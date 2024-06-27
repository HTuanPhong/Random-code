#include <algorithm>
#include <iostream>

int longestCommonSubSequence(int A[], int m, int B[], int n)
{
    int lcss[m][n] = {};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp1 = (i == 0 || j == 0) ? 0 : lcss[i - 1][j - 1];
            int temp2 = (i == 0) ? 0 : lcss[i - 1][j];
            int temp3 = (j == 0) ? 0 : lcss[i][j - 1];
            if (A[i] == B[j])
            {
                lcss[i][j] = 1 + temp1;
            }
            else
            {
                lcss[i][j] = std::max(temp2, temp3);
            }
        }
    }

    return lcss[m - 1][n - 1];
}

int main()
{

    int A[] = {9, 7, 2, 5, 5, 5, 0, 7, 1, 6, 8, 4};
    int B[] = {1, 2, 7, 2, 6, 3, 8, 5, 3, 1, 1};
    int m   = sizeof(A) / sizeof(A[0]);
    int n   = sizeof(B) / sizeof(B[0]);
    std::cout << longestCommonSubSequence(A, m, B, n);
    return 0;
}