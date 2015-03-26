#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "random.h"

#define BYTE 8
#define C_NORMAL "\033[00;00;00m"
#define C_HIGHLIGHT "\033[01m"
#define VAL2IDX(_num_) ((_num_) - 1)
#define RANGE 100

typedef unsigned int u32;

static u32 generate_seed(void)
{
	u32 result;

#if defined(DEBUG)
	result = 1273961423;
#else
	int i, num_bits = sizeof(u32) * BYTE;
	u32 tm;

	if ((tm = (u32)time(NULL)) == -1) {
		printf("error: could not get time for seeding random "
			"function\n");
		return -1;
	}

	result = 0;
	srandom(tm);
	do {
		for (i = 0; i < num_bits; i++)
			result |= (random() & 0x0001) << i;
	} while (result == -1); /* -1 is an error return value */
#endif

	return result;
}

static void do_random(u32 seed)
{
	int sequence[RANGE]; /* output - a random sequence */
	int verification[RANGE];
	int i, no_duplicates = 1, is_random = 1;
	struct {
		int max_cnt; /* counts sequential elements */
		int num_sequences; /* counts number of sequential elements */
	} monitor = { 0, 0 };

	srandom(seed);

	/* initialize sequence array */
	for (i = 0; i < RANGE; i++) {
		verification[i] = 0;
		sequence[i] = i+1; /* numbers in: [1, RANGE] */
	}

	/* randomize the sequence */
	randomize_array(sequence, RANGE);

	/* print the random sequence and assert its correctness */
	for (i = 0; i < RANGE; i++) {
		printf("%.2d. %s%.2d%s", i, C_HIGHLIGHT, sequence[i], 
			C_NORMAL);

		verification[VAL2IDX(sequence[i])]++;
		if (verification[VAL2IDX(sequence[i])] > 1) {
			printf(" Error: %.2d occurrence #%d", sequence[i],
				verification[VAL2IDX(sequence[i])]);
			no_duplicates = 0;
		}

		if (i) {
			if (sequence[i] == sequence[i-1] + 1)
				monitor.max_cnt++;
			else
				monitor.max_cnt = 0;

			if (monitor.max_cnt == 4) {
				monitor.num_sequences++;
				monitor.max_cnt--;
			}

			if (monitor.num_sequences == 5) {
				printf(" Error: numbers are not randomly "
					"distributed");
				is_random = 0;
			}
		}
		printf("\n");
	}

	/* summarize: sequence is good or bad */
	printf("sequence is %s\n", no_duplicates && is_random ?
		"good" : "bad");
}

int randomize_range(int max)
{
	return ((int)random() % max) + 1;
}

int main(int argc, char *argv[])
{
	u32 seed;

	/* generate a random seed */
	if ((seed = generate_seed()) == -1)
		return -1;

	/* generate a random sequence and print it */
	do_random(seed);
	return 0;
}

