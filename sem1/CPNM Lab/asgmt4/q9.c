#include <stdio.h>

int main(void)
{
    int row, col, iter;
    printf("Enter row and col of matrix: ");
    scanf("%d %d", &row, &col);

    // to allocate minimum number of cells(rows / columns) required for transpose
    if (row > col)
    {
        iter = row;
    }
    else
    {
        iter = col;
    }

    // initializing minimum-sized null matrix that is required to hold both original matrix and its transpose
    int m[iter][iter];
    for (int i = 0; i < iter; ++i)
    {
        for (int j = 0; j < iter; ++j)
        {
            m[i][j] = 0;
        }
    }

    // getting matrix
    printf("Enter matrix elements:\n");
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            scanf("%d", &m[i][j]);
        }
    }

    // printing matrix
    printf("\nMatrix entered:\n");
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    // doing transpose
    for (int i = 0; i < iter; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            // swapping values
            int tmp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = tmp;
        }
    }

    printf("\n");

    // printing final transpose
    printf("Transpose:\n");
    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}