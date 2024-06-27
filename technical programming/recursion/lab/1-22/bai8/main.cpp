#include <iostream>

int GCD(int A, int B)
{
    if (A == 0 || B == 0)
    {
        return A + B;
    }
    if (A > B)
    {
        return GCD(A - B, B);
    }
    else
    {
        return GCD(A, B - A);
    }
}

int LCM(int A, int B)
{
    return A * B / GCD(A, B);
}

int main()
{
    std::cout << GCD(10, 8);
    return 0;
}