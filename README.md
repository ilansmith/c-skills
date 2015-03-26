c-skills
========
Implement the function

  void randomize_array(int *array, int size);

in random.c, which receives a sorted 'array' of size 'size' with values:

  array[0]      = 1
  array[1]      = 2
  ...
  array[size-1] = size

You must randomize the values within the array in a uniform distribution.
You may use the function

  int randomize_range(int max);

declared in random.h which receives an integer value and returns a random
value within the range [1, max].

