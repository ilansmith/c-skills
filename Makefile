CC=gcc
CFLAGS=-Wall -Werror -O0 -m64
LDFLAGS=-lm
APP=fifo_test

OBJS=fifo.o fifo_test.o

# configuration
# =============
CONFIG_DEBUG=y

ifeq ($(CONFIG_DEBUG),y)
    CFLAGS+=-ggdb
endif

%: %.c
	$(GCC) -o $@ $(CFLAGS) -c $<

%_pre.c: %.c
	$(CPP) -x c -o $@ $<

.PHONY: all clean cleanall

all: $(APP)

$(APP): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

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

