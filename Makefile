CC=gcc
AR=ar
CFLAGS=-Wall -Werror -g
LIB=libevent
APP=factorial

LIBOBJS=event.o
APPOBJS=fact.o

%: %.c
	$(GCC) -o $@ $(CFLAGS) $<

.PHONY: all clean cleanall

all: $(APP)

$(LIB):$(LIBOBJS)
	$(AR) -r $@.a $^

$(APP): $(LIB) $(APPOBJS)
	$(CC) -o $@ $(APPOBJS) -L. -levent

clean:
	@echo "removing object files"
	@rm -f *.o

cleanlib:
	@echo "removing libraries"
	@rm -f *.a

cleanall: clean cleanlib
	@echo "removing tag file"
	@rm -f tags
	@echo "removing executables"
	@rm -f $(APP)

