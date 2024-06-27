#include <iostream>

template <class Item>
void insertion(Item a[], int l, int r)
{
    Item v;
    for (int i = l + 1; i <= r; i++)
    {
        v = a[i];
        int j;
        for (j = i; j > l && v < a[j - 1]; j--)
            a[j] = a[j - 1];
        a[j] = v;
    }
}

int main()
{
    int a[] = {1, 2, 312, 56, 17, 8, 9, 22, 9, 3, 950, 30, 1};
    insertion(a, 0, 12);
    for (auto &i : a)
    {
        std::cout << i << ' ';
    }

    return 0;
}