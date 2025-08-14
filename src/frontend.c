#include "frontend.h"

#include <assert.h>

#include "arena_alloc.h"
#include "constants.h"

void build_ast(FILE* input) {
    Arena arena = Arena_new(MAX_ARENA_SIZE);

    assert(arena.buffer && "creation of arena failed");

    Arena_fread(&arena, 1, MAX_ARENA_SIZE, input);
}
