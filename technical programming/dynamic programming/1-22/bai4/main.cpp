#include <algorithm>
#include <iostream>

int findMaxPath(int map[][10], int m, int n)
{
    int maxPaths[m][n] = {};
    for (int i = 0; i < m; i++)
    {
        maxPaths[i][0] = map[i][0]; // base cases
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            if (i == 0)
            {
                maxPaths[i][j] = map[i][j] + std::max(maxPaths[i][j - 1], maxPaths[i + 1][j - 1]);
            }
            else if (i == m - 1)
            {
                maxPaths[i][j] = map[i][j] + std::max(maxPaths[i - 1][j - 1], maxPaths[i][j - 1]);
            }
            else
            {
                maxPaths[i][j] = map[i][j] + std::max({maxPaths[i - 1][j - 1], maxPaths[i][j - 1],
                                                       maxPaths[i + 1][j - 1]});
            }
        }
    }

    int max = maxPaths[0][n - 1];
    for (int i = 0; i < m; i++)
    {
        if (max < maxPaths[i][n - 1])
        {
            max = maxPaths[i][n - 1];
        }
    }

    return max;
}

int main()
{
    int map[][10] = {{8, 9, 7, 5, 6, 4, 5, 6, 7, 6},
                     {7, 9, 5, 6, 3, 2, 1, 4, 56, 3},
                     {5, 4, 6, 9, 8, 7, 5, 6, 1, 5},
                     {4, 7, 9, 3, 1, 5, 6, 7, 9, 8}};

    int m = 4;
    int n = 10;
    std::cout << findMaxPath(map, m, n);
    return 0;
}