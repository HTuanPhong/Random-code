#include <iostream>

void addIndex(int *&a, int &n, int k, int num)
{
    if (k < 0 || k > n)
    {
        return;
    }
    n++;
    int *newArray = new int[n];

    for (int i = 0; i < k; i++)
    {

        *(newArray + i) = *(a + i);
    }
    *(newArray + k) = num;
    for (int i = k + 1; i < n; i++)
    {
        *(newArray + i) = *(a + i - 1);
    }

    delete[] a;
    a = newArray;
}

int main()
{
    int n = 8;

    int *arr = new int[n]{1, 3, 15, 6, 8, 9, 3, 1};

    addIndex(arr, n, 0, 100);
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
    return 0;
}