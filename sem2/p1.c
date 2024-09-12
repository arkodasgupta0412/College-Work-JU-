#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void factorialIterative(int n)
{
    int f = 1;
    unsigned long long fact = 0;
    int flag = 0; // Flag to indicate overflow
    int p = 0;    // Print overflow only once

    for (int i = 2; i <= n; i++)
    {
        // checking overflow
        if (!flag && i >= INT_MAX / f)
        {
            fact = f;
            flag = 1;

            if (!p)
            {
                printf("\nOverflow occurred at i = %d, switching to long long\n", i);
                p = 1;
            }
        }


		if (flag == 1 && i >= LONG_MAX / fact) {
			printf("Factorial too large. Aborting....\n");
			exit(0);
		}

        // After overflow, switch to long long and continue calculation
        if (flag)
        {
            fact *= i; // continuing with long long
        }
        else
        {
            f *= i; // continuing with int
        }
    }

    if (flag)
    {
        printf("Integer Overflow\n");
        printf("Factorial: %lld\n", fact);
    }
    else
    {
        printf("\nFactorial: %d\n", f);
    }
}

void factorialRecursive(int i, int flag, int n, unsigned long long fact, int f)
{
    if (i == n + 1)
    {
        if (flag)
        {
            printf("Integer overflow\n");
            printf("Factorial: %lld\n", fact);
        }
        else
        {
            printf("\nFactorial: %d\n", f);
        }
        return;
    }

    if (!flag)
    {
        if (i >= INT_MAX / f)
        {
            fact = f;
            flag = 1;
            printf("\nOverflow occurred at i = %d, switching to long long\n", i);
        }
    }

	/* if (flag == 1 && i >= LONG_MAX / fact) {
			printf("Factorial too large. Aborting....\n");
			exit(1);
	} */

    if (flag)
    {
        fact *= i;
    }
    else
    {
        f *= i;
    }

    factorialRecursive(i + 1, flag, n, fact, f);
}

int main()
{
    int n1, n2;
    printf("Enter values of n1 and n2: ");
    scanf("%d %d", &n1, &n2);

    printf("\nITERATIVE: n1 = %d, n2 = %d\n", n1, n2);
    // iterative (without overflow)
    printf("\ncalculating %d!...", n1);
    factorialIterative(n1);

    // iterative (with overflow)
    printf("\ncalculating %d!...", n2);
    factorialIterative(n2);

    printf("---------------------------------------------------------------\n");
    printf("\nRECURSIVE: n1 = %d, n2 = %d\n", n1, n2);
    // recursive (without overflow)
    printf("\ncalculating %d!...", n1);
    factorialRecursive(1, 0, n1, 1, 1);

    // recursive (with overflow)
    printf("\ncalculating %d!...", n2);
    factorialRecursive(1, 0, n2, 1, 1);

    return 0;
}
