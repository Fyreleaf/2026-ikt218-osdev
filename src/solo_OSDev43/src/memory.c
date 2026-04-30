#include "memory.h"

void terminal_write(const char* str);

static uint32_t heap_start = 0;
static uint32_t heap_current = 0;
static uint32_t heap_end = 0x01000000; // 16 MB

void init_kernel_memory(uint32_t* kernel_end) {
    heap_start = (uint32_t)kernel_end;
    heap_current = heap_start;
}

void* malloc(size_t size) {
    if (size == 0) {
        return 0;
    }

    if (size % 4 != 0) {
        size += 4 - (size % 4);
    }

    if (heap_current + size >= heap_end) {
        return 0;
    }

    void* allocated = (void*)heap_current;
    heap_current += size;
    return allocated;
}

void free(void* ptr) {
    (void)ptr;
    // Simple bump allocator: memory is not reused yet.
}

void print_memory_layout(void) {
    terminal_write("Kernel memory initialized\n");
    terminal_write("Heap starts after kernel end\n");
}