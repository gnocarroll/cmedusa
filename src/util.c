#include "util.h"

#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "macros.h"

#if defined(M_UNIX)
#include <sys/mman.h>
#elif defined(M_WINDOWS)

#endif

size_t round_up_mult_8(size_t old) {
    return (old + 7) & ~7;
}
size_t round_down_mult_8(size_t old) {
    return old & ~7;
}

size_t round_up_mult_pow_2(size_t old, size_t pow_2) {
    return (old + pow_2 - 1) & ~(pow_2 - 1);
}

void exit_print(int code, const char *msg) {
    fprintf(stderr, "%s", msg);
    exit(code);
}

void *alloc_stack() {
#if defined(M_UNIX)

    void *addr = mmap(
        NULL,
        MAX_ARENA_SIZE,
        PROT_READ | PROT_WRITE,
        MAP_ANON,
        -1,
        0
    );

    if (addr == MAP_FAILED) return NULL;

    return addr;

#elif defined(M_WINDOWS)

#else

#endif
}

void finalize_stack(void *addr) {
#if defined(M_UNIX)

    munmap((char*) addr, MAX_ARENA_SIZE);

#elif defined(M_WINDOWS)

#else

#endif
}
