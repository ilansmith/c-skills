#include "my_malloc.h"

/* allocate dynamic memory
   size - amount of memory (in bytes) required by user
   return: if successful pointer to allocated memory, otherwise NULL
 */
void *malloc_simple(u32 size)
{
	/* fill in and replace */
	return (void*)0x0;
}

/* free dynamically allocated memory
   ptr - pointer to dynamically allocated memory
 */
void free_simple(void *ptr)
{
	/* fill in */
}

/* allocate dynamic memory in pow(2, ALIGNMENT) byte aligned blocks
   size - amount of memory (in bytes) required by user
   return: if successful pointer to allocated memory, otherwise NULL
 */
void *malloc_block_aligned(u32 size)
{
	/* fill in and replace */
	return (void*)0x0;
}

/* free dynamically allocated memory allocated in pow(2, ALIGNMENT) byte 
   aligned blocks
   ptr - pointer to dynamically allocated memory
 */
void free_block_aligned(void *ptr)
{
	/* fill in */
}

/* allocate dynamic memory at a pow(2, ALIGNMENT) aligned address
   size - amount of memory (in bytes) required by user
   return: if successful pointer to allocated memory, otherwise NULL
 */
void *malloc_address_aligned(u32 size)
{
	/* fill in and replace */
	return (void*)0x0;
}

/* free dynamically allocated memory from a pow(2, ALIGNMENT) aligned address
   ptr - pointer to dynamically allocated memory
 */
void free_address_aligned(void *ptr)
{
	/* fill in */
}

/* allocate dynamic memory, uses different system calls depending on allocation
   size
   size - amount of memory (in bytes) required by user
   return: if successful pointer to allocated memory, otherwise NULL
 */
void *malloc_size_sensitive(u32 size)
{
	/* fill in and replace */
	return (void*)0x0;
}

/* free memory dynamically, uses different system calls depending on allocated
   size
   ptr - pointer to dynamically allocated memory
 */
void free_size_sensitive(void *ptr)
{
	/* fill in */
}

