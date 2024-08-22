#include <stdio.h>
#define POPULATION 80000
#define MEN_PERCENT 0.52
#define TOTAL_LITERACY_PERCENT 0.48
#define MEN_LITERACY_PERCENT 0.35

int main()
{
    int literate = TOTAL_LITERACY_PERCENT * POPULATION;
    int literate_men = MEN_LITERACY_PERCENT * POPULATION;
    int literate_women = literate - literate_men;
    int total_men = MEN_PERCENT * POPULATION;
    int total_women = POPULATION - total_men;
    int illiterate_women = total_women - literate_women;
    int illiterate_men = total_men - literate_men;

    printf("total illiterate men: %d\n", illiterate_men);
    printf("total illiterate women: %d\n", illiterate_women);

    return 0;
}