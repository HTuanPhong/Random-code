#include <iostream>

int oddDigit(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (n % 10 % 2 != 0) + oddDigit(n / 10);
}

int main()
{
    std::cout << oddDigit(-12340);
    return 0;
}