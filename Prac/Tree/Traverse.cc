#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// 递归实现遍历
void preorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// 用栈实现
void preorder2(TreeNode *root)
{
    if (root == nullptr)
        return;

    stack<TreeNode *> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode *node = s.top();
        s.pop();
        cout << node->val << " ";

        if (node->right != nullptr)
        {
            s.push(node->right);
        }
        if (node->left != nullptr)
        {
            s.push(node->left);
        }
    }
}

void inorder2(TreeNode *root)
{
    if (root == nullptr)
        return;

    stack<TreeNode *> s;
    TreeNode *cur = root;

    while (cur != nullptr || !s.empty())
    {
        while (cur != nullptr)
        {
            s.push(cur);
            cur = cur->left;
        }
    }
    cur = s.top();
    s.pop();
    cout << cur->val << " ";

    cur = cur->right;
}

void postorder(TreeNode *root)
{
    if (root == nullptr)
        return;

    stack<TreeNode *> s;
    TreeNode *cur = root;
    TreeNode *last = nullptr;

    while (cur != nullptr || !s.empty())
    {
        while (cur != nullptr)
        {
            s.push(cur);
            cur = cur->left;
        }

        TreeNode *peek = s.top();
        if (peek->right == nullptr || peek->right == last)
        {
            cout << peek->val << " ";
            s.pop();
            last = peek;
        }
        else
        {
            cur = peek->right;
        }
    }
}