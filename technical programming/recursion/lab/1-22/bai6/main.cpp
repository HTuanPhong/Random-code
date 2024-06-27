#include <iostream>

bool allEven(int n)
{
    if (n == 0)
    {
        return true;
    }
    return (n % 10 % 2 == 0) && allEven(n / 10);
}

int main()
{
    std::cout << allEven(-2);
    return 0;
}