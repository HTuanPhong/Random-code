#include <iostream>

const int MAX_ARR = 10;

int solution(int map[MAX_ARR][MAX_ARR], int m, int n)
{
    int possiblePaths[MAX_ARR][MAX_ARR] = {1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1)
            {
                possiblePaths[i][j] = 0;
            }
            else if (i == 0 || j == 0)
            {
                possiblePaths[i][j] = 1;
            }
            else
            {
                possiblePaths[i][j] = possiblePaths[i - 1][j] + possiblePaths[i][j - 1];
            }
        }
    }
    return possiblePaths[n - 1][m - 1];
}

int main()
{
    int map[MAX_ARR][MAX_ARR] = {{0, 0, 0},
                                 {0, 1, 0},
                                 {0, 0, 0}};
    int m = 3, n = 3;
    std::cout << solution(map, m, n);
    return 0;
}