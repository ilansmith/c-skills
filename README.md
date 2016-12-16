c-skills
========
You need to implement an efficient fifo queue using a buffer.

Implement the following API functions (declared in fifo.h):
```
o fifo fifo_init(unsigned int size);
o void fifo_uninit(fifo f);
o int fifo_push(fifo f, void *data);
o void *fifo_pop(fifo f);
```
Where fifo is defined as:
```
  #define  void *fifo;
```
After implementing, you can build and test your solution with provided
fifo_test.c and Makefile.

