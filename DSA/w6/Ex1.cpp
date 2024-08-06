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

node* findSucc(node*& root) {
  if (root == nullptr)
    return nullptr;
  else if (root->left != nullptr)
    return findSucc(root->left);
  node* res = root;
  root = root->right;
  return res;
}

void Remove(node*& root, int x) {
  if (root == nullptr) return;
  if (root->key > x) return Remove(root->left, x);
  if (root->key < x) return Remove(root->right, x);
  if (root->key == x) {
    node* child = nullptr;
    if (root->left != nullptr && root->right != nullptr) {
      child = findSucc(root->right);
      child->left = root->left;
      child->right = root->right;
    } else {
      if (root->left != nullptr) {
        child = root->left;
      } else {
        child = root->right;
      }
    }
    delete root;
    root = child;
  }
  Rebalance(root);
}

int main() {
  int a[] = {29, 7, 49, 78, 24, 98, 46, 72, 25, 75, 44, 50, 89};
  node* AVL = nullptr;
  for (auto& i : a) {
    Insert(AVL, i);
  }
  Remove(AVL, 72);
  Remove(AVL, 78);
  Remove(AVL, 98);
  printTree(AVL, 0);
  return 0;
}