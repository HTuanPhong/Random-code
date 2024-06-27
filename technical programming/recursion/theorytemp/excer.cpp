#include <iostream>

int sumOdd(int n)
{
    if (n == 0)
        return 1;
    else
        return sumOdd(n - 1) + (2 * n + 1);
}

int Bai9(int n)
{
    if (n == 1)
        return 1;
    else
        return Bai9(n - 1) + n * (n % 2 == 0 ? -1 : 1);
}

int fibo(int n)
{
    int f0 = 1, f1 = 1, fn = 1;
    for (int i = 2; i <= n; i++)
    {
        fn = f1 + f0;
        f0 = f1;
        f1 = fn;
    }
    return fn;
}

int max(int a[], int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

int ma1x(int a[], int n)
{
    if (n == 1)
        return a[0];
    else
        return max(a, n - 1) > max(a, n) ? a[n - 1] : a[n];
}

int gcd(int a, int b)
{
    if (a == 0 || b == 0)
        return a + b;
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{

    return 0;
}