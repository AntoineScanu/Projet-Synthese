#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "tree.h"
#include "heap.h"
#include "util.h"

/**********************************************************************************
 * ARRAY HEAP
 **********************************************************************************/

int getAHMaxSize(const ArrayHeap *AH)
{
	return AH->MAX;
}

int getAHActualSize(const ArrayHeap *AH)
{
	return AH->N;
}

void *getAHNodeAt(const ArrayHeap *AH, int pos)
{
	return AH->A[pos];
}

void decreaseAHActualSize(ArrayHeap *AH)
{
	AH->N--;
}

void setAHNodeAt(ArrayHeap *AH, int position, void *newData)
{
	if (position < 0)
		ShowMessage("La position ne peut pas être négative", 1);
	else if (position > getAHMaxSize(AH))
		ShowMessage("La position ne peut pas dépasser la taille maximale du tas", 1);
	else
	{
		AH->A[position] = newData;
	}
}

/**
 * @brief Corrige la position de l'élément de la position \p pos
 * du tas \p AH en le comparant avec ses fils et en l'échangeant avec
 * le fils de la plus grande priorité si nécessaire.
 *
 * Procédure récursive.
 *
 * @param[in] AH
 * @param[in] pos L'indice de la valeur en mouvement vers le bas.
 */
static void updateArrayHeapDownwards(ArrayHeap *AH, int pos)
{
	int fg = 2 * pos + 1;
	int fd = 2 * pos + 2;
	int pere = (pos - 1) / 2;

	if (fd < getAHActualSize(AH))
	{
		int min;

		if (AH->preceed(getAHNodeAt(AH, fg), getAHNodeAt(AH, fd)))
			min = fg;
		else
			min = fd;

		if (AH->preceed(getAHNodeAt(AH, min), getAHNodeAt(AH, pere)))
		{
			int temp = min;
			min = pere;
			pere = temp;
			updateArrayHeapDownwards(AH, pos++);
		}
	}
	else
	{
		if (AH->preceed(getAHNodeAt(AH, fg), getAHNodeAt(AH, pere)))
		{
			int temp = fg;
			fg = pere;
			pere = temp;
			updateArrayHeapDownwards(AH, pos++);
		}
	}
}

ArrayHeap *ArrayToArrayHeap(void **A, int N,
							int (*preceed)(const void *, const void *),
							void (*viewHeapData)(const void *),
							void (*freeHeapData)(void *))
{
	ArrayHeap *AH = (ArrayHeap *)calloc(1, sizeof(ArrayHeap));
	assert(AH);
	AH->viewHeapData = viewHeapData;
	AH->freeHeapData = freeHeapData;
	AH->MAX = N;
	AH->N = 0;

	for (int i = 0; i < N; i++)
	{
		AH->A[i] = A[i];
		AH->N++;
	}

	// Corrige la position des éléments
	for (int i = 0; i < N; i++)
	{
		updateArrayHeapDownwards(AH, i);
	}
}

void viewArrayHeap(const ArrayHeap *AH)
{
	for (int i = 0; i < getAHActualSize(AH); i++)
		AH->viewHeapData(getAHNodeAt(AH, i));
}

void freeArrayHeap(ArrayHeap *AH, int deletenode)
{
	// TODO
}

void *ArrayHeapExtractMin(ArrayHeap *AH)
{
	assert(getAHActualSize(AH) > 0);
	if (getAHActualSize(AH) == 1)
	{
		void *elm = getAHNodeAt(AH, 0);
		setAHNodeAt(AH, 0, NULL);
		decreaseAHActualSize(AH);
		return elm;
	}
	else
	{
		int highPriority = 0;
		int i;
		for (i = 1; i < getAHActualSize(AH); i++)
		{
			if (AH->preceed(getAHNodeAt(AH, i - 1), getAHNodeAt(AH, i)))
				highPriority = i;
		}
		void *elm = getAHNodeAt(AH, i);
		setAHNodeAt(AH, i, NULL);
		decreaseAHActualSize(AH);
		return elm;
	}
}

/**********************************************************************************
 * COMPLETE BINARY TREE HEAP
 **********************************************************************************/

CBTHeap *newCBTHeap(int (*preceed)(const void *, const void *),
					void (*viewHeapData)(const void *),
					void (*freeHeapData)(void *))
{
	CBTHeap *THeap = (CBTHeap *)calloc(1, sizeof(CBTHeap));
	assert(THeap);
	THeap->preceed = preceed;
	THeap->viewHeapData = viewHeapData;
	THeap->freeHeapData = freeHeapData;
	THeap->T = newCBTree(viewCBTree, freeCBTree);
}

CBTree *getCBTree(const CBTHeap *H)
{
	CBTree *T = newCBTree(viewCBTree, freeCBTree);
	if (treeIsEmpty(H->T))
		ShowMessage("Le tas H est vide", 0);
	else if (getCBTreeSize(H->T) == 1)
	{
		setRoot(T, Root(H->T));
		increaseCBTreeSize(T);
	}
	else
	{
		setRoot(T, Root(H->T))
	}
	return T;
}

/**
 * @brief Corrige la position du nœud à la position \p pos
 * de l'arbre raciné à \p node en le comparant avec son père
 * et en l'échangeant avec lui si nécessaire.
 * Le pointeur de fonction \p preceed est utilisé pour la comparaison.
 *
 * Procédure récursive. En descendant, on cherche le premier nœud
 * à corriger qui se trouve dans la position \p pos (de la même façon
 * que dans insertAfterLastTNode). En remontant, on corrige en échangeant
 * avec le père, si besoin.
 *
 * @param[in] node
 * @param[in] position
 * @param[in] preceed
 */
static void updateCBTHeapUpwards(TNode *node, int pos, int (*preceed)(const void *, const void *))
{
	// TODO
}

void CBTHeapInsert(CBTHeap *H, void *data)
{
	// TODO
}

/**
 * @brief Corrige la position du nœud \p node en le comparant avec ses fils
 * et en l'échangeant avec le fils de la plus grande priorité si nécessaire.
 * Le pointeur de fonction \p preceed est utilisé pour la comparaison.
 *
 * Procédure récursive.
 *
 * NB: Le sous-arbre avec racine \p node ne peut pas être vide.
 *
 * @param[in] node
 * @param[in] preceed
 */
static void updateCBTHeapDownwards(TNode *node, int (*preceed)(const void *, const void *))
{
	assert(node);
	// TODO
}

void *CBTHeapExtractMin(CBTHeap *H)
{
	assert(Root(getCBTree(H)));
	// TODO
}

void viewCBTHeap(const CBTHeap *H)
{
	// TODO
}

void freeCBTHeap(CBTHeap *H, int deletenode)
{
	// TODO
}