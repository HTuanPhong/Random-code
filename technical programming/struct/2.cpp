/**
 * Description:
 *          CSC10001 Struct homework
 *          chương trình cộng hai phân số
 *
 * Original Author:    H.T.Phong
 * Created:   Dec 1, 2023
 *
 **/

#include <iostream>

struct Fraction
{
    int numerator;
    int denominator;
};

int gcd(int a, int b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
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

Fraction toStandardForm(Fraction a)
{
    int gcdResult = gcd(a.numerator, a.denominator);
    a.numerator /= gcdResult;
    a.denominator /= gcdResult;
    if (a.denominator < 0)
    {
        a.numerator = -a.numerator;
        a.denominator = -a.denominator;
    }
    return a;
}

Fraction sumTwoFraction(const Fraction a, const Fraction b)
{
    Fraction result;
    result.numerator =
        a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return toStandardForm(result);
}

void getFractionArrayInput(Fraction a[], int &n)
{
    std::cout << "rArray amount: ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        do
        {
            std::cout << "rArray[" << i << "] = ";
            std::cin >> a[i].numerator >> a[i].denominator;
        } while (a[i].denominator == 0);
    }
}

Fraction findMinFraction(const Fraction a[], int n)
{
    Fraction min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i].numerator * min.denominator < a[i].denominator * min.numerator)
        {
            min = a[i];
        }
    }
    return min;
}

int main()
{
    int n;
    Fraction a[100];
    getFractionArrayInput(a, n);
    Fraction min = findMinFraction(a, n);
    std::cout << min.numerator << "/" << min.denominator;
    return 0;
}