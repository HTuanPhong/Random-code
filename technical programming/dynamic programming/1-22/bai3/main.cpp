#include <iostream>

int findClosestVal(const int w[], int n, const int v[], int weightCap, int chosen[], int &m)
{
    int possibleValue[n + 1][weightCap + 1] = {};

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < weightCap + 1; j++)
        {
            if (w[i - 1] > j)
            {
                possibleValue[i][j] = possibleValue[i - 1][j];
            }
            else
            {
                int temp1           = possibleValue[i - 1][j];
                int temp2           = possibleValue[i - 1][j - w[i - 1]] + v[i - 1];
                possibleValue[i][j] = std::max(temp1, temp2);
            }
        }
    }

    m     = 0;
    int j = weightCap;
    int i = n;
    while (i > 0 && j > 0)
    {
        if (possibleValue[i][j] == possibleValue[i - 1][j])
        {
            i--;
            continue;
        }
        else
        {
            chosen[m++] = w[i - 1];
            j -= w[i - 1];
            i--;
        }
    }

    return possibleValue[n][weightCap];
}

int main()
{
    int w[] = {3, 1, 3, 5};
    int n   = sizeof(w) / sizeof(w[0]);
    int v[] = {9, 3, 6, 4};
    int chosen[n];
    int weightCap = 10;
    int m         = n;
    std::cout << findClosestVal(w, n, v, weightCap, chosen, m);
    std::cout << '\n';
    for (int i = 0; i < m; i++)
    {
        std::cout << ' ' << chosen[i];
    }
    return 0;
}