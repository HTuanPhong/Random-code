#include <iostream>

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* CreateNode(int data, Node* left = nullptr, Node* right = nullptr) {
  Node* res = new Node;
  res->data = data;
  res->left = left;
  res->right = right;
  return res;
}

bool Add(Node*& root, int data) {
  if (root == nullptr) {
    root = CreateNode(data);
    return 1;
  }
  if (root->data == data) return 0;
  if (root->data > data)
    return Add(root->left, data);
  else
    return Add(root->right, data);
}

Node* Search(Node* root, int data) {
  if (root == nullptr) return nullptr;
  if (root->data == data) return root;
  if (root->data > data)
    return Search(root->left, data);
  else
    return Search(root->right, data);
}

Node* GetSuccessor(Node*& root) {
  if (root->left != nullptr) return GetSuccessor(root->left);
  Node* res = root;
  root = root->right;
  return res;
}

void Remove(Node*& root, int data) {
  if (root == nullptr) return;
  if (root->data > data) return Remove(root->left, data);
  if (root->data < data) return Remove(root->right, data);
  Node* successor = nullptr;
  if (root->left != nullptr && root->right != nullptr) {
    successor = GetSuccessor(root->right);
    successor->left = root->left;
    successor->right = root->right;
  } else {
    if (root->left != nullptr) {
      successor = root->left;
    } else {
      successor = root->right;
    }
  }
  delete root;
  root = successor;
}

void DeleteTree(Node* root) {
  if (root == nullptr) return;
  DeleteTree(root->left);
  DeleteTree(root->right);
  delete root;
}

int main() { return 0; }