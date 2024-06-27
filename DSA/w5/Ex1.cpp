#include <iostream>
#include <queue>

struct NODE {
  int key;
  NODE* p_left;
  NODE* p_right;
};

NODE* createNode(int data) {
  NODE* res = new NODE;
  res->key = data;
  res->p_left = nullptr;
  res->p_right = nullptr;
  return res;
}

void NLR(NODE* pRoot) {
  if (pRoot != nullptr) {
    std::cout << pRoot->key << ' ';
    NLR(pRoot->p_left);
    NLR(pRoot->p_right);
  }
}

void LNR(NODE* pRoot) {
  if (pRoot != nullptr) {
    LNR(pRoot->p_left);
    std::cout << pRoot->key << ' ';
    LNR(pRoot->p_right);
  }
}

void LRN(NODE* pRoot) {
  if (pRoot != nullptr) {
    LRN(pRoot->p_left);
    LRN(pRoot->p_right);
    std::cout << pRoot->key << ' ';
  }
}

void LevelOrder(NODE* pRoot) {
  if (pRoot == nullptr) return;
  std::queue<NODE*> q;
  NODE* curr;
  q.push(pRoot);
  q.push(nullptr);
  while (q.size() > 1) {
    curr = q.front();
    q.pop();
    if (curr == nullptr) {
      q.push(nullptr);
      std::cout << '\n';
    } else {
      if (curr->p_left) q.push(curr->p_left);
      if (curr->p_right) q.push(curr->p_right);
      std::cout << curr->key << ' ';
    }
  }
}

NODE* Search(NODE* pRoot, int x) {
  if (pRoot == nullptr) return nullptr;
  if (pRoot->key == x) return pRoot;
  if (pRoot->key > x) return Search(pRoot->p_left, x);
  return Search(pRoot->p_right, x);
}

void Insert(NODE*& pRoot, int x) {
  if (pRoot == nullptr) {
    pRoot = createNode(x);
  } else if (pRoot->key > x) {
    Insert(pRoot->p_left, x);
  } else {
    Insert(pRoot->p_right, x);
  }
}

NODE* findSucc(NODE*& root) {
  if (root == nullptr)
    return nullptr;
  else if (root->p_left != nullptr)
    return findSucc(root->p_left);
  NODE* res = root;
  root = root->p_right;
  return res;
}

void Remove(NODE*& pRoot, int x) {
  if (pRoot == nullptr) return;
  if (pRoot->key > x) return Remove(pRoot->p_left, x);
  if (pRoot->key < x) return Remove(pRoot->p_right, x);
  NODE* child = nullptr;
  if (pRoot->p_left != nullptr && pRoot->p_right != nullptr) {
    child = findSucc(pRoot->p_right);
    child->p_left = pRoot->p_left;
    child->p_right = pRoot->p_right;
  } else {
    if (pRoot->p_left != nullptr) {
      child = pRoot->p_left;
    } else {
      child = pRoot->p_right;
    }
  }
  delete pRoot;
  pRoot = child;
}

NODE* createTree(int a[], int n) {
  NODE* tree = nullptr;
  for (int i = 0; i < n; i++) {
    Insert(tree, a[i]);
  }
  return tree;
}

void removeTree(NODE*& pRoot) {
  if (pRoot != nullptr) {
    removeTree(pRoot->p_left);
    removeTree(pRoot->p_right);
    delete pRoot;
    pRoot = nullptr;
  }
}

int Height(NODE* pRoot) {
  if (pRoot == nullptr) return 0;

  int lh = Height(pRoot->p_left);
  int rh = Height(pRoot->p_right);
  if (lh > rh)
    return lh + 1;
  else
    return rh + 1;
}

int countNode(NODE* pRoot) {
  if (pRoot != nullptr) {
    return countNode(pRoot->p_left) + countNode(pRoot->p_right) + 1;
  }
  return 0;
}

int sumNode(NODE* pRoot) {
  if (pRoot != nullptr) {
    return sumNode(pRoot->p_left) + sumNode(pRoot->p_right) + pRoot->key;
  }
  return 0;
}

int heightNode(NODE* pRoot, int value) {
  if (pRoot == nullptr) return -1;
  if (pRoot->key == value) return 1;
  if (pRoot->key > value) return heightNode(pRoot->p_left, value) + 1;
  return heightNode(pRoot->p_right, value) + 1;
}

int Level(NODE* pRoot, NODE* p) {
  if (pRoot == nullptr) return -1;
  if (pRoot->key == p->key) return 0;
  if (pRoot->key > p->key) return Level(pRoot->p_left, p) + 1;
  return Level(pRoot->p_right, p) + 1;
}

int countLeaf(NODE* pRoot) {
  if (pRoot != nullptr) {
    if (!pRoot->p_left && !pRoot->p_right)
      return 1;
    else
      return countLeaf(pRoot->p_left) + countLeaf(pRoot->p_right);
  }
  return 0;
}

int countLess(NODE* pRoot, int x) {
  if (pRoot) {
    return countLess(pRoot->p_left, x) + countLess(pRoot->p_right, x) +
           (pRoot->key < x);
  }
  return 0;
}

int countGreater(NODE* pRoot, int x) {
  if (pRoot) {
    return countGreater(pRoot->p_left, x) + countGreater(pRoot->p_right, x) +
           (pRoot->key > x);
  }
  return 0;
}

bool isBSTRecur(NODE* root, NODE*& prev) {
  if (root) {
    if (!isBSTRecur(root->p_left, prev)) return false;
    if (prev != NULL && root->key <= prev->key) return false;
    prev = root;
    return isBSTRecur(root->p_right, prev);
  }

  return true;
}

bool isBST(NODE* pRoot) {
  NODE* prev = NULL;
  return isBSTRecur(pRoot, prev);
}

bool isFull(NODE* root) {
  if (root) {
    if (!root->p_left != !root->p_right) return false;
    if (!isFull(root->p_left)) return false;
    return isFull(root->p_right);
  }
  return true;
}

bool isFullBST(NODE* pRoot) { return isFull(pRoot) && isBST(pRoot); }

int main() {
  int a[] = {5, 4, 3, 7, 8, 6, 1, 2, 9, 12};
  NODE* BST = createTree(a, 10);

  LNR(BST);
  std::cout << "\n\n";
  // std::cout <<
  LevelOrder(BST);
  std::cout << "\n\n";

  // Remove(BST, 5);

  std::cout << Level(BST, Search(BST, 1)) << "\n\n";

  LNR(BST);

  removeTree(BST);
  return 0;
}