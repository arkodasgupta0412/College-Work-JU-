#include <stdio.h>
#include <math.h>

int checkPrime(int n)
{
    // by-default c = 2 because 1 and number itself are already factors
    int c = 2, flag = 0;

    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            c += 1;
        }

        if (c > 2)
        {
            // composite. because number of factors greater than 2
            flag = 1;
            break;
        }
    }

    // prime
    if (flag == 0)
    {
        return 1;
    }

    // composite
    else
    {
        return 0;
    }
}

int main()
{
    printf("The prime numbers between 1 and 100:\n");
    for (int i = 1; i <= 100; ++i)
    {
        if (checkPrime(i) && i != 1)
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}