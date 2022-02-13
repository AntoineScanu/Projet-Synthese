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
	struct List *L = newList(viewInt, freeInt);
	int *data1 = (int *)calloc(1, sizeof(int));
	*data1 = 1;
	int *data2 = (int *)calloc(1, sizeof(int));
	*data2 = 2;
	int *data3 = (int *)calloc(1, sizeof(int));
	*data3 = 3;

	listInsertLast(L, data1);
	viewHead(L);
	viewTail(L);
	viewList(L);

	listInsertFirst(L, data2);
	viewHead(L);
	viewTail(L);
	viewList(L);

	listInsertLast(L, data3);
	viewHead(L);
	viewTail(L);
	viewList(L);

	return EXIT_SUCCESS;
}