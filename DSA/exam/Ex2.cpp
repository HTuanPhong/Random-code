#include <iostream>

struct Node
{
    int   data;
    Node *left;
    Node *right;

    Node(int value)
        : data(value), left(nullptr), right(nullptr)
    {
    }
};

class BST
{
  public:
    BST()
        : root(nullptr)
    {
    }

    void insert(int value)
    {
        root = insertRec(root, value);
    }

    void inorder()
    {
        inorderRec(root);
        std::cout << std::endl;
    }

    Node *search(int value)
    {
        return searchRec(root, value);
    }

    void remove(int value)
    {
        root = removeRec(root, value);
    }

  private:
    Node *root;

    Node *insertRec(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }
        if (value < node->data)
        {
            node->left = insertRec(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    void inorderRec(Node *node)
    {
        if (node != nullptr)
        {
            std::cout << node->data << " ";
            inorderRec(node->left);
            inorderRec(node->right);
        }
    }

    Node *searchRec(Node *node, int value)
    {
        if (node == nullptr || node->data == value)
        {
            return node;
        }
        if (value < node->data)
        {
            return searchRec(node->left, value);
        }
        else
        {
            return searchRec(node->right, value);
        }
    }

    Node *removeRec(Node *node, int value)
    {
        if (node == nullptr)
        {
            return node;
        }
        if (value < node->data)
        {
            node->left = removeRec(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = removeRec(node->right, value);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            Node *temp  = minValueNode(node->right);
            node->data  = temp->data;
            node->right = removeRec(node->right, temp->data);
        }
        return node;
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }
};

int main()
{
    BST tree;
    tree.insert(79);
    tree.insert(24);
    tree.insert(4);
    tree.insert(3);
    tree.insert(61);
    tree.insert(39);
    tree.insert(56);
    tree.insert(41);
    tree.insert(59);
    tree.insert(71);
    tree.insert(67);
    tree.insert(84);
    tree.insert(94);
    tree.insert(91);

    std::cout << "Inorder traversal of the given tree: ";
    tree.inorder();

    std::cout << "Delete 20\n";
    tree.remove(20);
    std::cout << "Inorder traversal of the modified tree: ";
    tree.inorder();

    std::cout << "Delete 30\n";
    tree.remove(30);
    std::cout << "Inorder traversal of the modified tree: ";
    tree.inorder();

    std::cout << "Delete 50\n";
    tree.remove(50);
    std::cout << "Inorder traversal of the modified tree: ";
    tree.inorder();

    return 0;
}