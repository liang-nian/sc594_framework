#!/usr/bin/env python3
"""Match the ARM linker windows to common/xcore_abi.h."""

import pathlib
import re
import sys

root = pathlib.Path(__file__).resolve().parents[1]
ld = (root / "arm0/system/linker/app.ld").read_text()
abi = (root / "common/xcore_abi.h").read_text()
reserve = (root / "sharc1/system/startup_ldf/xcore_reserve.mem").read_text()


def define(name):
    match = re.search(r"#define\s+" + name + r"\s+\((0x[0-9A-Fa-f]+)u\)", abi)
    if match is None:
        raise SystemExit("missing " + name)
    return int(match.group(1), 16)


def memory(name):
    match = re.search(
        name + r"\s*:\s*ORIGIN\s*=\s*(0x[0-9A-Fa-f]+)\s*,\s*LENGTH\s*=\s*(0x[0-9A-Fa-f]+)",
        ld,
    )
    if match is None:
        raise SystemExit("linker region missing: " + name)
    return int(match.group(1), 16), int(match.group(2), 16)


ctrl = define("XCORE_CTRL_ADDR"), define("XCORE_CTRL_BYTES")
audio = define("XCORE_AUDIO_ADDR"), define("XCORE_AUDIO_BYTES")
ld_ctrl = memory("MEM_L2_XCORE_CTRL")
ld_audio = memory("MEM_L2_XCORE_AUDIO")
uncached = memory("MEM_L2_UNCACHED")

errors = []
if ctrl != ld_ctrl:
    errors.append("ctrl %s != linker %s" % (ctrl, ld_ctrl))
if audio != ld_audio:
    errors.append("audio %s != linker %s" % (audio, ld_audio))
if uncached[0] + uncached[1] != ctrl[0]:
    errors.append("uncached does not end at the control window")
if ctrl[0] + ctrl[1] != audio[0]:
    errors.append("control and audio windows are not adjacent")
if audio[0] + audio[1] != 0x20040000:
    errors.append("audio window does not end at cached L2")
if "MEM_L2_AUDIO_STAT" in ld:
    errors.append("old audio-stat region is still in the linker script")
if ".xcore_ctrl" not in ld or ".xcore_audio" not in ld:
    errors.append("NOLOAD sections missing")
if "0x20038000" not in reserve or "0x2003c000" not in reserve:
    errors.append("SHARC reserve fragment does not name both windows")
if "volatile" in abi and "flush_data_buffer" not in (root / "common/xcore_cache.c").read_text():
    errors.append("SHARC cache port missing")

if errors:
    print("\n".join(errors))
    sys.exit(1)
print("linker map matches xcore abi")
