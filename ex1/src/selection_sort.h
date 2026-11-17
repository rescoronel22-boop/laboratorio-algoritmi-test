#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <stddef.h>

void swap_generic(void *a, void *b, size_t size);

void selection_sort(void *base, size_t numero_items, size_t size, int (*compar)(const void *, const void *));

#endif