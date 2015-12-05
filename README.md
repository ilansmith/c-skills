c-skills
========
In this question you need to implement a few flavors of malloc and free.
The working direcotry contains the following files:

- my_malloc.c:      implementation of the different malloc/free functions -
                    YOU NEED TO FILL IT IN !!!
- my_malloc.h:      declaration of the different malloc/free functions
- libsys.a:         system library with the backing infrastructure you'll be
                    needing
- sys.h:            declaration of the system functions available to you in
                    libsys.a (API)
- sys_malloc.3:     manpage with a full description of the library functions
                    declared in sys.h. You can view it by issuing:
		    groff -man -Tascii sys_malloc.3 | less
- my_malloc_test.o: a pre-compiled test application object (main) for testing
                    your code
- Makefile:         a makefile for building your code and the my_malloc_test
                    testing application.
                    To view the available targets issue: make help

You must fill in the following functions in my_malloc.c:

1. simple malloc/free:
   - void *malloc_simple(unsigned int size);
   - void free_simple(void *ptr);
   These functions should imitate the standard malloc(3) and free(3) functions.
2. block aligned malloc/free:
   - void *malloc_block_aligned(unsigned int size);
   - void free_block_aligned(void *ptr);
   where sys_malloc() should be used to allocate 16 byte aligned blocks only.
3. address aligned malloc/free:
   - void *malloc_address_aligned(unsigned int size);
   - void free_address_aligned(void *ptr);
   where the pointers provided to the user are always 16 byte aligned.
4. size sensitive malloc/free:
   - void *malloc_size_sensitive(unsigned int size);
   - void free_size_sensitive(void *ptr);
   where sys_malloc_small/sys_free_small should be used to manage sizes of up to
   255 bytes and sys_malloc_large/sys_free_large should be used to manage sizes
   greater than 255 bytes.

All the functions you write should run at O(1) (consider libsys system calls as O(1) operations).

