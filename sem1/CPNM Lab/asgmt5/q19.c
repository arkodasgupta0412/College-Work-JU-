#include <stdio.h>
#include <stdlib.h>

// returns 0 if dates are equal, 1 if date1 is later date2, -1 if date1 is earlier than date2;

/*
    dd / mm / yyyy
    01 2 34 5 6789

*/

int ctoi(char c)
{
    return c - '0';
}

int dateCompare(char *d1, char *d2)
{
    // date 1
    int dd1 = ctoi(d1[0]) * 10 + ctoi(d1[1]);
    int m1 = ctoi(d1[3]) * 10 + ctoi(d1[4]);
    int y1 = ctoi(d1[6]) * 1000 + ctoi(d1[7]) * 100 + ctoi(d1[8]) * 10 + ctoi(d1[9]);

    // date 2
    int dd2 = ctoi(d2[0]) * 10 + ctoi(d2[1]);
    int m2 = ctoi(d2[3]) * 10 + ctoi(d2[4]);
    int y2 = ctoi(d2[6]) * 1000 + ctoi(d2[7]) * 100 + ctoi(d2[8]) * 10 + ctoi(d2[9]);

    if (y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && dd1 > dd2))
    {
        return 1;
    }

    else if (y1 == y2 && m1 == m2 && dd1 == dd2)
    {
        return 0;
    }

    else
    {
        return -1;
    }
}

int main()
{
    char d1[11], d2[11];

    printf("Enter date1: ");
    scanf("%10s", d1);

    printf("Enter date2: ");
    scanf("%10s", d2);

    printf("%d\n", dateCompare(d1, d2));

    return 0;
}
