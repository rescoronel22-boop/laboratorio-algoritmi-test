#ifndef HYBRID_SORT_H
#define HYBRID_SORT_H

#include <stddef.h>

void hybridsort(void *base,
                size_t nitems,
                size_t size,
                size_t k,
                int (*compar)(const void *, const void *));

#endif