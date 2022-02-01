#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "util.h"

/********************************************************************
 * LNode
 ********************************************************************/

// Construction 
LNode * newLNode(void* data) {
	// TODO
}

// Consultation
void* getLNodeData(const LNode* node) {
	// TODO
}
LNode* Successor(const LNode* node) {
	// TODO
}
LNode* Predecessor(const LNode* node) {
	// TODO
}

// Modification
void setLNodeData(LNode* node, void* newData) {
	// TODO
}
void setSuccessor(LNode* node, LNode* newSucc) {
	// TODO
}
void setPredecessor(LNode* node, LNode* newPred) {
	// TODO
}

/********************************************************************
 * List
 ********************************************************************/

// Construction
List * newList(void (*viewData)(const void*), void (*freeData)(void*)) {
	// TODO
}


int listIsEmpty(List* L) {
	assert(L);
	if (L->numelm ==0){
		return 0;
	}
	else{
		return 1;
	}
}

// Consultation
int getListSize(const List* L) {
	return L->numelm;
}
LNode* Head(const List* L) {
	// TODO
}
LNode* Tail(const List* L) {
	// TODO
}

// Modification
void increaseListSize(List* L) {
	// TODO
}
void decreaseListSize(List* L) {
	// TODO
}
void setListSize(List* L, int newSize) {
	// TODO
}
void resetListSize(List* L) {
	// TODO
}
void setHead(List* L, LNode* newHead) {
	// TODO
}
void setTail(List* L, LNode* newTail) {
	// TODO
}

// Liberation
void freeList(List * L, int deleteData) {
	assert(deleteData == 0 || deleteData == 1);
	// TODO
}

// Consultation
void viewList(const List * L) {
	// TODO
}

// Modification
void listInsertFirst(List * L, void * data) {
	// TODO
}
void listInsertLast(List * L, void * data) {
	// TODO
}
void listInsertAfter(List * L, void * data, LNode * ptrelm) {
	// TODO
}
void* listRemoveFirst(List * L) {
	assert(Head(L));
	// TODO
}
void* listRemoveLast(List * L) {
	assert(Head(L));
	// TODO
}
void* listRemoveNode(List * L, LNode * node) {
	assert(Head(L) && Tail(L));
	// TODO
}
List* listConcatenate(List* L1, List* L2) {
	// TODO
}