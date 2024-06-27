#include <iostream>

int main()
{
    int  n = 10;
    int *a = new int[n];
    for (int *p = a; p < a + n; p++)
    {
        *p = 0;
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i];
    }
    return 0;
}