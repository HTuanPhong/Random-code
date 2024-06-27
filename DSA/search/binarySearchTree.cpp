#include <iostream>
#include <random>
#include <string>
using namespace std;
typedef int Key; // non-negative number
const Key   nullKey = -1;
class BSTree
{
  private:
    struct Node
    {
        Key   key;
        Node *left, *right;
        Node(Key key)
        {
            this->key = key;
            left      = nullptr;
            right     = nullptr;
        }
    };
    typedef Node *link;

  private:
    link root;

  public:
    BSTree()
    {
        root = nullptr;
    }
    void printTree(link t, int h)
    {
        if (t == nullptr)
        {
            for (int i = 0; i < h; i++)
                cout << "   ";
            cout << "*  " << endl;
            return;
        }
        printTree(t->right, h + 1);
        for (int i = 0; i < h; i++)
            cout << "   ";
        cout << t->key << endl;
        printTree(t->left, h + 1);
    }
    void printTree()
    {
        printTree(root, 0);
    }
    void insertKey(Key key, link &root)
    {
        if (root == nullptr)
        {
            root = new Node(key);
        }
        else
        {
            if (root->key == key)
                return;
            if (root->key > key)
                insertKey(key, root->left);
            if (root->key < key)
                insertKey(key, root->right);
        }
    }
    void insert(Key key)
    {
        insertKey(key, root);
    }
    void insertKeyRoot(Key key, link &root)
    {
        if (root == nullptr)
            root = new Node(key);
        else
        {
            if (root->key == key)
                return;
            if (root->key > key)
            {
                insertKeyRoot(key, root->left);
                rightRotate(root);
            }
            if (root->key < key)
            {
                insertKeyRoot(key, root->right);
                leftRotate(root);
            }
        }
    }
    void insertRoot(Key key)
    {
        insertKeyRoot(key, root);
    }
    Key floorKey(Key key, link &root)
    {
        if (root == nullptr)
            return -1;
        if (key == root->key)
            return root->key;
        if (key < root->key)
            return floorKey(key, root->left);
        Key res = floorKey(key, root->right);
        if (res == -1)
            return root->key;
        else
            return res;
    }
    Key floor(Key key)
    {
        return floorKey(key, root);
    }
    void rightRotate(link &h)
    {
        link x   = h->left;
        h->left  = x->right;
        x->right = h;
        h        = x;
    }
    void leftRotate(link &h)
    {
        link x   = h->right;
        h->right = x->left;
        x->left  = h;
        h        = x;
    }
};
int main()
{
    // std::random_device dev;
    // std::mt19937       rng(dev());

    // std::uniform_int_distribution<std::mt19937::result_type> dist(0, 9);

    int a[10] = {7, 3, 6, 2, 20, 5, 9, 1, 4, 10};

    // for (auto &i : a)
    // {
    //     std::swap(i, a[dist(rng)]);
    // }

    BSTree tree;
    for (auto &i : a)
    {
        std::cout << i << ',';
        tree.insert(i);
    }
    std::cout << '\n';
    tree.insertRoot(8);
    tree.printTree();

    return 0;
}