#include <cstdlib>
#include <iostream>

using namespace std;

class TreeNode
{
public:
    int key;
    int priority;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int k) : key(k), priority(rand()), left(nullptr), right(nullptr) {}
};

class Treap
{
private:
    TreeNode *root;
    TreeNode *insert(TreeNode *node, int k);
    void inorder(TreeNode *node);
    TreeNode *remove(TreeNode *node, int val);
    void rotateRight(TreeNode *&node);
    void rotateLeft(TreeNode *&node);
    void clear(TreeNode *node)
    {
        if (node)
        {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    Treap() : root(nullptr) {}
    ~Treap() { clear(root); }
    void insertKey(int key) { root = insert(root, key); }
    void removeKey(int key) { root = remove(root, key); }
    void inorderTrav() { inorder(root); }
};

void Treap::rotateRight(TreeNode *&node)
{
    if (node == nullptr)
        return;
    TreeNode *p = node->left;
    node->left = p->right;
    p->right = node;
    node = p;
}

void Treap::rotateLeft(TreeNode *&node)
{
    if (node == nullptr)
        return;
    TreeNode *p = node->right;
    node->right = p->left;
    p->left = node;
    node = p;
}

TreeNode *Treap::insert(TreeNode *node, int k)
{
    if (node == nullptr)
    {
        node = new TreeNode(k);
        return node;
    }

    if (k < node->key)
    {
        node->left = insert(node->left, k);
        if (node->left->priority > node->priority)
        {
            rotateRight(node);
        }
    }
    else if (k > node->key)
    {
        node->right = insert(node->right, k);
        if (node->right->priority > node->priority)
        {
            rotateLeft(node);
        }
    }
    return node;
}

TreeNode *Treap::remove(TreeNode *node, int val)
{
    if (node == nullptr)
        return nullptr;

    if (val < node->key)
    {
        node->left = remove(node->left, val);
    }
    else if (val > node->key)
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
        else if (node->left->priority > node->right->priority)
        {
            rotateLeft(node);
            node->right = remove(node->left, val);
        }
        else
        {
            rotateRight(node);
            node->left = remove(node->right, val);
        }
    }
    return node;
}

void Treap::inorder(TreeNode *node)
{
    if (node)
    {
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
}

int main()
{
    Treap treap;
    treap.insertKey(10);
    treap.insertKey(20);
    treap.insertKey(30);
    treap.insertKey(40);
    treap.insertKey(50);
    // 中序遍历测试
    cout << "Inorder traversal of the Treap: ";
    treap.inorderTrav();
    cout << endl;

    // 删除测试
    cout << "Removing key30 from Treap" << endl;
    treap.removeKey(30);
    // 中序遍历测试
    cout << "Inorder traversal after removing30: ";
    treap.inorderTrav();
    cout << endl;
}