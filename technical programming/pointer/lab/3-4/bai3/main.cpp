#include <iostream>

int findMaxInArrayOfIntPointer(int **a, int n)
{
    int max = *a[0];
    for (int i = 0; i < n; i++)
    {
        if (max < *a[i])
        {
            max = *a[i];
        }
    }
    return max;
}

int main()
{
    int   n      = 5;
    int   a[n]   = {5, 2, 4, 9, 100};
    int **parray = new int *[n];
    for (int i = 0; i < n; i++)
    {
        parray[i] = &a[i];
    }
    std::cout << findMaxInArrayOfIntPointer(parray, n);
    return 0;
}