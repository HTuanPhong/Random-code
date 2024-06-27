#include <iostream>
#include <cmath>

bool kiemTraSNT(int n)
{
    if (n < 2)
    {
        return false;
    }
    bool laSNT = true;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            laSNT = false;
            break;
        }
    }
    return laSNT;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << (kiemTraSNT(n) ? "la snt" : "ko la snt") << '\n';
    for (int i = (n - 1); i >= 2; i--)
    {
        if (kiemTraSNT(i))
        {
            std::cout << i << " la snt phia truoc";
            break;
        }
    }
    return 0;
}