#include <iostream>

void generate(double *a, int n, double U)
{
    double div = U / n; // div equally for each element
    for (int i = 0; i < n; i++)
    {
        a[i] = div;                    // every element is now equal and sum up to U
    }
    for (int i = 0; i < n - 1; i += 2) // even element loop
    {
        a[i] += 1;                     // offset even value to be larger than next one
        a[i + 1] -= 1;                 // odd will be adjusted to maintain total sum
    }
}

int main()
{
    int    n    = 5;
    double a[n] = {};
    double sums = -3.5;
    generate(a, n, sums);
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << ' ';
        sum += a[i];
    }
    std::cout << '\n'
              << sum;
}