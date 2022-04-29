#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "list.h"
#include "tree.h"
#include "heap.h"
#include "sort.h"
#include "geometry.h"
#include "algo.h"

int main()
{

    List *L1 = newList(viewInt, freeInt);
    List *L2 = newList(viewInt, freeInt);

    int ptr1 = 1;
    void *data1 = &ptr1;

    int ptr2 = 2;
    void *data2 = &ptr2;

    int ptr3 = 3;
    void *data3 = &ptr3;

    int ptr4 = 4;
    void *data4 = &ptr4;

    int ptr5 = 5;
    void *data5 = &ptr5;

    int ptr6 = 6;
    void *data6 = &ptr6;

    listInsertFirst(L1, data1);
    listInsertFirst(L1, data2);
    listInsertFirst(L1, data3);

    listInsertLast(L2, data4);
    listInsertLast(L2, data5);
    listInsertLast(L2, data6);

    viewAll(L1);
    viewAll(L2);

    listRemoveFirst(L1);
    listRemoveLast(L2);

    viewAll(L1);
    viewAll(L2);

    List *L3 = listConcatenate(L1, L2);

    viewAll(L3);

    return EXIT_SUCCESS;
}