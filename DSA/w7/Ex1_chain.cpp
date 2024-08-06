#include <iostream>

struct node {
  int data;
  node* next;
};

struct hashTable {
  int tsize;
  node** data;
};

hashTable createHashTable(int N) { return {N, new node*[N]()}; }

node* createNode(int key) {
  node* n = new node;
  n->data = key;
  n->next = nullptr;
  return n;
}

int mod(int a, int b) {
  int rem = a % b;
  if (rem < 0) {
    rem = rem + b;
  }
  return rem;
}

void insert(hashTable hashTable, int key) {
  int rem = mod(key, hashTable.tsize);
  if (hashTable.data[rem] == nullptr) {
    hashTable.data[rem] = createNode(key);
  } else {
    node* p = hashTable.data[rem];
    while (p != nullptr) {
      if (p->next == nullptr) {
        p->next = createNode(key);
        break;
      }
      p = p->next;
    }
  }
}

bool isInside(hashTable hashTable, int key) {
  int rem = mod(key, hashTable.tsize);
  node* p = hashTable.data[rem];
  while (p != nullptr) {
    if (p->data == key) {
      return true;
    }
    p = p->next;
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