#include <algorithm>
#include <iostream>
struct node {
  int key;
  int height;
  node* left;
  node* right;
};

node* CreateNode(int key) {
  node* res = new node;
  res->key = key;
  res->left = nullptr;
  res->right = nullptr;
  res->height = 1;
  return res;
}

int Height(node* node) { return node ? node->height : 0; }

void UpdateHeight(node* n) {
  if (n) {
    n->height = 1 + std::max(Height(n->left), Height(n->right));
  }
}

void RightRotate(node*& h) {
  if (h == nullptr) return;
  node* x = h->left;
  if (x == nullptr) return;
  h->left = x->right;
  x->right = h;
  UpdateHeight(h);
  h = x;
  UpdateHeight(h);
}

void LeftRotate(node*& h) {
  if (h == nullptr) return;
  node* x = h->right;
  if (x == nullptr) return;
  h->right = x->left;
  x->left = h;
  UpdateHeight(h);
  h = x;
  UpdateHeight(h);
}

int getBalance(node* n) {
  if (n == nullptr) return 0;
  return Height(n->left) - Height(n->right);
}

void Rebalance(node*& root) {
  UpdateHeight(root);
  int balance = getBalance(root);
  if (balance > 1) {
    if (getBalance(root->left) < 0) {
      LeftRotate(root->left);
    }
    RightRotate(root);
  } else if (balance < -1) {
    if (getBalance(root->right) > 0) {
      RightRotate(root->right);
    }
    LeftRotate(root);
  }
}

void Insert(node*& root, int key) {
  if (root == nullptr) {
    root = CreateNode(key);
    return;
  }
  if (key < root->key) {
    Insert(root->left, key);
  } else if (key > root->key) {
    Insert(root->right, key);
  } else {
    return;
  }
  Rebalance(root);
}

node* lcaRecursion(node* root, int k1, int k2) {
  if (root->key >= k1 && root->key <= k2) {
    return root;
  } else if (root->key > k1 && root->key > k2) {
    return lcaRecursion(root->left, k1, k2);
  } else {
    return lcaRecursion(root->right, k1, k2);
  }
}

node* lca(node* root, int k1, int k2) {
  if (k1 > k2) {
    std::swap(k1, k2);
  }
  return lcaRecursion(root, k1, k2);
}

int main() {
  int a[] = {4, 2, 1, 3, 5, 6};
  node* AVL = nullptr;
  for (auto& i : a) {
    Insert(AVL, i);
  }
  std::cout << lca(AVL, 1, 5)->key;
  return 0;
}