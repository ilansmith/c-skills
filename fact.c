#include <stdlib.h>
#include <stdio.h>
#include "event.h"

#define ARG 8

#define FACT_T(o) ((struct factorial*)o)

struct factorial {
	int r;
	void(*func)(void *data);
	void *o;
};

static struct factorial *factorial_alloc(int r, void(*func)(void *data),
	void *o)
{
	struct factorial *obj;

	if (!(obj = (struct factorial*)calloc(1, sizeof(struct factorial))))
		return NULL;

	obj->r = r;
	obj->func = func;
	obj->o = o;
	return obj;
}

static void factorial_free(struct factorial *o)
{
	free(o);
}

static void fact_id(void *data)
{
	*(int*)FACT_T(data)->o = FACT_T(data)->r;
	factorial_free(FACT_T(data));
}

static void fact_cps(void *data)
{
	/* ... */
}

/*
 *             1           if n=0
 *   fact(n) =
 *             n*fact(n-1) if 0<n
 */
int main(int argc, char *argv[])
{
	int result = -1;

	event_add(fact_cps, factorial_alloc(ARG, fact_id, &result));
	event_loop();

	printf("fact(%i) = %i\n", ARG, result);
	return 0;
}

