#include <iostream>

int main()
{
    int n, sum = 0, factorial = 1;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
        sum += factorial;
    }
    std::cout << sum;
    return 0;
}