#include <stdio.h>
#include <string.h>
#include "runtime.h"

int main(int argc, char **argv)
{
	char buffer[256];

	if (argc != 2) {
		printf("usage: ./naive <arg>\n");
		return -1;
	}

	assert_randomize_va_space();

	strcpy(buffer, argv[1]);
	printf("Got: %s\n", buffer);

	return 0;
}

