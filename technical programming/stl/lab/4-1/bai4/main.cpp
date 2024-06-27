#include <algorithm>
#include <iostream>
#include <vector>

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (!(n % i))
        {
            return false;
        }
    }
    return true;
}

void printPrime(int n)
{
    if (isPrime(n))
    {
        std::cout << n << ' ';
    }
}

int main()
{
    int n;
    std::cout << "Enter number: ";
    std::cin >> n;
    std::vector<int> vec;
    for (int i = 2; i <= n; i++)
    {
        vec.push_back(i);
    }
    std::for_each(vec.cbegin(), vec.cend(), printPrime);
    return 0;
}