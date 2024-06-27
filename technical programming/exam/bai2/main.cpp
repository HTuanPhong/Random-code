#include <cmath>
#include <iostream>

double calculate2a(double *a, int n, double x)
{
    double sum = a[0];
    double pow = x;
    for (int i = 1; i < n; i++)
    {
        sum += a[i] * pow;
        pow *= x;
    }
    return sum;
}

double calculate2b(double *a, int n, double x)
{
    if (n == 0)
    {
        return a[0];
    }
    else
    {
        double term = a[n];
        for (int i = 0; i < n; i++)
        {
            term *= x;
        }
        return term + calculate2b(a, n - 1, x);
    }
}

double calculate2c(double *a, int n, double x)
{
    double sum = *a;
    double pow = x;
    for (double *p = a + 1; p < a + n; p++)
    {
        sum += *p * pow;
        pow *= x;
    }
    return sum;
}

int main()
{
    int    n    = 5;
    double a[n] = {5, 2, 3, 4, 5};
    std::cout << calculate2a(a, n, 2);
    std::cout << '\n';
    std::cout << calculate2c(a, n, 2);
    std::cout << '\n';
    std::cout << calculate2b(a, n, 2);
    return 0;
}