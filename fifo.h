#ifndef _FIFO_H_
#define _FIFO_H_

#define FIFO_ERROR(fifo) (!(fifo))

typedef void *fifo;

fifo fifo_init(unsigned int size);
void fifo_uninit(fifo f);

int fifo_push(fifo f, void *data);
void *fifo_pop(fifo f);

#endif

