#ifndef _RANDOM_H_
#define _RANDOM_H_

/**
 *	randomize_range - return a random value within a range
 *	@max: the maximum value that can be returned
 *
 *	The value returned is within the range [1, max].
 */
int randomize_range(int max);

/**
 *	randomize_array - randomize the values in an array
 *	@array: a sorted array of integers
 *	@size: the size of the array
 *
 *	The values are initialized in the array from 1 to size.
 */
void randomize_array(int *array, int size);

#endif

