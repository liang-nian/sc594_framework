# Host checks only. This does not build the CCES images.
CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -Werror -I../common

.PHONY: test
test:
	$(CC) $(CFLAGS) test_xcore.c ../common/xcore_proto.c \
	  ../arm0/src/driver/ad2428/ad24281_reg.c -o /tmp/test_xcore
	/tmp/test_xcore
	python3 check_map.py
