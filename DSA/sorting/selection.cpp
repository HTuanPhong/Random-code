#include <algorithm>
#include <iostream>

template <typename T>
void selectionSort(T a[], int l, int r)
{
    for (int i = l; i < r; i++)
    {
        int min = i;
        for (int j = i + 1; j <= r; j++)
            if (a[j] < a[min])
                min = j;
        std::swap(a[i], a[min]);
    }
}

int main()
{
    int a[] = {1, 2, 312, 56, 17, 8, 9, 22, 9, 3, 950, 30, 1};
    selectionSort(a, 0, 12);
    for (auto &i : a)
    {
        std::cout << i << ' ';
    }

    return 0;
}