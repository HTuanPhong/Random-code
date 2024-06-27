#include <iostream>

int main()
{
    int h;
    std::cin >> h;
    for (int i = 1; i <= h; i++)
    {
        for (int l = 1; l <= (h - i); l++)
        {
            std::cout << ' ';
        }
        for (int m = 1; m <= 2 * i - 1; m++)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
    return 0;
}