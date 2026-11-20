#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <stddef.h>

void quick_sort(void *base, size_t numero_items, size_t size, int (*compar)(const void *, const void *));
size_t partition(void *base, size_t elem_size, size_t low, size_t high, int (*cmp)(const void *, const void *));

#endif