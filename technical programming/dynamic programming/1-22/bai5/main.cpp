#include <algorithm>
#include <iostream>

const int MAX_ARR = 10;

int findMaxPath(int map[][MAX_ARR], int h)
{
    int maxPaths[MAX_ARR][MAX_ARR] = {map[0][0]};

    for (int i = 1; i < h; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                maxPaths[i][j] = map[i][j] + maxPaths[i - 1][j];
            }
            else if (j == i)
            {
                maxPaths[i][j] = map[i][j] + maxPaths[i - 1][j - 1];
            }
            else
            {
                maxPaths[i][j] = map[i][j] + std::max(maxPaths[i - 1][j - 1], maxPaths[i - 1][j]);
            }
        }
    }

    int max = maxPaths[h - 1][0];
    for (int i = 0; i < h; i++)
    {
        if (max < maxPaths[h - 1][i])
        {
            max = maxPaths[h - 1][i];
        }
    }

    return max;
}

int main()
{
    int map[MAX_ARR][MAX_ARR] = {{1},
                                 {6, 7},
                                 {9, 5, 4},
                                 {5, 1, 4, 3},
                                 {0, 5, 7, 2, 1}};

    std::cout << findMaxPath(map, 5);

    return 0;
}