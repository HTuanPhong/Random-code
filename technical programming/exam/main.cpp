#include <iostream>

int *findLargestTotalSubarray(int *a, int n, int &total, int &length)
{
    total    = a[0];
    length   = 1;
    int *res = a;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum > total)
            {
                total  = sum;
                a      = &a[i];
                length = j - i + 1;
            }
        }
    }
    return res;
}

int **concatenate2MatricesH(int **a, int **b, int length, int width)
{
    int **res = new int *[length];
    for (int i = 0; i < length; i++)
    {
        res[i] = new int[width * 2];
        for (int j = 0; j < width; j++)
        {
            res[i][j] = a[i][j];
        }
        for (int j = 0; j < width; j++)
        {
            res[i][j + width] = b[i][j];
        }
    }
    return res;
}

void sortColumns(int **matrix, int m)
{
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int k = i; k < m; k++)
            {
                if (*(*(matrix + i) + j) > *(*(matrix + k) + j))
                {
                    int temp             = *(*(matrix + i) + j);
                    *(*(matrix + i) + j) = *(*(matrix + k) + j);
                    *(*(matrix + k) + j) = temp;
                }
            }
        }
    }
}

bool isDivisibleBy3And5(int number)
{
    if (number == 0)
    {
        return true;
    }
    if (number < 0)
    {
        return false;
    }
    return isDivisibleBy3And5(number - 15);
}

int coinChange(int *money, int n, int amount)
{
    int ways[100] = {1};
    for (int i = 1; i < amount + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - money[j] >= 0)
            {
                ways[i] += ways[i - money[j]];
            }
            if (i - money[j] < money[j])
            {
                ways[i] -= ways[i - money[j]];
            }
        }
    }

    for (int i = 0; i <= amount; i++)
    {
        std::cout << ways[i] << ' ';
    }

    return ways[amount];
}

int main()
{
    int a[] = {1, 2, 5};
    std::cout << coinChange(a, 3, 5);
    // int  a[] = {1, 2, 3, -4, 5, -6};
    // int  total, length;
    // int *b = findLargestTotalSubarray(a, sizeof(a) / sizeof(int), total, length);
    // std::cout << total << '\n';
    // for (int i = 0; i < length; i++)
    // {
    //     std::cout << b[i] << ' ';
    // }

    // int **a = new int *[3];
    // int **b = new int *[3];

    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         *(*(a + i) + j) = i + j;
    //         *(*(b + i) + j) = i + j;
    //     }
    // }
    // a[0] = new int[3]{9, 8, 7};
    // a[1] = new int[3]{6, 5, 4};
    // a[2] = new int[3]{3, 2, 1};
    // b[0] = new int[3]{3, 2, 1};
    // b[1] = new int[3]{6, 5, 4};
    // b[2] = new int[3]{9, 8, 7};
    // sortColumns(a, 3);

    // int **c = concatenate2MatricesH(a, b, 3, 3);

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3 * 2; j++)
    //     {
    //         std::cout << c[i][j] << ' ';
    //     }
    //     std::cout << '\n';
    // }

    // std::cout << isDivisibleBy3And5(30);
    return 0;
}