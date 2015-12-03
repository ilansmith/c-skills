#include <stdlib.h>

#define BRC_OPEN(sym) ((sym) == '(' || (sym) == '[' || (sym) == '{')
#define MATCH_CLOSE(sym) ((sym) == ')' ? '(' : (sym) == ']' ? \
	'[' : (sym) == '}' ? '{' : 0)

#define CONTAINER_OF(_type_, _field_, _addr_) \
	(_type_*)((char*)_addr_ - (unsigned long)&(((_type_*)0x0)->_field_))

struct bracket {
	struct bracket *next;
	struct bracket **prev;
	char brc;
};

/**
 * check_brackets - checks that brackets are correctly nested
 * @array: a sorted array of integers
 * @size: the size of the array
 *
 * Test that brackets of the form (), [], {} are correctly nested within 'text'
 *
 *      Suggested solution:
 *
 *      If, for example, the string prefix contains: "...{...[...",
 *      then the following data structure is constructed:
 *
 *                                                           cur o
 *                                                               |
 *                    +------------------+      +----------------|-+
 *                    |                  |      |                v |
 *      list o------->| o prev    next o------->| o prev    next o------->NULL
 *           ^        | |              ^ |      | |                |
 *           |        | |              | |      | |                |
 *           +----------+              +----------+                |
 *                    |   brc = '{'      |      |   brc = '['      |
 *                    +------------------+      +------------------+
 *
 *
 *      If the first closing bracket found in the string suffix is ']'
 *      then the 2nd link will be folded, yealding:
 *
 *
 *                                 cur o        | Accounted for --->
 *                                     |
 *                    +----------------|-+      +------------------+
 *                    |                v |      |                  |
 *      list o------->| o prev    next o------->| o prev    next o------->NULL
 *           ^        | |              ^ |      | |                |
 *           |        | |              | |      | |                |
 *           +----------+              +----------+                |
 *                    |   brc = '{'      |      |   brc = '['      |
 *                    +------------------+      +------------------+
 *
 *
 *      If the second closing bracket found in the string suffix is ']'
 *      then the 1st link will be folded, yealding:
 *
 *
 *       cur o        | Accounted for --->
 *           |
 *           |        +------------------+      +------------------+
 *           v        |                  |      |                  |
 *      list o------->| o prev    next o------->| o prev    next o------->NULL
 *           ^        | |              ^ |      | |                |
 *           |        | |              | |      | |                |
 *           +----------+              +----------+                |
 *                    |   brc = '{'      |      |   brc = '['      |
 *                    +------------------+      +------------------+
 *
 *      The string is correct if and only if at the end of processing the string
 *      characters cur is pointing to list and no excess closing brackets are
 *      found.
 *      All nodes are freed when all the characters of text have been processed.
 *
 *
 * returns
 *  0: if brackets are nested correctly
 * -1: otherwise
 */
int check_brackets(char *text)
{
	struct bracket *list = NULL, **cur = &list;
	int ret = -1;

	for ( ; *text; text++) {
		char brc;

		if (BRC_OPEN(*text)) {
			if (!*cur && !(*cur = (struct bracket*)
					calloc(1, sizeof(struct bracket)))) {
				goto Exit;
			}
			(*cur)->brc = *text;
			(*cur)->prev = cur;
			cur = &(*cur)->next;
		} else if ((brc = MATCH_CLOSE(*text))) {
			if (cur == &list || brc != ((struct bracket*)cur)->brc)
				goto Exit;
			cur = ((struct bracket*)cur)->prev;
		}
	}
	ret = cur == &list ? 0 : -1;
Exit:
	while (list) {
		cur = &list->next;
		list = list->next;

		free(CONTAINER_OF(struct bracket, next, cur));
	}
	return ret;
}

