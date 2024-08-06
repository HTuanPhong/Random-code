#include <iostream>

struct Node {
  int key;
  Node* left;
  Node* right;
  bool isRed;
};

Node* CreateNode(int i, Node* left, Node* right) {
  Node* res = new Node;
  res->key = i;
  res->left = left;
  res->right = right;
  res->isRed = true;
  return res;
}

bool IsRed(Node* node) {
  if (node == nullptr) return false;
  return node->isRed;
}

void RotateRight(Node*& h) {
  Node* x = h->left;
  h->left = x->right;
  x->right = h;
  h = x;
}
void RotateLeft(Node*& h) {
  Node* x = h->right;
  h->right = x->left;
  x->left = h;
  h = x;
}

void FlipColor(Node*& h) {
  bool childColor = h->left->isRed;
  h->left->isRed = h->isRed;
  h->right->isRed = h->isRed;
  h->isRed = childColor;
}

void AddKeyRB(Node*& root, int key) {
  if (root == nullptr) {
    root = CreateNode(key, nullptr, nullptr);
    return;
  }
  if (root->key == key) return;
  if (root->key > key)
    AddKeyRB(root->left, key);
  else
    AddKeyRB(root->right, key);

  if (IsRed(root->right) && !IsRed(root->left))
    RotateLeft(root);
  else if (IsRed(root->left) && IsRed(root->left->left))
    RotateRight(root);
  else if (IsRed(root->left) && IsRed(root->right))
    FlipColor(root);
}

void DeleteTree(Node* root) {
  if (root == nullptr) return;
  DeleteTree(root->left);
  DeleteTree(root->right);
  delete root;
}

void printTree(Node* t, int h) {
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
void printTree(Node* root) { printTree(root, 0); }

int main() {
  Node* root = nullptr;
  int a[13] = {29, 7, 49, 78, 24, 98, 46, 72, 25, 75, 44, 50, 89};
  for (int i = 0; i < 13; i++) {
    AddKeyRB(root, a[i]);
  }
  printTree(root);
  DeleteTree(root);
  return 0;
}
