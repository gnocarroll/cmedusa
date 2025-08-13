#include "arena_alloc.h"

#include "constants.h"
#include "util.h"
#include <string.h>

Arena Arena_new(size_t capacity) {
    Arena ret;

    ret.top_addr = NULL;
    ret.curr_addr = NULL;
    ret.bottom_addr = NULL;

    ret.top_addr = alloc_stack();

    if (ret.top_addr) {
        ret.curr_addr = ret.top_addr;
        ret.bottom_addr = ret.top_addr - MAX_ARENA_SIZE;
    }

    return ret;
}

void Arena_finalize(Arena *arena) {
    finalize_stack(arena->top_addr);

    arena->top_addr = NULL;
    arena->curr_addr = NULL;
    arena->bottom_addr = NULL;
}

void *Arena_alloc(Arena* arena, size_t bytes) {
    arena->curr_addr -= bytes;
    arena->curr_addr = ROUND_PTR_DOWN_MULT_8(arena->curr_addr);

    return arena->curr_addr;
}

void *Arena_push(Arena* arena, void* src, size_t bytes) {
    void *ret = Arena_alloc(arena, bytes);

    memcpy(ret, src, bytes);

    return ret;
}