#include <algorithm>
#include <iostream>

// bottom up of recusion choose or not choose
int findClosestSum(const int w[], int n, int weightCap, int chosen[], int &m)
{
    int possibleSum[n + 1][weightCap + 1] = {}; // max sum weight table (items remain x weight left)
                                                // +1 due to taking extra 0 for base case

    for (int i = 1; i < n + 1; i++)             // start at 1 because base case at 0 alway 0 weight
    {
        for (int j = 1; j < weightCap + 1; j++) // also start at 1 after base case
        {
            if (w[i - 1] > j)
            {
                possibleSum[i][j] = possibleSum[i - 1][j];
            }
            else
            {
                int temp1         = possibleSum[i - 1][j];
                int temp2         = possibleSum[i - 1][j - w[i - 1]] + w[i - 1];
                possibleSum[i][j] = std::max(temp1, temp2);
            }
        }
    }

    m     = 0;
    int j = weightCap;
    int i = n;
    while (i > 0 && j > 0)
    {
        if (possibleSum[i][j] == possibleSum[i - 1][j])
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

    return possibleSum[n][weightCap];
}

int main()
{
    int n         = 4;
    int w[n]      = {3, 1, 3, 5};
    int chosen[n] = {};
    int m         = n;
    std::cout << findClosestSum(w, 4, 10, chosen, m);
    std::cout << '\n';
    for (int i = 0; i < m; i++)
    {
        std::cout << ' ' << chosen[i];
    }

    return 0;
}