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
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    printf("The prime factors of %d:\n", n);

    for (int i = 2; i <= n; ++i)
    {
        if (n % i == 0 && checkPrime(i))
        {
            printf("%d ", i);
        }
    }
    return 0;
}