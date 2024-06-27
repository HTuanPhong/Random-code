#include <iostream>

int main()
{
    auto multiply = [](int a, int b)
    {
        return a * b;
    };

    int product = multiply(2, 10);

    std::cout << product;
    return 0;
}