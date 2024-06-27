#include <iostream>

struct Test
{
    int ar[10];
};

int main()
{
    Test a = {1, 2, 3};
    Test b;
    b = a;
    a.ar[1] = 5;
    std::cout << b.ar[1];
}
