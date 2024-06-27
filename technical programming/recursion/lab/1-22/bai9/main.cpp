#include <iostream>

int reverse(int n, int result = 0)
{
    if (n == 0)
    {
        return result;
    }
    return reverse(n / 10, result * 10 + n % 10);
}

int main()
{
    std::cout << reverse(123);
    return 0;
}