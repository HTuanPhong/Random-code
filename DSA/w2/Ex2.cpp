#include <iostream>

void sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        if ((a[i] % 2) != 0)
        {
            int max = i;
            for (int j = i + 1; j < n; j++)
            {
                if ((a[j] % 2 != 0) && a[j] > a[max])
                {
                    max = j;
                }
            }
            std::swap(a[i], a[max]);
        }

        if (a[i] % 2 == 0)
        {
            int min = i;
            for (int j = i + 1; j < n; j++)
            {
                if ((a[j] % 2 == 0) && a[j] < a[min])
                {
                    min = j;
                }
            }
            std::swap(a[i], a[min]);
        }
    }
}

int main()
{
    int a[] = {1, 2, 4, 7, 15, 18, 8, 9, 11};
    sort(a, 9);
    for (auto &i : a)
    {
        std::cout << i << ' ';
    }

    return 0;
}