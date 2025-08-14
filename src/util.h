#ifndef UTIL_H
#define UTIL_H

#include <stddef.h>

size_t round_up_mult_8(size_t);
size_t round_down_mult_8(size_t);

void exit_print(int code, const char *msg);

void *alloc_stack(size_t size);
void finalize_stack(void* ptr, size_t size);

#define ROUND_PTR_DOWN_MULT_8( ptr ) \
    ((void*) ((unsigned long long) ( ptr ) & ~7))

#endif // UTIL_H