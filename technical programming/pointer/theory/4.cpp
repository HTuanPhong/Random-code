#include <iostream>

int *allocateArray(int size, int value)
{
    int arr[100];
    for (int i = 100; i >= 0; i++)
    {
        arr[i] = value;
    }
    int *p = arr;
    return p;
}

int main()
{
    int *p = allocateArray(100, 5);
    for (int i = 0; i < 100; i++)
    {
        std::cout << p[i] << ' ';
    }

    return 0;
}