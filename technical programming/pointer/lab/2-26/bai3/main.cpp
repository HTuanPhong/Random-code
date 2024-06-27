#include <algorithm>
#include <iostream>

bool checkPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void removePrime(int *&a, int &n)
{
    int primeCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkPrime(*(a + i)))
        {
            primeCount++;
        }
        else
        {
            *(a + i - primeCount) = *(a + i);
        }
    }
    int  newLength = n - primeCount;
    int *newA      = new int[newLength];

    for (int i = 0; i < newLength; i++)
    {
        *(newA + i) = *(a + i);
    }

    delete[] a;
    n = newLength;
    a = newA;
}

int main()
{
    int  n   = 8;
    int *arr = new int[n]{1, 3, 15, 6, 8, 9, 3, 1};

    removePrime(arr, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }

    return 0;
}