#include <stdio.h>
#include "selection_sort.h"

int confronta_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n = 10;
    int array[] = {23, 1, 4, 3, 24, 12, 45, 56, 67, 59};

    printf("Selection sorting:\n");

    printf("Unsorted list: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    selection_sort(array, n, sizeof(int), confronta_int);

    printf("\n\nSorted list: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}