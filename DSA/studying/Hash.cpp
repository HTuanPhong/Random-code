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

void Remove(node*& root, int x) {
  if (root == nullptr) return;

  if (x < root->key) {
    Remove(root->left, x);
  } else if (x > root->key) {
    Remove(root->right, x);
  } else {
    if (root->left == nullptr || root->right == nullptr) {
      node* temp = root->left ? root->left : root->right;
      delete root;
      root = temp;
    } else {
      node* successor = takeSucc(root->right);
      successor->left = root->left;
      if (successor != root->right) {
        successor->right = root->right;
      }
      delete root;
      root = successor;
    }
  }

  if (root != nullptr) {
    Rebalance(root);
  }
}