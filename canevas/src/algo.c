#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "algo.h"
#include "geometry.h"
#include "list.h"
#include "tree.h"
#include "util.h"
#include "heap.h"
#include "sort.h"

/**
 * @brief Réalise la lecture d'un ensemble des points à partir du fichier
 * \p filename.
 * Renvoie 2 paramètres : un tableau contenant les points du fichier
 * \p filename, le nombre \p N de ces points.
 *
 * @param[in] filename le nom du fichier qui contient les points d'entrée.
 * @param[out] N le nombre des points dans le fichier \p filename
 * (paramètre de sortie).
 * @return Point** le tableau avec les points du fichier \p filename.
 */
Point **readInstance(const char *filename, int *N)
{
    Point **tab = (Point **)calloc(1, sizeof(Point));
    FILE *fp;
    fp = fopen(filename, "r");

    fscanf(fp, "%d", N);
    for (int i = 1; i < *N; i++)
    {
        if (fp != NULL)
        {
            int x;
            int y;
            fscanf(fp, "%d %d", &x, &y);
            tab[i] = newPoint(x, y);
        }
        else
        {
            printf("Fichier invalide\n");
            exit(1);
        }
    }
    fclose(fp);
    return tab;
}

/**
 * @brief Réalise l'écriture de l'ensemble des points de la liste \p L
 * dans un fichier avec le nom \p filename.
 *
 * @param[in] filename le nom du fichier d'écriture.
 * @param[in] L la liste des points à écrire dans le fichier \p filename.
 */
static void writeSolution(const char *filename, List *L)
{
    FILE *fp;
    fp = fopen(filename, "w");
    LNode *n;
    n = Head(L);
    for (int i = 0; i < getListSize(L); ++i)
    {
        fprintf(fp, "%d", atoi(getLNodeData(n)));
        n = Successor(n);
    }
}

/**
 * @brief Transforme la liste des arcs \p dedges décrivant les arêtes
 * du polygone de l'enveloppe convexe à une liste des poins ordonnés
 * dans le sens horaire.
 *
 * @param[in] edges la liste des arcs de l'enveloppe convexe
 * @return List* la liste des points de l'enveloppe convexe dans le sens
 * horaire
 */
static List *DedgesToClockwisePoints(List *dedges)
{
    List *L = newList(viewPoint, freePoint);
    LNode *node = Head(dedges);

    while (Successor(node))
    {
        Point *A = newPoint(X(getOrigin(getLNodeData(node))), Y(getOrigin(getLNodeData(node))));
        Point *B = newPoint(X(getOrigin(getLNodeData(Successor(node)))), Y(getOrigin(getLNodeData(Successor(node)))));

        if (A < B)
        {
            listInsertLast(L, A);
            listInsertLast(L, B);
        }
        else if (A > B)
        {
            listInsertLast(L, B);
            listInsertLast(L, A);
        }
        else
        {
            listInsertLast(L, A);
        }
    }
    return L;
}

void SlowConvexHull(const char *infilename, const char *outfilename)
{
    //    int E=NULL;
    //    for (int i = 0; i < getListSize(L); ++i) {
    //        int ok=1;
    //
    //    }
    // TODO
    printf("SlowConvexHull\n");
}

/**
 * @brief Compare le points \p a et \p b.
 *
 * @param[in] a
 * @param[in] b
 * @return int si l'abscisse de \p a est plus petite que l'abscisse de \p b
 * renvoie 1, sinon renvoie 0. Dans le cas d'égalité, si l'ordonnée de \p a
 * est plus petite que l'ordonnée de \p b renvoie 1, sinon renvoie 0.
 */
static int smallerPoint(const void *a, const void *b)
{
    if (X(a) < X(b))
        return 1;
    else if (X(a) > X(b))
        return 0;
    else
    {
        if (Y(a) < Y(b))
            return 1;
        else if (Y(a) > Y(b))
            return 0;
    }
    return 0;
}

/**
 * @brief Compare le points \p a et \p b.
 *
 * @param[in] a
 * @param[in] b
 * @return int si l'abscisse de \p a est plus grande que l'abscisse de \p b
 * renvoie 1, sinon renvoie 0. Dans le cas d'égalité, si l'ordonnée de \p a
 * est plus grande que l'ordonnée de \p b renvoie 1, sinon renvoie 0.
 */
static int biggerPoint(const void *a, const void *b)
{
    if (X(a) > X(b))
        return 1;
    else if (X(a) < X(b))
        return 0;
    else
    {
        if (Y(a) > Y(b))
            return 1;
        else if (Y(a) < Y(b))
            return 0;
    }
    return 0;
}

void ConvexHull(const char *infilename, const char *outfilename, int sortby)
{
    printf("ConvexHull\n");
}

void RapidConvexHull(const char *infilename, const char *outfilename)
{
    printf("RapideConvexHull\n");
}