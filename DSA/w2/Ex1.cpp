#include <chrono>
#include <iostream>
#include <random>

void insertion(int a[], int l, int r)
{
    int v;
    for (int i = l + 1; i <= r; i++)
    {
        v = a[i];
        int j;
        for (j = i; j > l && v < a[j - 1]; j--)
            a[j] = a[j - 1];
        a[j] = v;
    }
}

int partition(int a[], int l, int r)
{
    int mid = (l + r) / 2;
    if (a[l] > a[mid])
        std::swap(a[l], a[mid]);
    if (a[l] > a[r])
        std::swap(a[l], a[r]);
    if (a[mid] > a[r])
        std::swap(a[mid], a[r]);
    int v = a[mid];
    std::swap(a[mid], a[r - 1]);

    int i = l - 1, j = r - 1;
    while (true)
    {
        while (a[++i] < v)
            ;
        while (v < a[--j])
            if (j == l)
                break;
        if (i >= j)
            break;
        std::swap(a[i], a[j]);
    }
    std::swap(a[i], a[r - 1]);
    return i;
}

void quicksort(int a[], int l, int r)
{
    if (r <= l)
        return;
    int i = partition(a, l, r);
    quicksort(a, l, i - 1);
    quicksort(a, i + 1, r);
}

void merge(int a[], int aux[], int l, int m, int r)
{
    int i, j, k;
    i = l;
    j = m + 1;
    k = l;
    while (i <= m && j <= r)
        if (aux[i] <= aux[j])
            a[k++] = aux[i++];
        else
            a[k++] = aux[j++];
    while (i <= m)
        a[k++] = aux[i++];
    while (j <= r)
        a[k++] = aux[j++];
}

void mergesort(int a[], int aux[], int l, int r)
{
    int *real = a;
    int *fake = aux;
    for (int sz = 1; sz <= r - l; sz = sz + sz)
    {
        for (int i = l; i <= r - sz; i += sz + sz)
        {
            merge(fake, real, i, i + sz - 1, std::min(i + sz + sz - 1, r));
        }
        std::swap(real, fake);
    }
    if (fake == a)
    {
        for (int k = l; k <= r; k++)
            a[k] = aux[k];
    }
}

int main()
{
    std::random_device dev;
    std::mt19937       rng(dev());

    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 100); // distribution in range [1, 50]

    int a[10000];
    for (int i = 0; i < 10000; i++)
    {
        a[i] = dist(rng);
    }

    auto start = std::chrono::high_resolution_clock::now();
    insertion(a, 0, 9999);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end - start;
    std::cout << "Time to insertion sort " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    quicksort(a, 0, 9999);
    end = std::chrono::high_resolution_clock::now();

    diff = end - start;
    std::cout << "Time to quick sort (median of 3)" << diff.count() << " s\n";

    int aux[10000];
    start = std::chrono::high_resolution_clock::now();
    mergesort(a, aux, 0, 9999);
    end = std::chrono::high_resolution_clock::now();

    diff = end - start;
    std::cout << "Time to merge sort " << diff.count() << " s\n";

    return 0;
}