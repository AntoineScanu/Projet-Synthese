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

	// int ptr4 = 4;
	// void *data4 = &ptr4;

	listInsertLast(L1, data1);
	listInsertLast(L1, data2);
	listInsertLast(L1, data3);
	viewAll(L1);

	listInsertLast(L2, data4);
	listInsertLast(L2, data5);
	listInsertLast(L2, data6);
	viewAll(L2);

	viewAll(listConcatenate(L1, L2));

	return EXIT_SUCCESS;
}