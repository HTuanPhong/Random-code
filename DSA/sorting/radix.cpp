#include <iostream>
using namespace std;

void radixSort(int a[], int aux[], int l, int r)
{
    int bit    = 1;
    int maxBit = a[0];
    for (int i = l; i <= r; i++)
    {
        if (maxBit < a[i])
            maxBit = a[i];
    }
    int *des = aux, *src = a;
    while (bit < maxBit)
    {
        int bitCnt = 0;
        for (int i = l; i <= r; i++)
        {
            if (!(bit & src[i]))
                des[bitCnt++] = src[i];
        }
        for (int i = l; i <= r; i++)
        {
            if (bit & src[i])
                des[bitCnt++] = src[i];
        }
        bit <<= 1;
        swap(src, des);
    }
    if (des == a)
    {
        for (int i = l; i <= r; i++)
        {
            a[i] = aux[i];
        }
    }
}

void radixSort(int a[], int aux[], int l, int r)
{
}

int main()
{
    int a[] = {9, 1, 3, 2, 5, 6};
    int b[6];

    radixSort(a, b, 0, 5);
    for (auto &i : a)
    {
        std::cout << i << ' ';
    }
    return 0;
}