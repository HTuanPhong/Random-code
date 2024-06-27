#include <iostream>

void insertion(int a[], int n)
{
    int v;
    for (int i = 1; i < n; i++)
    {
        v = a[i];
        int j;
        for (j = i; j > 0 && v > a[j - 1]; j--)
            a[j] = a[j - 1];
        a[j] = v;
    }
}

void sort(int a[][4], int w, int h)
{
    int *a1D = new int[w * h];
    int  c   = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            a1D[c++] = a[i][j];
        }
    }

    insertion(a1D, c);

    int i, k = 0, l = 0;
    int m = h, n = w;
    while (k < m && l < n)
    {
        for (i = l; i < n; ++i)
        {
            a[k][i] = a1D[--c];
        }
        k++;

        for (i = k; i < m; ++i)
        {
            a[i][n - 1] = a1D[--c];
        }
        n--;

        if (k < m)
        {
            for (i = n - 1; i >= l; --i)
            {
                a[m - 1][i] = a1D[--c];
            }
            m--;
        }

        if (l < n)
        {
            for (i = m - 1; i >= k; --i)
            {
                a[i][l] = a1D[--c];
            }
            l++;
        }
    }
}

int main()
{
    int maxtrix[4][4] = {{15, 14, 13, 12},
                         {11, 10, 9, 8},
                         {4, 5, 6, 7},
                         {3, 2, 1, 0}};

    sort(maxtrix, 4, 4);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << maxtrix[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}