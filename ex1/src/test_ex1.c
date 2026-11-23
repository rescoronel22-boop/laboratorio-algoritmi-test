#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hybrid_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"

static int total_tests = 0;
static int failed_tests = 0;

static int confronta_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

static void check_int_array(const char *test_name, const int *actual, const int *expected, size_t n) {
    total_tests++;
    for (size_t i = 0; i < n; i++) {
        if (actual[i] != expected[i]) {
            failed_tests++;
            printf("[FAIL] %s -> all'indice %zu atteso %d, ottenuto %d\n",
                   test_name, i, expected[i], actual[i]);
            return;
        }
    }
    printf("[OK]   %s -> ordinamento corretto\n", test_name);
}

static void test_null_array(void) {
    total_tests++;
    int *a = NULL;
    selection_sort(a, 0, sizeof(int), confronta_int);
    if (a == NULL) {
        printf("[OK]   test_null_array -> puntatore NULL gestito correttamente\n");
    } else {
        failed_tests++;
        printf("[FAIL] test_null_array -> atteso NULL, ottenuto puntatore non NULL\n");
    }
}

static void test_one_element(void) {
    int a[] = {42};
    int expected[] = {42};
    selection_sort(a, 1, sizeof(int), confronta_int);
    check_int_array("test_one_element", a, expected, 1);
}

static void test_unordered_array(void) {
    int a[] = {23, 1, 4, 3, 24, 12, 45, 56, 67, 59};
    int expected[] = {1, 3, 4, 12, 23, 24, 45, 56, 59, 67};
    selection_sort(a, 10, sizeof(int), confronta_int);
    check_int_array("test_unordered_array", a, expected, 10);
}

static void test_duplicates_and_negatives(void) {
    int a[] = {5, -2, 5, 0, -2, 3};
    int expected[] = {-2, -2, 0, 3, 5, 5};
    selection_sort(a, 6, sizeof(int), confronta_int);
    check_int_array("test_duplicates_and_negatives", a, expected, 6);
}

int main(void) {
    test_null_array();
    test_one_element();
    test_unordered_array();
    test_duplicates_and_negatives();

    printf("\nRiepilogo: %d/%d test superati (%d falliti)\n",
           total_tests - failed_tests, total_tests, failed_tests);
    return (failed_tests == 0) ? 0 : 1;
}


/* int main() {
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
}  */
