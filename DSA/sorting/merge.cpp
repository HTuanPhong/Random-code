#include <algorithm>
#include <iostream>
using namespace std;

template <class Item>
void merge(Item a[], Item aux[], int l, int m, int r) {
  int i = l, j = m + 1, k = l;
  while (i <= m && j <= r) {
    if (aux[i] <= aux[j])
      a[k++] = aux[i++];
    else
      a[k++] = aux[j++];
  }
  while (i <= m) a[k++] = aux[i++];
  while (j <= r) a[k++] = aux[j++];
}

template <class Item>
void mergesort(Item a[], Item aux[], int l, int r) {
  Item *real = a;
  Item *fake = aux;
  for (int sz = 1; sz <= r - l; sz += sz) {
    int i;
    for (i = l; i <= r - sz; i += sz + sz) {
      merge(fake, real, i, i + sz - 1, std::min(i + sz + sz - 1, r));
    }
    i -= sz + sz;
    while (i <= r) {
      fake[i] = real[i++];
    }
    std::swap(real, fake);
  }
  if (fake == a) {
    for (int k = l; k <= r; k++) a[k] = aux[k];
  }
}

// template <class Item>
// void merge(Item a[], Item aux[], int l, int m, int r) {
//   int i, j, k;
//   for (k = l; k <= r; k++) aux[k] = a[k];
//   i = l;
//   j = m + 1;
//   k = l;
//   while (i <= m && j <= r)
//     if (aux[i] <= aux[j])
//       a[k++] = aux[i++];
//     else
//       a[k++] = aux[j++];
//   while (i <= m) a[k++] = aux[i++];
//   while (j <= r) a[k++] = aux[j++];
// }

// template <class Item>
// void mergesort(Item a[], Item aux[], int l, int r) {
//   if (r <= l) return;
//   int m = (l + r) / 2;
//   mergesort(a, aux, l, m);
//   mergesort(a, aux, m + 1, r);
//   merge(a, aux, l, m, r);
// }

int main() {
  // int a[25] = {2005, 2001, 2001, 2000, 2000, 1996, 1996, 1995, 1995, 1995,
  // 1991, 1990, 1990, 1988, 1988, 1984, 1983, 1982, 1977, 1977, 1968, 1967,
  // 1965, 1965, 1956}; int b[25] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
  // 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};
  int a[3] = {5, 4, 3};
  int b[3] = {10, 10, 10};
  mergesort(a, b, 0, 3);
  for (auto &i : a) {
    std::cout << i << ' ';
  }
}