#include <iostream>

void sort(int *a, int n, bool (*comp)(int, int))
{
    int *bound = a + (n - 1);
    for (int i = 0; i < n; i++)
    {
        for (int *p = a; p < bound; ++p)
        {
            if (!comp(*p, *(p + 1)))
            {
                int t    = *p;
                *p       = *(p + 1);
                *(p + 1) = t;
            }
        }
    }
}

bool ascending(int a, int b)
{
    return a < b;
}

bool descending(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    std::cout << "array size: ";
    std::cin >> n;
    int *a = new int[n];
    std::cout << "enter array: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::cout << "1 for ascending, 2 for descending: ";

    int choice;
    while (choice > 2 || choice < 1)
    {
        std::cin >> choice;
    }
    bool (*comp)(int, int);
    switch (choice)
    {
    case 1:
        comp = ascending;
        break;
    case 2:
        comp = descending;
        break;
    }

    sort(a, n, comp);
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << ' ';
    }

    return 0;
}