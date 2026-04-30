#ifndef MEMORY_H
#define MEMORY_H

typedef unsigned int uint32_t;
typedef unsigned int size_t;

void init_kernel_memory(uint32_t* kernel_end);
void* malloc(size_t size);
void free(void* ptr);
void print_memory_layout(void);

#endif