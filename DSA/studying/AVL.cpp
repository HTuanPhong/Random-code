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

void NLR(node* root) {
  if (root != nullptr) {
    std::cout << root->key << ' ';
    NLR(root->left);
    NLR(root->right);
  }
}

void LNR(node* root) {
  if (root != nullptr) {
    LNR(root->left);
    std::cout << root->key << ' ';
    LNR(root->right);
  }
}

void LRN(node* root) {
  if (root != nullptr) {
    LRN(root->left);
    LRN(root->right);
    std::cout << root->key << ' ';
  }
}

void DeleteTree(node*& root) {
  if (root != nullptr) {
    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
    root = nullptr;
  }
}

node* Search(node* root, int x) {
  if (root == nullptr) return nullptr;
  if (root->key == x) return root;
  if (root->key > x) return Search(root->left, x);
  return Search(root->right, x);
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
  UpdateHeight(x);
  h = x;
}

void LeftRotate(node*& h) {
  if (h == nullptr) return;
  node* x = h->right;
  if (x == nullptr) return;
  h->right = x->left;
  x->left = h;
  UpdateHeight(h);
  UpdateHeight(x);
  h = x;
}

int getBalance(node* n) {
  if (n == nullptr) return 0;
  return Height(n->left) - Height(n->right);
}

void Rebalance(node*& root) {
  if (root == nullptr) return;
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

void printTree(node* t, int h) {
  if (t == nullptr) {
    for (int i = 0; i < h; i++) std::cout << "   ";
    std::cout << "*  " << '\n';
    return;
  }
  printTree(t->right, h + 1);
  for (int i = 0; i < h; i++) std::cout << "   ";
  std::cout << t->key << '\n';
  printTree(t->left, h + 1);
}

node* minValueNode(node* root) {
  node* current = root;
  while (current->left != nullptr) {
    current = current->left;
  }
  return current;
}

void Remove(node*& root, int x) {
  if (root == nullptr) return;
  if (root->key > x) {
    Remove(root->left, x);
  } else if (root->key < x) {
    Remove(root->right, x);
  } else {
    if (root->left == nullptr || root->right == nullptr) {
      node* temp = root->left ? root->left : root->right;
      delete root;
      root = temp;
    } else {
      node* successor = minValueNode(root->right);
      root->key = successor->key;
      Remove(root->right, successor->key);
    }
  }
  if (root == nullptr) return;
  Rebalance(root);
}

int main() {
  int a[] = {30, 20, 10, 25, 40, 50};
  node* AVL = nullptr;
  for (auto& i : a) {
    Insert(AVL, i);
  }
  NLR(AVL);
  // std::cout << "\n";
  // Remove(AVL, 10);
  // NLR(AVL);
  // std::cout << "\n";
  // printTree(AVL, 0);
  DeleteTree(AVL);
  return 0;
}