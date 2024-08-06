#include <iostream>

struct hashTable {
  int tsize;
  int** data;
};

int mod(int a, int b) {
  int rem = a % b;
  if (rem < 0) {
    rem = rem + b;
  }
  return rem;
}

hashTable createHashTable(int N) { return {N, new int*[N]()}; }

bool insert(hashTable hashTable, int key) {
  for (int i = 0; i < hashTable.tsize; i++) {
    int rem = mod(key + i * i, hashTable.tsize);
    if (hashTable.data[rem] == nullptr) {
      hashTable.data[rem] = new int(key);
      return true;
    }
  }
  return false;
}

bool isInside(hashTable hashTable, int key) {
  for (int i = 0; i < hashTable.tsize; i++) {
    int rem = mod(key + i * i, hashTable.tsize);
    if (hashTable.data[rem] != nullptr) {
      if (*hashTable.data[rem] == key) {
        return true;
      }
    } else {
      return false;
    }
  }
  return false;
}

int main() {
  int N;
  std::cout << "Enter N: ";
  std::cin >> N;
  hashTable ht = createHashTable(N);
  int a[] = {5, -4, 3, 2, 6, 7, -1, -9};
  int b[] = {51, 5, 77, 12, -1, 9};
  for (auto& i : a) {
    insert(ht, i);
  }
  for (auto& i : b) {
    std::cout << i << (isInside(ht, i) ? " is inside" : " not inside") << '\n';
  }
  return 0;
}