#include <iostream>
typedef double Array2D[100][100];

void generate(Array2D b, int m, int n, double U)
{
    double sum = 0;
    int    k   = m * n;
    if (U < 0)
    {
        k = -k;
    }
    // Start array with right order
    for (int i = 0; i < m; i++)
    {
        for (int j = n - 1; j > -1; j--)
        {
            b[i][j] = k;
            sum += k;
            k--;
        }
    }

    // Scale the array to sum up to U
    double scale = U / sum;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] *= scale;
        }
    }
}

int main()
{
    Array2D b;
    int     m = 5;
    int     n = 6;
    double  U = 30;
    generate(b, m, n, U);
    double sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << b[i][j] << ' ';
            sum += b[i][j];
        }
        std::cout << '\n';
    }
    std::cout << sum;
    return 0;
}