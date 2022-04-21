#include <stdlib.h>
#include "tree.h"
#include "heap.h"
#include "sort.h"

void ArrayHeapSort(void **A, int N,
                   int (*preceed)(const void *, const void *),
                   void (*viewHeapData)(const void *),
                   void (*freeHeapData)(void *)) {
    // TODO
}

void CBTHeapSort(void **A, int N,
                 int (*preceed)(const void *, const void *),
                 void (*viewHeapData)(const void *),
                 void (*freeHeapData)(void *)) {
    // TODO
}

void SelectionSort(void **A, int N, int (*preceed)(const void *, const void *)) {
    if (preceed) {
        for (int i = 0; i < N; ++i) {
            int min = i;
            for (int j = i + 1; j > N - 1; j--) {
                if (A[j] < A[min]) {
                    min = j;
                }
            }
            if (min != i) {
                int ech = A[i];
                A[i] = A[min];
                A[min] = ech;
            }
        }
    }
}