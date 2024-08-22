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

float **transpose(float **m)
{
    float **t;

    t = (float **)malloc(3 * sizeof(float *));
    for (int i = 0; i < 3; ++i)
    {
        *(t + i) = (float *)malloc(3 * sizeof(float));
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            t[j][i] = m[i][j];
        }
    }

    return t;
}

int main()
{
    float **a;
    a = input_matrix();

    printf("\nMatrix A:\n");
    print_matrix(a);

    float **t = transpose(a);
    printf("\nTranspose of A:\n");
    print_matrix(t);

    return 0;
}