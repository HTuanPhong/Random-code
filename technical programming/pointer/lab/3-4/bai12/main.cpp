#include <iostream>

char *ex8(char *pc)
{
    return pc;
}

float *ex9(int *pi)
{
    float *re = new float; // or static
    *re       = *pi;
    return re;
}

void ex10(int *pi)
{
    if (*pi % 2)
    {
        std::cout << "odd";
        return;
    }
    std::cout << "even";
}

void cf()
{
    std::cout << "Catfish";
}

void cn()
{
    std::cout << "chrisname";
}

void dr()
{
    std::cout << "devonrevenge";
}

int main()
{
    char  *ex1;
    char **ex2;
    char  *ex3[10];
    char(*ex4)[30];
    char(*ex5[10])[500];
    int const *ex6;
    const int *ex7;

    int choices;
    void (*pf[3])() = {cf, cn, dr};
    while (choices > 3 || choices < 1)
    {
        std::cin >> choices;
    }
    pf[choices - 1]();
    return 0;
}