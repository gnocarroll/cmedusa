#ifndef ARENA_ALLOC_H
#define ARENA_ALLOC_H

#include "stddef.h"

typedef struct {
    char *top_addr;
    char *curr_addr;
    char *bottom_addr;
} Arena;

Arena Arena_new(size_t capacity);

void *Arena_alloc(Arena* arena, size_t bytes);
void *Arena_push(Arena* arena, void* src, size_t bytes);

#define Arena_push_item(arena, item) \
    (Arena_push((arena), &(item), sizeof(item)))

#endif // ARENA_ALLOC_H