#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int prime[8] = {1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049};
    long long largeInt[10];

    // generating 10 large integers (which exceeds integer range)
    for (int i = 0; i < 10; i++)
    {
        largeInt[i] = (1LL << 31) + (rand() % (1LL << 31));
    }

    long long r;
    for (int i = 0; i < 8; i++)
    {
        // generating 10 large integers (which exceeds integer range)
        printf("\n\nPrime #%d: %d\n", i + 1, prime[i]);
        printf("L_i\t\t\t\t\t\tR_i\n");
        for (int j = 0; j < 10; j++)
        {
            printf("%lld\t\t\t\t\t%lld\n", largeInt[j], largeInt[j] % prime[i]);
        }
    }
}
