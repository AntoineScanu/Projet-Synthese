#include <stdio.h>
#include <stdlib.h>
#include "geometry.h"
#include "util.h"

Point *newPoint(long long int x, long long int y)
{
    Point *P = (Point *)calloc(1, sizeof(Point));
    P->x = x;
    P->y = y;
    return P;
}

long long int X(const Point *P)
{
    return P->x;
}

long long int Y(const Point *P)
{
    return P->y;
}

void viewPoint(const void *P)
{
    printf("(%lld, %lld)\n", X(P), Y(P));
}

void freePoint(void *P)
{
    free(P);
    P = NULL;
}

int onRight(const Point *origin, const Point *destination, const Point *P)
{
    if (((X(destination) - X(origin)) * (Y(P) - Y(origin)) - (Y(destination) - Y(origin)) * (X(P) - X(origin))) > 0)
        return 1;
    else
        return 0;
}

int onLeft(const Point *origin, const Point *destination, const Point *P)
{
    if (((X(destination) - X(origin)) * (Y(P) - Y(origin)) - (Y(destination) - Y(origin)) * (X(P) - X(origin))) < 0)
        return 1;
    else
        return 0;
}

int collinear(const Point *origin, const Point *destination, const Point *P)
{
    if (((X(destination) - X(origin)) * (Y(P) - Y(origin)) - (Y(destination) - Y(origin)) * (X(P) - X(origin))) == 0)
        return 1;
    else
        return 0;
}

int isIncluded(const Point *origin, const Point *destination, const Point *P)
{
    if (collinear(origin, destination, P))
    {
        if (onRight(origin, destination, P) && onLeft(destination, origin, P))
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

DEdge *newDEdge(Point *origin, Point *destination)
{
    DEdge *DE = (DEdge *)calloc(1, sizeof(DEdge));
    DE->origin = newPoint(X(origin), Y(origin));
    DE->destination = newPoint(X(destination), Y(destination));

    return DE;
}

Point *getOrigin(const DEdge *DE)
{
    return DE->origin;
}

Point *getDestination(const DEdge *DE)
{
    return DE->destination;
}

void viewDEdge(const void *DE)
{
    printf("Origine : ");
    viewPoint(getOrigin(DE));
    printf("Destination : ");
    viewPoint(getDestination(DE));
}

void freeDEdge(void *DE)
{
    freePoint(getOrigin(DE));
    freePoint(getDestination(DE));
    free(DE);
    DE = NULL;
}