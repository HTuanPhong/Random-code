#include <iostream>

int main()
{
    int n, amount = 0, sum = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            std::cout << i << ", ";
            amount++;
            sum += i;
        }
    }
    std::cout << '\n'
              << amount << '\n'
              << sum;
    return 0;
}