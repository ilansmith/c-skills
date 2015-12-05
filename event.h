#ifndef _EVENT_H_
#define _EVENT_H_

int event_add(void(*handler)(void *data), void *ctx);
int event_loop(void);

#endif

