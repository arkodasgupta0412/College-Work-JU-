#include <stdio.h>

int ctoi(char *c)
{
    int res = 0;

    while (*c != '\0')
    {
        res = (res * 10) + (*c - '0');
        c++;
    }

    return res;
}

int main(int argc, char *argv[])
{

    if (argc < 3)
    {
        printf("Please provide at least two command-line arguments.\n");
        return 1;
    }

    int sum;
    sum = ctoi(argv[1]) + ctoi(argv[2]);

    printf("Sum of last two numbers of command line argument is: %d\n", sum);

    return 0;
}