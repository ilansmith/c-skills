#ifndef _BRACES_H_
#define _BRACES_H_

/**
 *	check_brackets - checks that brackets are correctly nested
 *	@array: a sorted array of integers
 *	@size: the size of the array
 *
 *	Test that brackets of the form (), [], {} are correctly nested within
 *	'text'
 *
 *	returns
 *	 0: if brackets are nested correctly
 *	-1: otherwise
 *
 *	-2: temporary return value while function is not implemented
 */
int check_brackets(char *text);

#endif

