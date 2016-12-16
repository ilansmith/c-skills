#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "fifo.h"

#define COL_GREEN "\033[01;32m"
#define COL_RED "\033[01;31m"
#define COL_WHITE "\033[01;37m"
#define COL_CLEAR "\033[00;00;00m"

static int digits;
static char fmt[64];

static void print_init(int size)
{
	if (digits)
		return;

	digits = (int)log10(size) + 1;
	snprintf(fmt, sizeof(fmt), "%%.%dd %%s%%s%%s: %%s%%d%%s\n", digits);
}

static void print_action(int count, int val, int action)
{
	char *publish[2][2] = {
		{ "pushed", COL_GREEN },
		{ "popped", COL_RED },
	};

	printf(fmt, count, publish[action][1], publish[action][0], COL_CLEAR,
		COL_WHITE, val, COL_CLEAR);
}

static void print_pushed(int count, int val)
{
	print_action(count, val, 0);
}

static void print_popped(int count, int val)
{
	print_action(count, val, 1);
}

static int run_test(int size, int count_action_1, int count_action_2)
{
	fifo f;
	int *buf, i, j, k, ret = 0;
	int count_push, count_pop;
	int count = 0, phase = 0;

	buf = (int*)malloc(size * sizeof(int));
	if (!buf)
		return -1;

	for (i = 0; i < size; i++)
		buf[i] = i+1;

	f = fifo_init(size);
	if (FIFO_ERROR(f)) {
		printf("Error: couldn't allocate a fifo of size: %u\n", size);
		ret = -1;
		goto Exit;
	}

	print_init(size);

	count_push = count_action_1;
	count_pop = count_action_2;
	i = j = 0;
	while (1) {
		for (k = 0; k < count_push; k++) {
			int idx = (i+k) % size;

			if (fifo_push(f, &buf[idx])) {
				if (!phase && count == size) {
					printf("Couldn't push value: %d "
						"(fifo is full)\n", buf[idx]);
					count_push = count_action_2;
					count_pop = count_action_1;
					phase = 1;
					break;
				} else {
					printf("Error: couldn't push value: "
						"%d\n", buf[idx]);
					ret = -1;
					goto Exit;
				}
			}
			print_pushed(++count, buf[idx]);
		}

		for (k = 0; k < count_pop; k++) {
			int *val;

			if (!(val = fifo_pop(f))) {
				if (!phase || count) {
					printf("Error: Couldn't pop: j=%d, "
						"k=%d\n", j, k);
					ret = -1;
					goto Exit;
				} else {
					goto Exit;
				}
			}
			print_popped(--count, *val);
		}

		i = i + count_push % size;
		j = j + count_pop % size;
	}

Exit:
	free(buf);
	fifo_uninit(f);
	return ret;
}

int main (int argc, char **argv)
{
	return run_test(53, 5, 3);
}

