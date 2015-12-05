CC=gcc
CFLAGS=-Wall -Werror
APP=dots

OBJS=dots.o

ifeq ($(CONFIG_DEBUG),y)
    CFLAGS+=-g -O0
endif

%: %.c
	$(GCC) -o $@ $(CFLAGS) $<

%_pre.c: %.c
	$(CPP) -x c -o $@ $<

.PHONY: all clean cleanall

all: $(APP)

$(APP): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	@echo "removing executables"
	@rm -f $(APP)
	@echo "removing object files"
	@rm -f *.o

cleanall: clean
	@echo "removing pre compilation files"
	@rm -f *_pre.c
	@echo "removing tag file"
	@rm -f tags

