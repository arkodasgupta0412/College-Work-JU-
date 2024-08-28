#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c)
{
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int editDistance(char *A, char *B)
{
    int m = strlen(A);
    int n = strlen(B);

    // Create a DP table
    int dp[m + 1][n + 1];

    // Fill dp table
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j; // Min. operations = j (because only insertions are required)
            }
            else if (j == 0)
            {
                dp[i][j] = i; // Min. operations = i (Same as above)
            }
            else if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1]; // No operations required
            }
            else
            {
                // either insert, delete or substitute
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main()
{
    char A[100], B[100];
    printf("Enter first string: ");
    scanf("%s", A);
    printf("Enter second string: ");
    scanf("%s", B);

    int distance = editDistance(A, B);
    printf("The Edit Distance between %s and %s is %d.\n", A, B, distance);

    return 0;
}
