#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "util.h"

/********************************************************************
 * LNode
 ********************************************************************/

// Construction
LNode *newLNode(void *data)
{
	struct ListNode *L = (struct ListNode *)calloc(1, sizeof(struct ListNode));
	assert(data);
	L->data = data;
	return L;
}

// Consultation
void *getLNodeData(const LNode *node)
{
	return node->data;
}
LNode *Successor(const LNode *node)
{
	return node->succ;
}
LNode *Predecessor(const LNode *node)
{
	return node->pred;
}

// Modification
void setLNodeData(LNode *node, void *newData)
{
	node->data = newData;
}
void setSuccessor(LNode *node, LNode *newSucc)
{
	node->succ = newSucc;
}
void setPredecessor(LNode *node, LNode *newPred)
{
	node->pred = newPred;
}

/********************************************************************
 * List
 ********************************************************************/

// Construction
List *newList(void (*viewData)(const void *), void (*freeData)(void *))
{
	// TODO
}

int listIsEmpty(List *L)
{
	assert(L);
	if (L->numelm == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

// Consultation
int getListSize(const List *L)
{
	return L->numelm;
}
LNode *Head(const List *L)
{
	return L->head;
}
LNode *Tail(const List *L)
{
	return L->tail;
}

// Modification
void increaseListSize(List *L)
{
	L->numelm = L->numelm + 1;
}
void decreaseListSize(List *L)
{
	L->numelm = L->numelm - 1;
}
void setListSize(List *L, int newSize)
{
	L->numelm = newSize;
}
void resetListSize(List *L)
{
	L->numelm = 0;
}
void setHead(List *L, LNode *newHead)
{
	L->head = newHead;
}
void setTail(List *L, LNode *newTail)
{
	L->tail = newTail;
}

// Liberation
void freeList(List *L, int deleteData)
{
	assert(deleteData == 0 || deleteData == 1);
	// TODO
}

// Consultation
void viewList(const List *L)
{
	// TODO
}

// Modification
void listInsertFirst(List *L, void *data)
{
	// TODO
}
void listInsertLast(List *L, void *data)
{
	// TODO
}
void listInsertAfter(List *L, void *data, LNode *ptrelm)
{
	// TODO
}
void *listRemoveFirst(List *L)
{
	assert(Head(L));
	// TODO
}
void *listRemoveLast(List *L)
{
	assert(Head(L));
	// TODO
}
void *listRemoveNode(List *L, LNode *node)
{
	assert(Head(L) && Tail(L));
	// TODO
}
List *listConcatenate(List *L1, List *L2)
{
	// TODO
}