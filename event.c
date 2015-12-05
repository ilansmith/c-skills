#include <stdlib.h>
#include "event.h"

struct event {
    struct event *next;
    void(*handler)(void *data);
    void *ctx;
};

static struct event *event_queue;

int event_add(void(*handler)(void *data), void *ctx)
{
	static struct event **event_queue_tail;

	if (!event_queue_tail)
		event_queue_tail = &event_queue;

	if (!((*event_queue_tail) = calloc(1, sizeof(struct event))))
		return -1;

	(*event_queue_tail)->handler = handler;
	(*event_queue_tail)->ctx = ctx;
	event_queue_tail = &((*event_queue_tail)->next);

	return 0;
}

int event_loop(void)
{
	while (event_queue) {
		struct event *cur;

		event_queue->handler(event_queue->ctx);
		cur = event_queue;
		event_queue = event_queue->next;
		free(cur);
	}

	return 0;
}

