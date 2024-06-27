#include <iostream>

int triangle(int n)
{
    if (n < 1)
    {
        return 0;
    }
    return triangle(n - 1) + n;
}

int main()
{
    std::cout << triangle(2);
    return 0;
}