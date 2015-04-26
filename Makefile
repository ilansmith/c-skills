CC=gcc
CPP=cpp
AR=ar
CFLAGS=-ansi -pedantic-errors -Werror -Wall
APP=timers_test

OBJS=timers.o timers_test.o

all: $(APP)

help:
	@echo "\033[1mbuild $(APP) - timers assignment implementations\033[0m"
	@echo "targets:"
	@echo "  \033[1m[all]\033[0m:    build \033[1m$(APP)\033[0m"
	@echo "            command line options:"
	@echo "              \033[1mDEBUG=y\033[0m: build debug version"
	@echo "  \033[1mclean\033[0m:    remove all object files"
	@echo "  \033[1mcleanall\033[0m: do \033[1mclean\033[0m, remove tags file and \033[1m$(APP)\033[0m"

ifeq ($(DEBUG),y)
  CFLAGS+=-g
endif

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c $<

$(APP): $(OBJS)
	$(CC) -o $@ $^ -L. -lsys

clean:
	@echo "removing object files"
	@ls *.o | grep -v $(APP) | xargs rm -f

cleanall: clean
	@echo "removing tag file"
	@rm -rf tags
	@echo "removing $(APP)"
	@rm -f $(APP)

