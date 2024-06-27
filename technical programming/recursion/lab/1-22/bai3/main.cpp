#include <iostream>

float pow(int x, unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    return x * pow(x, n - 1);
}

int main()
{
    std::cout << pow(2, -3);
    return 0;
}