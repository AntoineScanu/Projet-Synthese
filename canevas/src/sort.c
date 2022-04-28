#include <stdlib.h>
#include "tree.h"
#include "heap.h"
#include "sort.h"

void ArrayHeapSort(void **A, int N,int (*preceed)(const void *, const void *),void (*viewHeapData)(const void *),void (*freeHeapData)(void *))
{
    // TODO
}

void CBTHeapSort(void **A, int N,
                 int (*preceed)(const void *, const void *),
                 void (*viewHeapData)(const void *),
                 void (*freeHeapData)(void *))
{
    for (int i = 0; i < N - 1; i++)
    {
        A[i] =
    }
    for (int i = 0; i < N - 1; i++)
    {
        A[i] =
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
            int ech = A[i];
            A[i] = A[min];
            A[min] = ech;
        }
    }
}