#include <iostream>

void deleteIndex(int *a, int &n, int k)
{
    if (k < 0 || k >= n)
    {
        return;
    }
    for (int i = k; i < n - 1; i++)
    {
        std::swap(*(a + i), *(a + i + 1));
    }
    n -= 1;
    return;
}

int main()
{
    int a[] = {1, 251, 62, 78, 9, 3, 1, 23, 4};
    int n   = sizeof(a) / sizeof(int);
    deleteIndex(a, n, 3);

    for (int i = 0; i < n; i++)
    {
        std::cout << *(a + i) << ' ';
    }

    return 0;
}