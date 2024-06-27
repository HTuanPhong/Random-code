#include <iostream>
typedef double Array2D[100][100];

double cal4a(Array2D b, int m, int n, double x, double y)
{
    double sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double powX = 1;
            for (int k = 0; k < i; k++)
            {
                powX *= x;
            }
            double powY = 1;
            for (int k = 0; k < j; k++)
            {
                powY *= y;
            }
            sum += b[i][j] * powX * powY;
        }
    }
    return sum;
}

double cal4b(Array2D b, int m, int n, double x, double y, int i = 0, int j = 0)
{
    if (i >= m || j >= n)
    {
        return 0.0;
    }

    double powX = 1.0;
    for (int k = 0; k < i; k++)
    {
        powX *= x;
    }

    double powY = 1.0;
    for (int k = 0; k < j; k++)
    {
        powY *= y;
    }

    double currentTerm = b[i][j] * powX * powY;

    double sum = cal4b(b, m, n, x, y, i + 1, j) + cal4b(b, m, n, x, y, i, j + 1) - cal4b(b, m, n, x, y, i + 1, j + 1) + currentTerm;

    return sum;
}

double cal4c(Array2D b, int m, int n, double x, double y)
{
    double sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double powX = 1;
            for (int k = 0; k < i; k++)
            {
                powX *= x;
            }
            double powY = 1;
            for (int k = 0; k < j; k++)
            {
                powY *= y;
            }
            sum += *(*(b + i) + j) * powX * powY;
        }
    }
    return sum;
}

int main()
{
    int     m = 2;
    int     n = 3;
    int     x = 2;
    int     y = 7;
    Array2D b = {{1, 2, 3},
                 {4, 5, 6}};
    std::cout << cal4a(b, m, n, x, y);
    std::cout << '\n';
    std::cout << cal4c(b, m, n, x, y);
    std::cout << '\n';
    std::cout << cal4b(b, m, n, x, y);
    return 0;
}