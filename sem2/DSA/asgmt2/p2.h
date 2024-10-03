#ifndef P2_H
#define P2_H

#include <stdio.h>
#include <stdlib.h>

// Define a node for a non-zero element in the sparse matrix
typedef struct Node
{
    int row;   // Row index of the element
    int col;   // Column index of the element
    int value; // Non-zero value
    struct Node *next;
} Node;

// Define a sparse matrix as a linked list of non-zero elements
typedef struct SparseMatrix
{
    int rows;   // Total number of rows in the matrix
    int cols;   // Total number of columns in the matrix
    Node *head; // Pointer to the head of the linked list
} SparseMatrix;

// Function declarations
SparseMatrix *createSparseMatrix(int, int);
void insertElement(SparseMatrix, int, int, int v);
void displaySparseMatrix(const SparseMatrix);
SparseMatrix *addSparseMatrices(const SparseMatrix *, const SparseMatrix *);
SparseMatrix *multiplySparseMatrices(const SparseMatrix *, const SparseMatrix *);
void deleteSparseMatrix(SparseMatrix *);

#endif // P2_H
