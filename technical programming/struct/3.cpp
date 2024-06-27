#include <iostream>

struct Fraction
{
    int num; // numerator
    int den; // denominator
};

struct Mixed
{
    int whole;
    Fraction frac;
};

void print(Fraction frac)
{
    std::cout << frac.num << '/';
    std::cout << frac.den;
}

void print(Mixed mix)
{
    std::cout << mix.whole;
    if (mix.frac.num != 0)
    {
        std::cout << '_';
        print(mix.frac);
    }
}

void print(Mixed mix[], int n)
{
    std::cout << "{ ";
    for (int i = 0; i < n - 1; i++)
    {
        print(mix[i]);
        std::cout << ", ";
    }
    print(mix[n - 1]);
    std::cout << " }";
}

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
    int gcdResult = gcd(a.num, a.den);
    a.num /= gcdResult;
    a.den /= gcdResult;
    if (a.den < 0)
    {
        a.num = -a.num;
        a.den = -a.den;
    }
    return a;
}

Fraction sum(Fraction a, Fraction b)
{
    Fraction result;
    result.num = a.num * b.den + b.num * a.den;
    result.den = a.den * b.den;
    return result;
}

Mixed sum(Mixed a, Mixed b)
{
    Mixed result;
    Fraction sumFrac = toStandardForm(sum(a.frac, b.frac));
    result.whole = a.whole + b.whole + sumFrac.num / sumFrac.den;
    result.frac.num = sumFrac.num % sumFrac.den;
    result.frac.den = sumFrac.den;
    return result;
}

int compare(Fraction a, Fraction b)
{
    if (a.num * b.den > a.den * b.num)
        return 1; // a > b
    if (a.num * b.den < a.den * b.num)
        return -1; // a < b;
    return 0;      // a = b
}

int compare(Mixed a, Mixed b)
{
    if (a.whole > b.whole)
        return 1; // a > b
    if (a.whole < b.whole)
        return -1; // a < b
    int compareFrac = compare(a.frac, b.frac);
    if (compareFrac == 1)
        return 1; // a > b
    if (compareFrac == -1)
        return -1; // a < b
    return 0;
}

Mixed findMaxMixedArray(Mixed mix[], int n)
{
    Mixed max = mix[0];
    for (int i = 1; i < n; i++)
    {
        if (compare(max, mix[i]) == -1)
        {
            max = mix[i];
        }
    }
    return max;
}

Mixed sumMixedArray(Mixed mix[], int n)
{
    Mixed result = {0, {0, 1}};
    for (int i = 0; i < n; i++)
    {
        result = sum(result, mix[i]);
    }
    return result;
}

void sortMixedArrayIncreasing(Mixed mix[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (compare(mix[j], mix[i]) == -1)
            {
                Mixed temp = mix[i];
                mix[i] = mix[j];
                mix[j] = temp;
            }
        }
    }
}

void getMixedArrayInput(Mixed a[], int &n)
{
    std::cout << "Mixed array length: ";
    std::cin >> n;
    std::cout << "enter whole, numerator, denominator" << '\n';
    for (int i = 0; i < n; i++)
    {
        do
        {
            std::cout << "mix[" << i << "] = ";
            std::cin >> a[i].whole >> a[i].frac.num >> a[i].frac.den;
        } while (a[i].whole < 1 || a[i].frac.num >= a[i].frac.den ||
                 a[i].frac.num < 1 || a[i].frac.den < 1);
    }
}

int main()
{
    Mixed mix[100];
    int n;
    getMixedArrayInput(mix, n);
    std::cout << '\n' << "Sum: ";
    print(sumMixedArray(mix, n));
    std::cout << '\n' << "Max: ";
    print(findMaxMixedArray(mix, n));
    std::cout << '\n' << "Increasing order: ";
    sortMixedArrayIncreasing(mix, n);
    print(mix, n);
    return 0;
}