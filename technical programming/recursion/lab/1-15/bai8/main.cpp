#include <iostream>

int maxCandy(int money, int price, int wrapRequired, int candy = 0, int wrap = 0)
{
    if (money)
    {
        candy = money / price;
        wrap  = candy;
        money = 0;
    }
    else
    {
        int newCandy = wrap / wrapRequired;
        candy += newCandy;
        wrap = newCandy + wrap % wrapRequired;
    }
    if (wrap < wrapRequired)
    {
        return candy;
    }
    return maxCandy(money, price, wrapRequired, candy, wrap);
}

int main()
{
    std::cout << maxCandy(20, 3, 5);
    return 0;
}