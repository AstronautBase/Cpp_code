#include <iostream>

using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
public:
    BinarySearchTree() : root(nullptr) {}
    void insert(int val)
    {
        root = insertVal(root, val);
    }
    bool search(int val)
    {
        return searchVal(root, val);
    }
    void inorderTrav()
    {
        inorder(root);
    }

private:
    TreeNode *root;
    TreeNode *insertVal(TreeNode *node, int val);
    bool searchVal(TreeNode *node, int val);
    void inorder(TreeNode *node);
    void preorder(TreeNode *node);
    void postorder(TreeNode *node);
    TreeNode *remove(TreeNode *node, int val);
    TreeNode *findMin(TreeNode *node);
};

TreeNode *BinarySearchTree::insertVal(TreeNode *node, int val)
{
    if (node == nullptr)
    {
        return new TreeNode(val);
    }

    if (val < node->value)
    {
        insertVal(node->left, val);
    }
    else
    {
        insertVal(node->right, val);
    }

    return node;
}

bool BinarySearchTree::searchVal(TreeNode *node, int val)
{
    if (node == nullptr)
    {
        return false;
    }
    if (val == node->value)
    {
        return true;
    }
    else if (val < node->value)
    {
        return searchVal(node->left, val);
    }
    else
    {
        return searchVal(node->right, val);
    }
}

void BinarySearchTree::inorder(TreeNode *node)
{
    if (node != nullptr)
    {
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }
}

void BinarySearchTree::preorder(TreeNode *node)
{
    if (node != nullptr)
    {
        cout << node->value << " ";
        postorder(node->left);
        postorder(node->right);
    }
}

void BinarySearchTree::postorder(TreeNode *node)
{
    if (node != nullptr)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->value << " ";
    }
}

TreeNode *BinarySearchTree::remove(TreeNode *node, int val)
{
    if (node == nullptr)
    {
        return node;
    }

    if (val < node->value)
    {
        node->left = remove(node->left, val);
    }
    else if (val > node->value)
    {
        node->right = remove(node->right, val);
    }
    else
    {
        if (node->left == nullptr)
        {
            TreeNode *tmp = node->right;
            delete node;
            return tmp;
        }
        else if (node->right == nullptr)
        {
            TreeNode *tmp = node->left;
            delete node;
            return tmp;
        }
        // 有两个节点，找到右子树的最小值
        TreeNode *minNode = findMin(node->right);
        // 用右子树的最小值代替要删除的节点
        node->value = minNode->value;
        // 删除右子树的最小值所在节点
        node->right = remove(node->right, minNode->value);
    }
    return node;
}

TreeNode *BinarySearchTree::findMin(TreeNode *node)
{
    while (node && node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}