"""把各核 Debug 里的链接产物复制到 output/<核>/，并把 map.xml 转成 map.html。

目录和工程一致，例如 output/arm0/、output/sharc1/。Debug 里的原文件保留。
ARM 映像在工程里没有后缀，复制后记为 output/arm0/arm0.dxe。
"""

import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent
OUTPUT = ROOT / "output"
CORES = ("arm0", "sharc1", "sharc2")
STYLESHEET = "System/linker_map_ss1.xsl"


def copy_products():
    copied = []
    for core in CORES:
        debug = ROOT / core / "Debug"
        if not debug.is_dir():
            print("跳过 %s，没有 Debug 目录" % core)
            continue
        dest_dir = OUTPUT / core
        dest_dir.mkdir(parents=True, exist_ok=True)
        arm_image = debug / "arm0"
        if arm_image.is_file():
            copied.append(shutil.copy2(arm_image, dest_dir / "arm0.dxe"))
        for pattern in ("*.dxe", "*.ldr", "*.map.xml", "*.map"):
            for src in debug.glob(pattern):
                if not src.is_file():
                    continue
                copied.append(shutil.copy2(src, dest_dir / src.name))
    return copied


def find_xmlmap2html(map_xml):
    found = shutil.which("xmlmap2html")
    if found:
        return Path(found)
    head = map_xml.read_text(encoding="utf-8", errors="replace")[:800]
    marker = "file:///"
    index = head.find(STYLESHEET)
    start = head.rfind(marker, 0, index) if index >= 0 else -1
    if start >= 0:
        cces_root = Path(head[start + len(marker):index])
        candidate = cces_root / "xmlmap2html.exe"
        if candidate.is_file():
            return candidate
    return None


def convert_maps():
    html_files = []
    maps = sorted(OUTPUT.glob("*/*.map.xml"))
    if not maps:
        print("output 里没有 map.xml")
        return html_files
    tool = find_xmlmap2html(maps[0])
    if tool is None:
        print("找不到 xmlmap2html。把 CCES 放到 PATH，或保留 map.xml 里的 stylesheet 路径。")
        sys.exit(1)
    for map_xml in maps:
        result = subprocess.run([str(tool), str(map_xml)], cwd=str(map_xml.parent))
        if result.returncode != 0:
            print("xmlmap2html 转换失败：%s" % map_xml.name)
            sys.exit(result.returncode)
        html = map_xml.with_suffix(".html")
        if not html.is_file():
            print("xmlmap2html 没有生成 %s" % html.name)
            sys.exit(1)
        html_files.append(html)
    return html_files


def main():
    copied = copy_products()
    for path in copied:
        print("复制 %s" % path.relative_to(OUTPUT).as_posix())
    if not copied:
        print("arm0、sharc1、sharc2 的 Debug 里没有 dxe、ldr 或 map")
        sys.exit(1)
    for path in convert_maps():
        print("生成 %s" % path.relative_to(OUTPUT).as_posix())


if __name__ == "__main__":
    main()
