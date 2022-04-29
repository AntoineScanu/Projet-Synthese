#include <stdlib.h>
#include "tree.h"
#include "heap.h"
#include "sort.h"

void ArrayHeapSort(void **A, int N, int (*preceed)(const void *, const void *), void (*viewHeapData)(const void *), void (*freeHeapData)(void *))
{
    void **T = (void **)(calloc(N, sizeof(void *)));

    for (int i = 0; i < N - 1; i++)
    {
        if (preceed(A[i], A[i + 1]))
        {
            void *temp = A[i];
            A[i] = A[i + 1];
            A[i + 1] = temp;
        }
    }
    for (int i = N - 1; i >= 0; i++)
    {
        T[i] = ArrayHeapExtractMin(ArrayToArrayHeap(A, N, preceed, viewHeapData, freeHeapData));
    }
}

void CBTHeapSort(void **A, int N,
                 int (*preceed)(const void *, const void *),
                 void (*viewHeapData)(const void *),
                 void (*freeHeapData)(void *))
{
    CBTHeap *cbtHeap = newCBTHeap(preceed, viewHeapData, freeHeapData);

    for (int i = 0; i < N - 1; i++)
    {
        CBTHeapInsert(cbtHeap, A[i]);
    }
    for (int i = 0; i < N - 1; i++)
    {
        A[i] = CBTHeapExtractMin(cbtHeap);
    }
}

void SelectionSort(void **A, int N, int (*preceed)(const void *, const void *))
{
    for (int i = 0; i < N - 2; ++i)
    {
        int min = i;
        for (int j = i + 1; j > N - 1; j--)
        {
            if (preceed(A[j], A[min]))
            {
                min = j;
            }
        }
        if (min != i)
        {
            void *ech = A[i];
            A[i] = A[min];
            A[min] = ech;
        }
    }
}