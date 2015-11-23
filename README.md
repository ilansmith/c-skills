c-skills
========
In this question you need to implement the function

    int bit_count_pairs(u32 word);

which recieves a single word and returns the number of bit pairs which are
adjacent to one another.

For example:
- bit_count_pairs(0x0) = 0;
- bit_count_pairs(0x1) = 0;
- bit_count_pairs(0x2) = 0;
- bit_count_pairs(0x3) = 1;
- bit_count_pairs(0x4) = 0;
- bit_count_pairs(0x5) = 0;
- bit_count_pairs(0x6) = 1;
- bit_count_pairs(0x7) = 2;
- bit_count_pairs(0x8) = 0;

You may use the function:

    int bit_count(u32 word);

which recieves a single word and returns its number of set bits.

The complexity of your solution should be O(1). You can assume language built-in
functions and the function bit_count() to have an O(1) complexity.

The working direcotry contains the following files:

- bit_pairs.c:      implementation of pairs_in_word.
                    YOU NEED TO FILL IT IN !!!
- bit_count.h:      decleration of bits/pairs in word functions.
- bit_test.o:       implemmentation of bit_count()
                    and test function for testing your code.
- Makefile:         a makefile for building your code and the bits_test
                    testing application.
                    To view the available targets issue: make help

