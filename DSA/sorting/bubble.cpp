#include <iostream>

template <class Item>
void bubble(Item a[], int l, int r) {
  for (int i = l; i < r; i++)
    for (int j = r; j > i; j--)
      if (a[j - 1] > a[j]) std::swap(a[j - 1], a[j]);
}

int main() {
  int a[] = {1, 2, 312, 56, 17, 8, 9, 22, 9, 3, 950, 30, 1};
  bubble(a, 0, 12);
  for (auto &i : a) {
    std::cout << i << ' ';
  }

  return 0;
}