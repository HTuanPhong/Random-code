#include <iostream>

int countDigit(int n)
{
    if (n < 0)
    {
        n *= -1;
    }
    if (n < 10)
    {
        return 1;
    }
    return 1 + countDigit(n / 10);
}

int main()
{
    std::cout << countDigit(10);
    return 0;
}