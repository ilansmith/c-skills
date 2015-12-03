#include <stdlib.h>
#include <stdio.h>
#include "brackets.h"

int main(int argc, char **argv)
{
	struct {
		char *str;
		int val;
	} *t, tests[] = {
		{ "a(b)", 0 },
		{ "[{}]", 0 },
		{ "[(]", -1 },
		{ "}{", -1 },
		{ "z([{}-()]{a})", 0 },
		{ "[{}a ] b", 0 },
		{ "", 0 }, 
		{ NULL }
	};

	for (t = tests; t->str; t++) {
		int val = check_brackets(t->str);

		printf("check_brackets(\"%s\") -> %s (%s)\n", t->str,
			val ? "false" : "true",
			val == t->val ? "CORRECT": "WRONG");
	}

	return 0;
}

