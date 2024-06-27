#include <fstream>
#include <iostream>
#include <string>

class Tree
{
  private:
    struct Node
    {
        std::string key;
        Node       *left, *right;
        Node(std::string &key)
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
    Tree()
    {
        root = nullptr;
    }

    void del(link &root)
    {
        if (root != nullptr)
        {
            del(root->left);
            del(root->right);
            delete root;
        }
    }

    ~Tree()
    {
        del(root);
    }
    void insertKey(std::string &parent, std::string &childLeft, std::string &childRight, link &root)
    {
        if (root == nullptr)
        {
            root        = new Node(parent);
            root->left  = new Node(childLeft);
            root->right = new Node(childRight);
        }
        else
        {
            if (root->key == parent)
            {
                root->left  = new Node(childLeft);
                root->right = new Node(childRight);
            }
            else
            {
                if (root->left != nullptr)
                    insertKey(parent, childLeft, childRight, root->left);
                if (root->right != nullptr)
                    insertKey(parent, childLeft, childRight, root->right);
            }
        }
    }
    void insert(std::string &parent, std::string &childLeft, std::string &childRight)
    {
        insertKey(parent, childLeft, childRight, root);
    }
    void preorder(link &root)
    {
        if (root != nullptr)
        {
            std::cout << root->key << '\n';
            preorder(root->left);
            preorder(root->right);
        }
    }
    void preorder()
    {
        preorder(root);
    }
    void inorder(link &root)
    {
        if (root != nullptr)
        {
            inorder(root->left);
            std::cout << root->key << '\n';
            inorder(root->right);
        }
    }
    void inorder()
    {
        inorder(root);
    }
    void postorder(link &root)
    {
        if (root != nullptr)
        {
            postorder(root->left);
            postorder(root->right);
            std::cout << root->key << '\n';
        }
    }
    void postorder()
    {
        postorder(root);
    }
};

int main()
{
    std::fstream file("input.txt", std::ios::in);
    if (!file.is_open())
    {
        std::cout << "fail to open file";
        return 0;
    }

    int n;
    file >> n;
    file.ignore();
    std::string parent;
    std::string childLeft;
    std::string childRight;
    Tree        familyTree;

    for (int i = 0; i < n; i++)
    {
        file.ignore();
        file >> parent;
        file.ignore(2);
        file >> childLeft;
        file.ignore();
        std::getline(file, childRight, ')');
        file.ignore(2);
        familyTree.insert(parent, childLeft, childRight);
    }

    std::cout << "\npreOrder: \n";
    familyTree.preorder();
    std::cout << "\ninOrder: \n";
    familyTree.inorder();
    std::cout << "\npostOrder: \n";
    familyTree.postorder();

    return 0;
}