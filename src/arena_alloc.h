#ifndef ARENA_ALLOC_H
#define ARENA_ALLOC_H

#include <stddef.h>
#include <stdio.h>

typedef struct {
    size_t capacity;
    size_t top;
    char *buffer;
} Arena;

Arena Arena_new(size_t capacity);

void *Arena_alloc(Arena* arena, size_t bytes);
void *Arena_push(Arena* arena, void* src, size_t bytes);

#define Arena_push_item(arena, item) \
    (Arena_push((arena), &(item), sizeof(item)))

typedef struct ArenaFreadData {
    void *ptr;
    size_t nitems;
} ArenaFreadData;

ArenaFreadData Arena_fread(
    Arena* arena,
    size_t size,
    size_t nitems,
    FILE* f
);

#endif // ARENA_ALLOC_H