#ifndef P1B_H
#define P1B_H

typedef struct PolyNode
{
    double coeff;
    int exp;
    struct PolyNode *next;

} PolyNode;

PolyNode *createNode(double, int);
PolyNode *createPoly(int);

#endif