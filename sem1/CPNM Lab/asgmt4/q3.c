#include <stdio.h>
#include <stdlib.h>

float **input_matrix()
{
    printf("\nEnter matrix :\n");

    float **mat;
    mat = (float **)malloc(3 * sizeof(float *));
    for (int i = 0; i < 3; ++i)
    {
        *(mat + i) = (float *)malloc(3 * sizeof(float));
        for (int j = 0; j < 3; ++j)
        {
            scanf("%f", &mat[i][j]);
        }
    }
    return mat;
}

float **createNullMatrix()
{
    float **mat;
    mat = (float **)calloc(3, sizeof(float *));
    for (int i = 0; i < 3; ++i)
    {
        *(mat + i) = (float *)calloc(3, sizeof(float));
    }
    return mat;
}

void print_matrix(float **m)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("%.2f    ", m[i][j]);
        }
        printf("\n");
    }
}

float **add(float **m1, float **m2)
{
    float **s = createNullMatrix();
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            s[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return s;
}

float **subtract(float **m1, float **m2)
{
    float **d = createNullMatrix();
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            d[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return d;
}

float **multiply(float **m1, float **m2)
{
    float **p = createNullMatrix();

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                p[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return p;
}

int main()
{
    float **a = input_matrix(), **b = input_matrix(), **p, **s, **d;

    printf("\nMatrix A:\n");
    print_matrix(a);

    printf("\nMatrix B:\n");
    print_matrix(b);

    // adding matrices A and B: S = A + B
    printf("\nMatrix S = A + B:\n\n");
    s = add(a, b);
    print_matrix(s);

    // subtracting matrices A and B: D = A - B
    printf("\nMatrix D = A - B:\n\n");
    d = subtract(a, b);
    print_matrix(d);

    // multiplying matrices A and B: P = A x B
    printf("\nMatrix P = A x B:\n\n");
    p = multiply(a, b);
    print_matrix(p);

    return 0;
}