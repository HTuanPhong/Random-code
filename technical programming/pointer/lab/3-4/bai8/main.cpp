#include <iostream>

void swap_by_ptr(int *a, int *b)
{
    int t = *a;
    *a    = *b;
    *b    = t;
}

void swap_by_ref(int &a, int &b)
{
    int t = a;
    a     = b;
    b     = t;
}

void swap_ptr_by_ref(int *&a, int *&b)
{
    int t = *a;
    *a    = *b;
    *b    = t;
}

int main()
{
    int a = 2;
    int b = 4;
    swap_by_ptr(&a, &b);
    std::cout << a << ' ' << b << '\n';
    swap_by_ref(a, b);
    std::cout << a << ' ' << b << '\n';
    int *pa = &a;
    int *pb = &b;
    swap_ptr_by_ref(pa, pb);
    std::cout << a << ' ' << b << ' ';
    return 0;
}