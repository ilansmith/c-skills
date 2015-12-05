CC=gcc
CFLAGS=-ansi -Werror -Wall -pedantic-errors
APP=brackets

OBJS=test.o brackets.o

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c $<


.PHONY: all clean cleanall

all: $(APP)

$(APP): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	@echo "removing object files"
	@rm -f *.o

cleanall: clean
	@echo "removing tag file"
	@rm -f tags
	@echo "removing $(APP)"
	@rm -f $(APP)

