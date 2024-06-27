#include <iostream>

int UCLN(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return a + b;
    }
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

int BEZOUT(int a, int b)
{
    int s = 0, old_s = 1;
    int t = 1, old_t = 0;
    int r = b, old_r = a;

    while (r != 0)
    {
        int chiaNguyen = old_r / r;

        int temp = r;
        r = old_r - chiaNguyen * temp;
        old_r = temp;

        temp = s;
        s = old_s - chiaNguyen * temp;
        old_s = temp;

        temp = t;
        t = old_t - chiaNguyen * temp;
        old_t = temp;
    }

    std::cout << a << " * " << old_s << " + " << b << " * " << old_t << " = " << old_r << '\n';
}

int BCNN(int a, int b)
{
    int result = UCLN(a, b);
    return a * b / result;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << UCLN(a, b) << " " << BCNN(a, b) << '\n';
    // BEZOUT(a, b);
    return 0;
}