#include <iostream>

void sapTang(int a[][5], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < m; l++)
                {
                    if (a[i][j] < a[k][l])
                    {
                        std::swap(a[i][j], a[k][l]);
                    }
                }
            }
        }
    }
}

int main()
{
    int a[4][5] = {{2, 3, 5, 61, 5},
                   {1, 2, 3, 4, 5},
                   {6, 1, 24, 5, 5},
                   {90, 24, 512, 6, 0}};
    sapTang(a, 4, 5);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << a[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}