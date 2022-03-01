#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "tree.h"
#include "util.h"

/********************************************************************
 * TNode
 ********************************************************************/

TNode *newTNode(void *data)
{
	TNode *T = (TNode *)calloc(1, sizeof(TNode));
	assert(data);
	T->data = data;
	return T;
}

void *getTNodeData(const TNode *node)
{
	return node->data;
}

TNode *Left(const TNode *node)
{
	return node->right;
}

TNode *Right(const TNode *node)
{
	return node->left;
}

void setTNodeData(TNode *node, void *newData)
{
	node->data = newData;
}

void setLeft(TNode *node, TNode *newLeft)
{
	node->left = newLeft;
}

void setRight(TNode *node, TNode *newRight)
{
	node->left = newRight;
}

/********************************************************************
 * Complete Binary Tree
 ********************************************************************/

CBTree *newCBTree(void (*viewData)(const void *), void (*freeData)(void *))
{
	CBTree *T = (CBTree *)calloc(1, sizeof(CBTree));
	assert(T);
	T->viewData = viewData;
	T->freeData = freeData;
	return T;
}

int treeIsEmpty(CBTree *T)
{
	if (T->numelm == 0)
		return 1;
	else
		return 0;
}

int getCBTreeSize(const CBTree *T)
{
	return T->numelm;
}

TNode *Root(const CBTree *T)
{
	return T->root;
}

void increaseCBTreeSize(CBTree *T)
{
	T->numelm++;
}

void decreaseCBTreeSize(CBTree *T)
{
	T->numelm--;
}

void resetCBTreeSize(CBTree *T)
{
	T->numelm = 0;
}

void setRoot(CBTree *T, TNode *newRoot)
{
	T->root = newRoot;
}

/**
 * @brief Libère récursivement le sous-arbre raciné au nœud \p node.
 * Dans le cas où le pointeur de fonction \p freeData n'est pas NULL,
 * la mémoire de la donnée du nœud actuel est aussi libérée.
 * NB : procédure récursive.
 *
 * @param[in] node
 * @param[in] freeData
 */
static void freeTNode(TNode *node, void (*freeData)(void *)) {
    if (Right(node) != NULL && Left(node) != NULL) {
        freeTNode(Right(node), freeData);
        freeTNode(Left(node), freeData);
        /*free(node);*/
    } else if (Right(node) != NULL) {
        freeTNode(Right(node), freeData);
        /*free(node);*/
    } else if (Left(node) != NULL) {
        freeTNode(Left(node), freeData);
        /*free(node);*/
    } else {
        free(node);
    }
    (*freeData)(node);
}

/**
 * NB : Utilisez la procédure récursive freeTNode.
 * Vous devez initialiser le paramètre freeData
 * par rapport à la valeur de deleteData.
 */
void freeCBTree(CBTree *T, int deleteData)
{
	// TODO
}

/**
 * @brief Affiche les éléments de l'arbre raciné au nœud \p node
 * en réalisant un parcours préfixé.
 * Les données de chaque nœud sont afficher en utilisant le
 * pointer de fonction \p viewData.
 *
 * @param[in] node
 * @param[in] viewData
 */
static void preorder(TNode *node, void (*viewData)(const void *))
{
	// TODO
}

/**
 * @brief Affiche les éléments de l'arbre raciné au nœud \p node
 * en réalisant un parcours infixé.
 * Les données de chaque nœud sont afficher en utilisant le
 * pointer de fonction \p viewData.
 *
 * @param[in] node
 * @param[in] viewData
 */
static void inorder(TNode *node, void (*viewData)(const void *))
{
	// TODO
}

/**
 * @brief Affiche les éléments de l'arbre raciné au nœud \p node
 * en réalisant un parcours postfixé.
 * Les données de chaque nœud sont afficher en utilisant le
 * pointer de fonction \p viewData.
 *
 * @param[in] node
 * @param[in] viewData
 */
static void postorder(TNode *node, void (*viewData)(const void *))
{
	// TODO
}

/**
 * NB : Utilisez les procédures récursives preorder, inorder et postorder.
 * Rappel : order = 0 (preorder), 1 (postorder), 2 (inorder)
 */
void viewCBTree(const CBTree *T, int order)
{
	if (order == 0)
		preorder(T, viewInt);
	else if (order == 1)
		postorder(T, viewInt);
	else if (order == 2)
		inorder(T, viewInt);
	else
		ShowMessage("Erreur viewCBTree : Veuillez rentrez un chiffre valide parmi 0, 1 ou 2", 1);
}

/**
 * @brief Insère récursivement un nouveau nœud de donnée \p data
 * dans l'arbre raciné au nœud \p node.
 * La position (par rapport à la racine \p node) où le nouveau nœud
 * va être insérer est indiquée par le paramètre \p position
 * (voir la figure ci-dessous pour la définition de la position).
 *
 *          0
 *       /     \
 *      1       2
 *     / \     / \
 *    3   4   5   6
 *   / \
 *  7  ...
 *
 * @param[in] node La racine de l'arbre actuel.
 * @param[in] position La position du nouveau élément
 * 						par rapport à la racine \p node.
 * @param[in] data La donnée à insérer.
 * @return TNode* Le nœud \p node mis à jour.
 */
static TNode *insertAfterLastTNode(TNode *node, int position, void *data)
{
	// TODO
}

/**
 * NB : Utilisez la procédure récursive insertAfterLastTNode
 * afin de lancer l'insertion.
 */
void CBTreeInsert(CBTree *T, void *data)
{
	// TODO
}

/**
 * @brief Supprime récursivement le dernier nœud
 * de l'arbre raciné au nœud \p node.
 * La position (par rapport à la racine \p node) du nœud à supprimer
 * est indiquée par le paramètre \p position
 * (voir la figure ci-dessous pour la définition de la position).
 * La mémoire du dernier nœud est libérée mais pas la mémoire de sa donnée.
 *
 *          0
 *       /     \
 *      1       2
 *     / \     / \
 *    3   4   5   6
 *   / \
 *  7  ...
 *
 * @param[in] node La racine de l'arbre actuel.
 * @param[in] position La position de l'élément à supprimer
 *                         par rapport à la racine \p node.
 * @param[out] data La donnée du nœud supprimé (sortie).
 * @return TNode* Le nœud \p node mis à jour.
 */
static TNode *removeLastTNode(TNode *node, int position, void **data)
{
	// TODO
}

/**
 * NB : Utilisez la procédure récursive removeLastTNode
 * afin de lancer la suppression.
 */
void *CBTreeRemove(CBTree *T)
{
	assert(Root(T));
	// TODO
}

/**
 * @brief Restitue récursivement le dernier nœud
 * de l'arbre raciné au nœud \p node.
 * La position (par rapport à la racine \p node) de ce dernier nœud
 * est indiquée par le paramètre \p position
 * (voir la figure ci-dessous pour la définition de la position).
 *
 *          0
 *       /     \
 *      1       2
 *     / \     / \
 *    3   4   5   6
 *   / \
 *  7  ...
 *
 * @param node La racine de l'arbre actuel.
 * @param position La position du dernier nœud par rapport à la racine \p node.
 * @return TNode* Le dernier nœud de l'arbre.
 */
static TNode *getLastTNode(TNode *node, int position)
{
	// TODO
}

/**
 * NB : Utilisez la procédure récursive getLastTNode
 * afin de lancer la recherche.
 */
TNode *CBTreeGetLast(CBTree *T)
{
	// TODO
}

void CBTreeSwapData(TNode *node1, TNode *node2)
{
	// TODO
}