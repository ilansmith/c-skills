#ifndef _SYS_H_
#define _SYS_H_

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

/* allocate memory
   input parameters:
   - size: number of bytes to allocate.
   reutrn: pointer to allocated memory, 0x0 if unsuccessful.
 */
void *sys_malloc(u32 size);

/* free allocated memory
   input parameters:
   - ptr: a pointer to the allocated memory.
   - size: number of bytes to allocated at 'ptr'.
 */
void sys_free(void *ptr, u32 size);

/* allocate memory up to 255 bytes
   input parameters:
   - size: number of bytes to allocate.
   reutrn: pointer to allocated memory, 0x0 if unsuccessful.
 */
void *sys_malloc_small(u32 size);

/* free allocated memory for allocations of up to 255 bytes
   input parameters:
   - ptr: a pointer to the allocated memory.
   - size: number of bytes to allocated at 'ptr'.
 */
void sys_free_small(void *ptr, u32 size);

/* allocate memory larger than 255 bytes
   input parameters:
   - size: number of bytes to allocate.
   reutrn: pointer to allocated memory, 0x0 if unsuccessful.
 */
void *sys_malloc_large(u32 size);

/* free allocated memory for allocations greater than 255 bytes
   input parameters:
   - ptr: a pointer to the allocated memory.
   - size: number of bytes to allocated at 'ptr'.
 */
void sys_free_large(void *ptr, u32 size);
#endif

