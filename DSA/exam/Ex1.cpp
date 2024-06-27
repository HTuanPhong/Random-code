#include <cmath>
#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;
  Node(int n) {
    val = n;
    left = nullptr;
    right = nullptr;
  }
};

int BSTtoVINE(Node *grand) {
  int count = 0;
  Node *tmp = grand->right;

  while (tmp) {
    if (tmp->left) {
      Node *oldTmp = tmp;
      tmp = tmp->left;
      oldTmp->left = tmp->right;
      tmp->right = oldTmp;
      grand->right = tmp;
    } else {
      count++;
      grand = tmp;
      tmp = tmp->right;
    }
  }

  return count;
}

void Compress(Node *root, int m) {
  Node *tmp = root->right;

  for (int i = 0; i < m; i++) {
    Node *oldTmp = tmp;
    tmp = tmp->right;
    root->right = tmp;
    oldTmp->right = tmp->left;
    tmp->left = oldTmp;
    root = tmp;
    tmp = tmp->right;
  }
}

Node *balanceBST(Node *root) {
  Node *grand = new Node(0);

  grand->right = root;

  int count = BSTtoVINE(grand);

  int h = log2(count + 1);

  int m = pow(2, h) - 1;

  Compress(grand, count - m);

  for (m = m / 2; m > 0; m /= 2) {
    Compress(grand, m);
  }
  Node *tempRes = grand->right;
  delete grand;
  return tempRes;
}

void Preorder(Node *root) {
  if (!root) return;
  cout << root->val << " ";
  Preorder(root->left);
  Preorder(root->right);
  return;
}

void printTree(Node *t, int h) {
  if (t == nullptr) {
    for (int i = 0; i < h; i++) cout << "   ";
    cout << "*  " << endl;
    return;
  }
  printTree(t->right, h + 1);
  for (int i = 0; i < h; i++) cout << "   ";
  cout << t->val << endl;
  printTree(t->left, h + 1);
}

int main() {
  Node *root = new Node(28);
  root->left = new Node(9);
  root->left->left = new Node(7);
  root->left->left->left = new Node(4);

  std::cout << "before\n";
  printTree(root, 0);
  root = balanceBST(root);
  std::cout << "after\n";
  printTree(root, 0);

  Preorder(root);

  return 0;
}