#include <stdio.h>
#include <stdlib.h>
#include <string.h> //memcpy

void hybridsort(void *base,
                size_t nitems,
                size_t size,
                size_t k,
                int (*compar)(const void *, const void *));
