#include <iostream>

int *combineArray(int *a, int n, int *b, int m)
{
    int *c = new int[n + m];
    int  k = 0;
    for (int i = 0; i < n; i++)
    {
        *(c + k++) = *(a + i);
    }
    for (int i = 0; i < m; i++)
    {
        *(c + k++) = *(b + i);
    }
    return c;
}

int main()
{
    int  n = 3;
    int *a = new int[n]{5, 6, 7};
    int  m = 4;
    int *b = new int[m]{1, 2, 3, 4};
    int *c = combineArray(a, n, b, m);

    for (int i = 0; i < n + m; i++)
    {
        std::cout << c[i] << ' ';
    }
    return 0;
}