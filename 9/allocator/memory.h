#ifndef MEMORY_H
#define MEMORY_H
/* Provide for usres */
#include <stddef.h>

extern int mm_init(void);
extern void* mm_malloc(size_t size);
extern void mm_free(void* ptr);

#endif