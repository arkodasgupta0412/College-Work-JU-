#ifndef P1_H
#define P1_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 100 // Maximum degree of polynomial

typedef struct Polynomial
{
    int coefficients[MAX_DEGREE + 1];
    int degree;
} Polynomial;

// Function declarations
Polynomial *createPolynomial();
void insertTerms(Polynomial *, int);
void displayPolynomial(const Polynomial *);
Polynomial *addPolynomials(const Polynomial *, const Polynomial *);
Polynomial *subPolynomials(const Polynomial *, const Polynomial *);
Polynomial *multiplyPolynomials(const Polynomial *p, const Polynomial *);
void deletePolynomial(Polynomial *);

#endif // P1_H
