#include "util.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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

void *alloc_stack(size_t size) {
    void *addr = NULL;

#if defined(M_UNIX)

    addr = mmap(
        NULL,
        size,
        PROT_READ | PROT_WRITE,
        MAP_ANON,
        -1,
        0
    );

    if (addr == MAP_FAILED) return NULL;

    return addr;

#elif defined(M_WINDOWS)

#else
    assert(false && "unsupported architecture in alloc_stack");
#endif
}

void finalize_stack(void* ptr, size_t size) {
#if defined(M_UNIX)

    munmap(ptr, size);
    return;

#elif defined(M_WINDOWS)

#else
    assert(false && "unsupported architecture in finalize_stack");
#endif
}
