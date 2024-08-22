#include <stdio.h>

// Pattern 1
void pattern1(int n)
{
    for (int row = 1; row <= n; ++row)
    {
        for (int col = 1; col <= row; ++col)
        {
            printf("%d ", col);
        }

        printf("\n");
    }
}

// Pattern 2
void pattern2(int n)
{
    int space = 2 * (n - 1);

    for (int row = 1; row <= n; ++row)
    {
        for (int k = 0; k < space; ++k)
        {
            printf(" ");
        }

        for (int col = 1; col <= row; ++col)
        {
            printf("%d ", col);
        }

        space -= 2;
        printf("\n");
    }
}

// Pattern 3
void pattern3(int n)
{
    int space = 2 * (n - 1);

    for (int row = 1; row <= n; ++row)
    {
        for (int k = 0; k < space; ++k)
        {
            printf(" ");
        }

        for (int col = 1; col <= row; ++col)
        {
            printf("%d ", col);
        }

        for (int col = row - 1; col >= 1; --col)
        {
            printf("%d ", col);
        }

        space -= 2;
        printf("\n");
    }
}

void pattern4(int n)
{
    int space = 2 * n - 2;

    for (int i = 1; i <= 2 * n - 1; ++i)
    {
        // printing the spaces
        for (int m = 0; m < space; ++m)
        {
            printf(" ");
        }

        // printing the numbers
        if (i % 2 != 0)
        {
            int j;

            if (i == 1)
            {
                printf("1");
            }
            else
            {
                for (j = 1; j < i; ++j)
                {
                    if (j > (i / 2) + 1)
                    {
                        break;
                    }
                    printf("%d ", j);
                }

                for (int k = j - 2; k >= 1; --k)
                {
                    printf("%d ", k);
                }
            }
        }

        else
        {
            int j;
            if (i == 2)
            {
                printf("1 1");
            }
            else
            {
                for (j = 1; j < 2 * i; ++j)
                {
                    if (j > i / 2)
                    {
                        break;
                    }
                    printf("%d ", j);
                }

                // printf("j = %d", j);

                for (int k = j - 1; k >= 1; --k)
                {
                    printf("%d ", k);
                }
            }
        }
        printf("\n");
        space -= 1;
    }
}

void pattern5(int n)
{
    int k = n;

    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = k; j >= i - 1; --j)
        {
            printf("%d ", j);
        }
        printf("\n");
        --k;
    }
}

void pattern6(int n)
{
    int space = n - 1, plus = 1;

    for (int row = 1; row <= 2 * n - 1; ++row)
    {

        if (row <= n)
        {
            // printf("row = %d and space = %d and plus = %d\n", row, space, plus);
            for (int i = 0; i < space; ++i)
            {
                printf(" ");
            }

            for (int i = 0; i < plus; ++i)
            {
                printf("+");
            }

            space -= 1, plus += 2;
        }

        else
        {
            if (space == -1 && plus == 2 * n + 1)
            {
                space = 1, plus -= 4;
            }

            for (int i = 0; i < space; ++i)
            {
                printf(" ");
            }

            for (int i = 0; i < plus; ++i)
            {
                printf("+");
            }

            space += 1, plus -= 2;
        }

        printf("\n");
    }
}

void pattern7(int n)
{
    int space = 2 * (n - 1);

    for (int row = 1; row <= n; ++row)
    {
        int col;
        for (int k = 0; k < space; ++k)
        {
            printf(" ");
        }

        for (col = 1; col <= row; ++col)
        {
            printf("%d ", col);
        }

        if (row != 1)
        {
            // why col1 = col - 2
            // because for the previous loop, suppose in row3, col = 4 after previous loop termination
            // so we need to decrement col by 2 (4 - 2 = 2) to start printing col again from 2->1
            for (int col1 = col - 2; col1 >= 1; --col1)
            {
                printf("%d ", col1);
            }
        }

        space -= 2;
        printf("\n");
    }
}

void pattern8(int n)
{
    int midspace = 1;

    // topmost row with no midspace
    for (int col = 0; col < 2 * n + 1; ++col)
    {
        printf("*");
    }
    printf("\n");

    // top half
    for (int row = 0; row < n; ++row)
    {
        for (int col = n - row; col >= 1; --col)
        {
            printf("*");
        }
        for (int col = 0; col < midspace; ++col)
        {
            printf(" ");
        }
        for (int col = n - row; col >= 1; --col)
        {
            printf("*");
        }
        midspace += 2;
        printf("\n");
    }

    // bottomhalf
    midspace -= 4;
    int j = 0;

    for (int row = n; row < 2 * n - 1; ++row)
    {
        for (int col = 0; col < 2 + j; ++col)
        {
            printf("*");
        }

        for (int col = 0; col < midspace; ++col)
        {
            printf(" ");
        }

        for (int col = 0; col < 2 + j; ++col)
        {
            printf("*");
        }

        j += 1;
        midspace -= 2;
        printf("\n");
    }

    // bottommost row with no spaces
    for (int col = 0; col < 2 * n + 1; ++col)
    {
        printf("*");
    }
    printf("\n");
}

void pattern9(int n)
{
    int totalRows = n * 2 - 1;
    int i, j;

    for (i = 1; i <= totalRows; i++)
    {
        for (j = 1; j <= totalRows; j++)
        {
            if (i <= n)
            {
                if (j == n - i + 1 || j == n + i - 1)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            else
            {
                if (j == i - n + 1 || j == totalRows - i + n)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int main(void)
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("\nPattern 1:\n\n");
    pattern1(n);

    printf("\n\nPattern 2:\n\n");
    pattern2(n);

    printf("\n\nPattern 3:\n\n");
    pattern3(n);

    printf("\n\nPattern 4:\n\n");
    pattern4(n);

    printf("\n\nPattern 5:\n\n");
    pattern5(n);

    printf("\n\nPattern 6:\n\n");
    pattern6(n);

    printf("\n\nPattern 7:\n\n");
    pattern7(n);

    printf("\n\nPattern 8:\n\n");
    pattern8(n);

    printf("\n\nPattern 9:\n\n");
    pattern9(n);

    return 0;
}