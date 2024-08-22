#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int m, int n)
{
    int **mat;
    mat = (int **)malloc(m * sizeof(int *));

    printf("Enter matrix elements:\n");

    for (int i = 0; i < m; ++i)
    {
        *(mat + i) = (int *)malloc(n * sizeof(int));

        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    return mat;
}

int **createNullMatrix(int m, int n)
{
    int **mat;
    mat = (int **)calloc(m, sizeof(int *));

    for (int i = 0; i < m; ++i)
    {
        *(mat + i) = (int *)calloc(n, sizeof(int));
    }

    return mat;
}

void printMatrix(int **m, int r, int c)
{
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int **product(int **m1, int **m2, int r1, int c1, int r2, int c2)
{
    int **p = createNullMatrix(r1, c2);

    for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c2; ++j)
        {
            for (int k = 0; k < r2; ++k)
            {
                p[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return p;
}

int main()
{
    int **m1, **m2, **p, r1, r2, c1, c2;
    printf("\nEnter rows and cols of matrix 1: ");
    scanf("%d %d", &r1, &c1);
    m1 = createMatrix(r1, c1);

    printf("\nEnter rows and cols of matrix 2: ");
    scanf("%d %d", &r2, &c2);
    m2 = createMatrix(r2, c2);

    printf("\nMatrix 1:\n");
    printMatrix(m1, r1, c1);

    printf("\nMatrix 2:\n");
    printMatrix(m2, r2, c2);

    if (c1 != r2)
    {
        printf("Matrix 1 and matrix 2 cannot be multiplied\n");
    }

    else
    {
        printf("\nProduct:\n");
        p = product(m1, m2, r1, c1, r2, c2);
        printMatrix(p, r1, c2);
    }

    return 0;
}