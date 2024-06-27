#include <iostream>

int countHi(char arr[], int n = 0)
{
    if (arr[n] == '\0')
    {
        return 0;
    }
    int count = 0;
    if (arr[n] == 'h' && arr[n + 1] == 'i')
    {
        if (n != 0)
        {
            if (arr[n - 1] != 'x')
            {
                count = 1;
            }
        }
        else
        {
            count = 1;
        }
    }
    return countHi(arr, n + 1) + count;
}

int main()
{
    char a[] = "ahixhi";
    std::cout << countHi(a);
    return 0;
}