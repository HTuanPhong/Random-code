#include <iostream>

int toBinary(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n % 2 + 10 * toBinary(n / 2);
}

int main()
{
    std::cout << toBinary(123);
    return 0;
}