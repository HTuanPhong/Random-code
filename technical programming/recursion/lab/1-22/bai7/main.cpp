#include <iostream>

int numberOfCommonDivisors(int A, int B, int cd = 1)
{
    if (A < 0)
    {
        A *= -1;
    }
    if (B < 0)
    {
        B *= -1;
    }
    if (cd > A || cd > B)
    {
        return 0;
    }
    return (A % cd == 0 && B % cd == 0) + numberOfCommonDivisors(A, B, cd + 1);
}

int main()
{
    std::cout << numberOfCommonDivisors(8, -4);
    return 0;
}