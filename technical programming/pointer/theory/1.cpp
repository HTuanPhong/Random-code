#include <iostream>

void mySort(int a[], int n)
{
    int *arrEnd = a + n;
    for (int *i = a; i < arrEnd - 1; i++)
        for (int *j = i + 1; j < arrEnd; j++)
            if (*i > *j)
                std::swap(*i, *j);
}

void sortArray(int a[], int n)
{
    int *arrEnd = a + n;
    bool odd    = false;
    for (int *i = a; i < arrEnd - 1; i++)
    {
        odd = !odd;
        for (int *j = i + 1; j < arrEnd; j++)
        {
            if (odd)
            {
                if (*i < *j)
                    std::swap(*i, *j);
            }
            else if (*i > *j)
                std::swap(*i, *j);
        }
    }
}

int main()
{
    int a[7] = {20, 50, 60, 10, 40, 30, 70};
    sortArray(a, 7);

    for (int i = 0; i < 7; i++)
        std::cout << a[i] << ' ';
    return 0;
}