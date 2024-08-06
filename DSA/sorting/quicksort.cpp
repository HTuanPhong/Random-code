#include <iostream>

template <class Item>
int partition(Item a[], int l, int r) {
  int i = l - 1, j = r;
  Item v = a[r];
  while (true) {
    while (a[++i] < v);
    while (v < a[--j])
      if (j == l) break;
    if (i >= j) break;
    std::swap(a[i], a[j]);
  }
  std::swap(a[i], a[r]);
  return i;
}

template <class Item>
void quicksort(Item a[], int l, int r) {
  if (r <= l) return;
  int i = partition(a, l, r);
  quicksort(a, l, i - 1);
  quicksort(a, i + 1, r);
}
// 5 4 2 5 8 9 1 0 7 6

// template <class Item>
// int partition(Item a[], int l, int r) {
//   int mid = (l + r) / 2;
//   if (a[l] > a[mid]) std::swap(a[l], a[mid]);
//   if (a[l] > a[r]) std::swap(a[l], a[r]);
//   if (a[mid] > a[r]) std::swap(a[mid], a[r]);
//   Item v = a[mid];
//   std::swap(a[mid], a[r - 1]);

//   int i = l - 1, j = r - 1;
//   while (true) {
//     while (a[++i] < v);
//     while (v < a[--j])
//       if (j == l) break;
//     if (i >= j) break;
//     std::swap(a[i], a[j]);
//   }
//   std::swap(a[i], a[r - 1]);
//   return i;
// }


int main() {
  int a[] = {1, 1, 1, 1, 3};
  quicksort(a, 0, 12);
  for (auto &i : a) {
    std::cout << i << ' ';
  }

  return 0;
}