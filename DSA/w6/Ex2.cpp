#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

struct node {
  int key;
  int ratio;
  node* left;
  node* right;
};

node* CreateNode(int key) {
  node* res = new node;
  res->key = key;
  res->left = nullptr;
  res->right = nullptr;
  res->ratio = 0;
  return res;
}

int Height(node* root) {
  if (root == nullptr) return 0;

  int lh = Height(root->left);
  int rh = Height(root->right);
  if (lh > rh)
    return lh + 1;
  else
    return rh + 1;
}

int getBalance(node* n) {
  if (n == nullptr) return 0;
  return Height(n->left) - Height(n->right);
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
}

bool checkAVL(node* root) {
  if (root != nullptr) {
    if (!checkAVL(root->left) || !checkAVL(root->right)) return false;
    root->ratio = getBalance(root);
    if (root->ratio > 1 || root->ratio < -1) return false;
    return true;
  }
  return true;
}

bool isValidAVLPreorder(std::stringstream& ss, node*& AVL) {
  int i;
  while (ss >> i) {
    Insert(AVL, i);
  }
  return checkAVL(AVL);
}

void Del(node*& pRoot) {
  if (pRoot != nullptr) {
    Del(pRoot->left);
    Del(pRoot->right);
    delete pRoot;
    pRoot = nullptr;
  }
}

int main() {
  std::fstream ifile("input.txt", std::ios::in);
  std::fstream ofile("output.txt", std::ios::out);
  if (!ifile.is_open() || !ofile.is_open()) {
    return 0;
  }
  int n;
  ifile >> n;
  ifile.ignore();
  for (; n > 0; n--) {
    std::string line;
    std::getline(ifile, line);
    std::stringstream ss(line);
    node* AVL = nullptr;
    if (isValidAVLPreorder(ss, AVL)) {
      ofile << "yes\n";
    } else {
      ofile << "no\n";
    }
    Del(AVL);
  }

  return 0;
}