#include "arena_alloc.h"

#include <assert.h>
#include <string.h>

#include "util.h"

Arena Arena_new(size_t capacity) {
    Arena ret;

    ret.buffer = NULL;
    ret.top = 0;
    ret.capacity = 0;

    ret.buffer = alloc_stack(capacity);

    if (ret.buffer) {
        ret.capacity = capacity;
    }

    return ret;
}

void Arena_finalize(Arena *arena) {
    finalize_stack(arena->buffer, arena->capacity);

    arena->buffer = NULL;
    arena->capacity = 0;
    arena->top = 0;
}

void *Arena_alloc(Arena* arena, size_t bytes) {
    arena->top = round_up_mult_8(arena->top);

    assert(
        arena->top < arena->capacity &&
        arena->top + bytes <= arena->capacity &&
        "Arena_alloc: CRITICAL FAILURE, ARENA MEMORY EXHAUSTED"
    );

    void *ret = (char*) arena->buffer + arena->top;

    arena->top += bytes;

    return ret;
}

void *Arena_push(Arena* arena, void* src, size_t bytes) {
    void *ret = Arena_alloc(arena, bytes);

    memcpy(ret, src, bytes);

    return ret;
}

ArenaFreadData Arena_fread(
    Arena* arena,
    size_t size,
    size_t nitems,
    FILE* f
) {
    arena->top = round_up_mult_8(arena->top);

    ArenaFreadData ret;

    ret.ptr = (char*) arena->buffer + arena->top;

    unsigned long nitems_read = fread(
        ret.ptr,
        size,
        nitems,
        f
    );

    ret.nitems = nitems_read;

    arena->top += nitems_read * size;

    return ret;
}
