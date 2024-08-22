#include <iostream>
using namespace std;

int main()
{
    int mat[5][5] = {{1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}};

    int soldierCount[5][2] = {{0, 2}, {1, 4}, {2, 1}, {3, 2}, {4, 5}};

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5 - i - 1; ++i)
        {
            if (soldierCount[j][1] > soldierCount[j + 1][1])
            {
                int tmp = soldierCount[j + 1][1];
                soldierCount[j + 1][1] = soldierCount[j][1];
                soldierCount[j][1] = tmp;

                int tmp1 = soldierCount[j + 1][0];
                soldierCount[j + 1][0] = soldierCount[j][0];
                soldierCount[j][0] = tmp1;
            }
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        cout << soldierCount[i][0] << " " << soldierCount[i][1] << endl;
    }

    return 0;
}
