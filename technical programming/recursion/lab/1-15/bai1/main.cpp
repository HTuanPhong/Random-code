#include <iostream>

int bunnyEars(int n)
{
    if (n < 1)
    {
        return 0;
    }
    if (n == 1)
    {
        return 2;
    }
    return bunnyEars(n - 1) + ((n % 2 == 0) ? 3 : 2);
}

int main()
{
    int n;
    std::cout << "Bunnies: ";
    std::cin >> n;
    std::cout << bunnyEars(n);
    return 0;
}