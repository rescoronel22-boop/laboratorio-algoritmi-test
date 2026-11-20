#include "selection_sort.h"
#include <string.h>

void swap_generic(void *a, void *b, size_t size) {
    unsigned char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

void selection_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {
    if (nitems <= 1 || base == NULL) {
        return;
    }
    //spostamento di un byte alla volta
    char *array = (char *)base;
    for (size_t i = 0; i < nitems - 1; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < nitems; j++) {
            //calcolo degli indirizzi
            void *elem_j = array + j * size;
            void *elem_min = array + min * size;

            if (compar(elem_j, elem_min) < 0) {
                min = j;
            }
        }
        if (min != i) {
            swap_generic(array + min * size, array + i * size, size);
        }
    }
}