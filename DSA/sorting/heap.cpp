#include <iostream>

template <class Item>
void heapify(Item a[], int n, int i)
{
    Item v = a[i];
    while (i < n / 2)
    {
        int child = 2 * i + 1;
        if (child < n - 1)
            if (a[child] > a[child + 1])
                child++;
        if (v >= a[child])
            break;

        a[i] = a[child];
        i    = child;
    }
    a[i] = v;
}

template <class Item>
void heapsort(Item a[], int l, int r)
{
    Item *pa = a + l;
    int   N  = r - l + 1;
    for (int k = N / 2 - 1; k >= 0; k--)
        heapify(pa, N, k);
    while (N > 1)
    {
        swap(pa[0], pa[N - 1]);
        N--;
        heapify(pa, N, 0);
    }
}

int main()
{
}