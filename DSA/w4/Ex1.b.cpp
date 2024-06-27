#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TreeNode
{
  public:
    string             name;
    vector<TreeNode *> children;

    TreeNode(string name)
        : name(name)
    {
    }
};

class FamilyTree
{
  private:
    unordered_map<string, TreeNode *> nodes;
    TreeNode                         *root;

    void preorder(TreeNode *node, vector<string> &result)
    {
        if (!node)
            return;
        result.push_back(node->name);
        for (auto child : node->children)
        {
            preorder(child, result);
        }
    }

    void inorder(TreeNode *node, vector<string> &result)
    {
        if (!node)
            return;
        int n = node->children.size();
        for (int i = 0; i < n / 2; ++i)
        {
            inorder(node->children[i], result);
        }
        result.push_back(node->name);
        for (int i = n / 2; i < n; ++i)
        {
            inorder(node->children[i], result);
        }
    }

    void postorder(TreeNode *node, vector<string> &result)
    {
        if (!node)
            return;
        for (auto child : node->children)
        {
            postorder(child, result);
        }
        result.push_back(node->name);
    }

  public:
    FamilyTree()
        : root(nullptr)
    {
    }

    void addRelation(const string &parentName, const vector<string> &childrenNames)
    {
        if (nodes.find(parentName) == nodes.end())
        {
            nodes[parentName] = new TreeNode(parentName);
        }
        TreeNode *parent = nodes[parentName];
        for (const auto &childName : childrenNames)
        {
            if (nodes.find(childName) == nodes.end())
            {
                nodes[childName] = new TreeNode(childName);
            }
            parent->children.push_back(nodes[childName]);
        }
        if (!root)
        {
            root = parent;
        }
    }

    vector<string> getPreOrder()
    {
        vector<string> result;
        preorder(root, result);
        return result;
    }

    vector<string> getInOrder()
    {
        vector<string> result;
        inorder(root, result);
        return result;
    }

    vector<string> getPostOrder()
    {
        vector<string> result;
        postorder(root, result);
        return result;
    }
};

vector<string> split(const string &str)
{
    vector<string> tokens;
    stringstream   ss(str);
    string         token;
    while (ss >> token)
    {
        tokens.push_back(token);
    }
    return tokens;
}

int main()
{
    ifstream infile("family_data.txt");
    if (!infile)
    {
        cerr << "Unable to open file family_data.txt";
        return 1;
    }

    int numRelations;
    infile >> numRelations;
    infile.ignore();

    FamilyTree familyTree;
    string     line;
    while (getline(infile, line))
    {
        line                         = line.substr(1, line.size() - 2);
        size_t         pos1          = line.find('(');
        size_t         pos2          = line.find(')');
        string         parentName    = line.substr(0, pos1 - 1);
        string         childrenStr   = line.substr(pos1 + 1, pos2 - pos1 - 1);
        vector<string> childrenNames = split(childrenStr);
        familyTree.addRelation(parentName, childrenNames);
    }

    infile.close();

    vector<string> preOrder  = familyTree.getPreOrder();
    vector<string> inOrder   = familyTree.getInOrder();
    vector<string> postOrder = familyTree.getPostOrder();

    cout << "PreOrder: ";
    for (const auto &name : preOrder)
    {
        cout << name << " ";
    }
    cout << endl;

    cout << "InOrder: ";
    for (const auto &name : inOrder)
    {
        cout << name << " ";
    }
    cout << endl;

    cout << "PostOrder: ";
    for (const auto &name : postOrder)
    {
        cout << name << " ";
    }
    cout << endl;

    return 0;
}