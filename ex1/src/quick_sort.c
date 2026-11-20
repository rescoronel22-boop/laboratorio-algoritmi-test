#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "selection_sort.h"
#include "quick_sort.h"

//prototipo
static void quicksort_recursion(
    unsigned char *base,
    size_t elem_size,
    size_t low,
    size_t high,
    int (*cmp)(const void *, const void *));

size_t partition(void *base_ptr,
                 size_t elem_size,
                 size_t low,
                 size_t high,
                 int (*cmp)(const void *, const void *));

static unsigned char *elem_at(unsigned char *base, size_t idx, size_t elem_size) {
    return base + idx * elem_size;
}


//implementazione quicksort generico
void quicksort( void *base, size_t length, size_t elem_size, int (*cmp)(const void *, const void *)) {
    if (base == NULL || elem_size == 0 || length < 2) {
        return; // Array vuoto o con un solo elemento è già ordinato
    }
    quicksort_recursion((unsigned char *)base, elem_size, 0, length - 1, cmp);
}

static void quicksort_recursion(
    unsigned char *base,
    size_t elem_size,
    size_t low,
    size_t high,
    int (*cmp)(const void *, const void *)) {
    if (low >= high) {
        return;
    }

    size_t pivot_index = partition(base, elem_size, low, high, cmp);

    // Evita l'underflow se pivot_index == 0
    if (pivot_index > low) {
        quicksort_recursion(base, elem_size, low, pivot_index - 1, cmp);
    }
    if (pivot_index < high) {
        quicksort_recursion(base, elem_size, pivot_index + 1, high, cmp);
    }
}

size_t partition(void *base_ptr,
                 size_t elem_size,
                 size_t low,
                 size_t high,
                 int (*cmp)(const void *, const void *)) {
    unsigned char *base = (unsigned char *)base_ptr;
    unsigned char *pivot = elem_at(base, low, elem_size);
    size_t p = low;

    for (size_t k = low + 1; k <= high; k++) {
        unsigned char *curr = elem_at(base, k, elem_size);
        if (cmp(curr, pivot) <= 0) {
            p++;
            swap_generic(elem_at(base, p, elem_size), curr, elem_size);
        }
    }

    swap_generic(elem_at(base, low, elem_size), elem_at(base, p, elem_size), elem_size);
    return p;
}