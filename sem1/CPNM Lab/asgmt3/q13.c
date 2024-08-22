#include <stdio.h>
#include <string.h>

int ctoi(char c)
{
    return c - '0';
}

char itoc(int i)
{
    return i + '0';
}

int decimalToBase(int n, int b)
{
    // converts decimal number to any base (except hexadecimal)

    int s = 0;
    if (n == 0)
    {
        return s;
    }
    else
    {
        s = (n % b) + (10 * decimalToBase(n / b, b));
    }
}

int getPower(int x, int y)
{
    // returns x ^ y
    int p = 1;
    while (y)
    {
        p *= x;
        y--;
    }
    return p;
}

int baseToDecimal(int n, int b)
{
    // converts any base (except hexadecimal) to decimal

    int s = 0, i = 0;
    while (n)
    {
        int rem = n % 10;
        s += rem * getPower(b, i);
        i++;
        n /= 10;
    }

    return s;
}

int hexToDecimal(char h[])
{
    int l = strlen(h), i = l - 1, digit, j = 0, s = 0;

    while (i >= 0)
    {
        switch (h[i])
        {
        case 'A':
        case 'a':
            digit = 10;
            break;

        case 'B':
        case 'b':
            digit = 11;
            break;

        case 'C':
        case 'c':
            digit = 12;
            break;

        case 'D':
        case 'd':
            digit = 13;
            break;

        case 'E':
        case 'e':
            digit = 14;
            break;

        case 'F':
        case 'f':
            digit = 15;
            break;

        default:
            digit = ctoi(h[i]);
            break;
        }

        s += digit * getPower(16, j);
        i--;
        j++;
    }

    return s;
}

void decToHex(int n)
{
    char hex[15];
    int i = 0;
    while (n)
    {
        int rem = n % 16;
        switch (rem)
        {
        case 10:
            hex[i++] = 'A';
            break;

        case 11:
            hex[i++] = 'B';
            break;

        case 12:
            hex[i++] = 'C';
            break;

        case 13:
            hex[i++] = 'D';
            break;

        case 14:
            hex[i++] = 'E';
            break;

        case 15:
            hex[i++] = 'F';
            break;

        default:
            hex[i++] = itoc(rem);
        }
        n /= 16;
    }

    // if decimal number = 0
    if (i == 0)
    {
        hex[i++] = '0';
    }

    hex[i] = '\0';

    // reversing the hex array to get correct order
    for (int j = 0; j < i / 2; ++j)
    {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }

    printf("%s\n", hex);
}

int main()
{
    int ib, ob, n;
    char hex[15];

    printf("Enter input base: ");
    scanf("%d", &ib);
    printf("Enter output base: ");
    scanf("%d", &ob);

    if (ib != 16)
    {
        printf("Enter number in input base: ");
        scanf("%d", &n);

        if (ob != 16)
        {
            printf("Number in output base: %d\n", decimalToBase(baseToDecimal(n, ib), ob));
        }
        else
        {
            printf("Number in output base: ");
            decToHex(baseToDecimal(n, ib));
        }
    }

    else
    {
        printf("Enter number in input base: ");
        scanf("%s", hex);

        printf("Number in output base: %d\n", decimalToBase(hexToDecimal(hex), ob));
    }

    return 0;
}