#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "util.h"

/********************************************************************
 * LNode
 ********************************************************************/

void viewSuccessor(const LNode *node);

void viewPredecessor(const LNode *node);

// Construction

LNode *newLNode(void *data) {
    LNode *L = (LNode *) calloc(1, sizeof(LNode));
    assert(data);
    L->data = data;
    return L;
}

// Consultation

void *getLNodeData(const LNode *node) {
    return node->data;
}

LNode *Successor(const LNode *node) {
    return node->succ;
}

LNode *Predecessor(const LNode *node) {
    return node->pred;
}

// Modification

void setLNodeData(LNode *node, void *newData) {
    node->data = newData;
}

void setSuccessor(LNode *node, LNode *newSucc) {
    node->succ = newSucc;
}

void setPredecessor(LNode *node, LNode *newPred) {
    node->pred = newPred;
}

/********************************************************************
 * List
 ********************************************************************/

// Construction

List *newList(void (*viewData)(const void *), void (*freeData)(void *)) {
    List *L = (List *) calloc(1, sizeof(List));
    assert(L);
    L->viewData = viewData;
    L->freeData = freeData;
    return L;
}

int listIsEmpty(List *L) {
    assert(L);
    if (L->numelm == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Consultation

int getListSize(const List *L) {
    return L->numelm;
}

LNode *Head(const List *L) {
    return L->head;
}

LNode *Tail(const List *L) {
    return L->tail;
}

// Modification

void increaseListSize(List *L) {
    L->numelm++;
}

void decreaseListSize(List *L) {
    L->numelm--;
}

void setListSize(List *L, int newSize) {
    L->numelm = newSize;
}

void resetListSize(List *L) {
    L->numelm = 0;
}

void setHead(List *L, LNode *newHead) {
    L->head = newHead;
}

void setTail(List *L, LNode *newTail) {
    L->tail = newTail;
}

// Liberation

void freeNode(LNode *ptrE) {
    assert(ptrE);
    free(ptrE);
    ptrE = NULL;
}

void freeList(List *L, int deleteData) {
    assert(deleteData == 0 || deleteData == 1);
    assert(L != NULL);

    if (deleteData == 1) {
        for (LNode *E = Head(L); E; E = Successor(E)) {
            LNode *T = E;
            L->freeData(T->data);
            freeNode(T);
        }
        free(L);
        L = NULL;
    } else {
        free(L);
        L = NULL;
    }
}

// Consultation

void viewList(const List *L) {
    printf("[ ");
    for (LNode *E = Head(L); E; E = Successor(E)) {
        (*L->viewData)(E->data); // Affiche la donnée, suivi d'un espace pour aérer
        printf(" ");
    }
    printf("]\n\n");
}

// Modification

void listInsertFirst(List *L, void *data) {
    LNode *node = newLNode(data);
    if (listIsEmpty(L)) {
        setHead(L, node);
        setTail(L, node);
    } else {
        setSuccessor(node, Head(L));
        setPredecessor(Head(L), node);
        setHead(L, node);
    }
    increaseListSize(L);
}

void listInsertLast(List *L, void *data) {
    LNode *node = newLNode(data);
    if (listIsEmpty(L)) {
        setHead(L, node);
        setTail(L, node);
    } else {
        setSuccessor(Tail(L), node);
        setPredecessor(node, Tail(L));
        setTail(L, node);
    }
    increaseListSize(L);
}

void listInsertAfter(List *L, void *data, LNode *ptrelm) {
    if (ptrelm == NULL)
        ShowMessage("Le pointeur doit obligatoirement designer un noued de la liste", 1);
    if (listIsEmpty(L))
        listInsertFirst(L, data);
    else if (ptrelm == Tail(L))
        listInsertLast(L, data);
    else {
        LNode *node = newLNode(data);
        setPredecessor(node, ptrelm);
        setSuccessor(node, Successor(ptrelm));
        setSuccessor(ptrelm, node);
        setPredecessor(Successor(ptrelm), node);
    }
    increaseListSize(L);
}

void *listRemoveFirst(List *L) {
    assert(Head(L));
    if (listIsEmpty(L))
        ShowMessage("La liste ne doit pas être vide", 1);

    void *data = getLNodeData(Head(L));
    LNode *succ = Successor(Head(L));
    free(Head(L));
    setHead(L, succ);
    setPredecessor(Head(L), NULL);
    decreaseListSize(L);
    return data;
}

void *listRemoveLast(List *L) {
    assert(Tail(L));
    if (listIsEmpty(L))
        ShowMessage("La liste ne doit pas être vide", 1);

    void *data = getLNodeData(Tail(L));
    LNode *pred = Predecessor(Tail(L));
    free(Tail(L));
    setTail(L, pred);
    setSuccessor(Tail(L), NULL); // On met le successeur de la queue de la liste a NULL
    // pour éviter un seg fault lors de l'affochage de la liste
    // listRemoveNode(L, Tail(L));
    decreaseListSize(L);
    return data;
}

void *listRemoveNode(List *L, LNode *node) {
    assert(Head(L) && Tail(L));
    if (listIsEmpty(L))
        ShowMessage("La liste ne doit pas être vide", 1);

    if (node == Head(L))
        listRemoveFirst(L);
    else if (node == Tail(L))
        listRemoveLast(L);
    else {
        setSuccessor(Predecessor(node), Successor(node));
        setPredecessor(Successor(node), Predecessor(node));
        free(node);
    }

    decreaseListSize(L);
    return node->data;
}

List *listConcatenate(List *L1, List *L2) {
    if (listIsEmpty(L1) == 1) {
        freeList(L1, 0);
        return L2;
    } else {
        setSuccessor(Tail(L1), Head(L2));
        setPredecessor(Head(L2), Tail(L1));
        setTail(L1, Tail(L2));
        setListSize(L1, getListSize(L1) + getListSize(L2));
        freeList(L2, 0);
        return L1;
    }
}

// Fonctions externes

void viewHead(List *L) {
    printf("Tete : ");
    if (Head(L) == NULL)
        printf("NULL\n");
    else {
        viewInt(getLNodeData(Head(L)));
        printf("\n");
    }
}

void viewTail(List *L) {
    printf("Queue : ");
    if (Tail(L) == NULL)
        printf("NULL\n");
    else {
        viewInt(getLNodeData(Tail(L)));
        printf("\n");
    }
}

void viewAll(List *L) {
    printf("Taille : %d\n", getListSize(L));
    viewHead(L);
    viewTail(L);
    viewList(L);
}
