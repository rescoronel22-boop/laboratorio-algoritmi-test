#include <stddef.h>
#include "hybrid_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"


static unsigned char *elem_ptr(unsigned char *base, size_t idx, size_t size) {
    return base + idx * size;
}

static void hybridsort_rec(unsigned char *base,
                           size_t size,
                           size_t low,
                           size_t high,
                           size_t k,
                           int (*compar)(const void *, const void *)) {
    if (low >= high) {
        return;
    }

    size_t count = high - low + 1;

    // Sotto la soglia k (o con meno di 2 elementi), delega a selection_sort
    if (count < k || count < 2) {
        selection_sort(elem_ptr(base, low, size), count, size, compar);
        return;
    }

    // Altrimenti partiziona e prosegue ricorsivamente rispettando k
    size_t pivot_index = partition(base, size, low, high, compar);

    if (pivot_index > low) {
        hybridsort_rec(base, size, low, pivot_index - 1, k, compar);
    }
    if (pivot_index < high) {
        hybridsort_rec(base, size, pivot_index + 1, high, k, compar);
    }
}

void hybridsort(void *base,
                size_t nitems,
                size_t size,
                size_t k,
                int (*compar)(const void *, const void *)) {
    if (base == NULL || size == 0 || nitems < 2 || compar == NULL) {
        return;
    }

    // Se k <= 1, nessun sotto-array con >= 2 elementi ha dimensione < k
    size_t effective_k = (k <= 1) ? 2 : k;

    hybridsort_rec((unsigned char *)base, size, 0, nitems - 1, effective_k, compar);
}