#include <iostream>

using namespace std;

enum Color
{
    RED,
    BLACK
};

struct Node
{
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree
{
private:
    Node *root;
    void rotateLeft(Node *&pt);
    void rotateRight(Node *&pt);
    void fixViolation(Node *&node);
    Node *minimum(Node *node);
    void fixDelete(Node *&node);

public:
    RedBlackTree() : root(nullptr) {}
    void insert(int data);
    void inorder();
    void inorderHelper(Node *root);
    void deleteNode(int data);
};

void RedBlackTree::rotateLeft(Node *&pt)
{
    Node *pt_y = pt->right;
    pt->right = pt_y->left;
    if (pt->right != nullptr)
        pt->right->parent = pt;

    pt_y->parent = pt->parent;

    if (pt->parent == nullptr)
    {
        root = pt_y;
    }
    else if (pt == pt->parent->left)
    {
        pt->parent->left = pt_y;
    }
    else
    {
        pt->parent->right = pt_y;
    }

    pt_y->left = pt;
    pt->parent = pt_y;
}

void RedBlackTree::rotateRight(Node *&pt)
{
    Node *pt_y = pt->right;
    pt->left = pt_y->right;

    if (pt->left != nullptr)
        pt->left->parent = pt;

    pt_y->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_y;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_y;
    else
        pt->parent->right = pt_y;

    pt_y->right = pt;
    pt->parent = pt_y;
}

void RedBlackTree::fixViolation(Node *&node)
{
    Node *parent = nullptr;
    Node *grandparent = nullptr;

    // 当前结点是红色且其父结点也是红色时进行修复
    while ((node != root) && (node->color == RED) && (node->parent->color == RED))
    {
        parent = node->parent;
        grandparent = parent->parent;

        // 父节点是祖父结点的左子结点
        if (parent == grandparent->left)
        {
            Node *uncle = grandparent->right;
            // 叔叔结点是红色
            if (uncle != nullptr && uncle->color == RED)
            {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            }
            else
            {
                // 进行旋转变色
                if (node == parent->right)
                {
                    rotateLeft(parent);    // 左旋父结点
                    node = parent;         // 更新结点为父结点
                    parent = node->parent; // 更新父结点
                }
                rotateRight(grandparent); // 右旋祖父结点
                swap(parent->color, grandparent->color);
                node = parent; // 更新当前节点为父节点
            }
        }
        else
        {
            Node *uncle = grandparent->left;
            if (uncle != nullptr && uncle->color == RED)
            {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            }
            else
            {
                if (node == parent->left)
                {
                    rotateRight(parent);
                    node = parent;
                    parent = node->parent;
                }
                rotateLeft(grandparent);
                swap(parent->color, grandparent->color);
                node = parent;
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::insert(int data)
{
    Node *node = new Node(data);
    if (root == nullptr)
    {
        node->color = BLACK;
        root = node;
    }
    else
    {
        Node *tmp = root;
        Node *parent = nullptr;

        while (tmp != nullptr)
        {
            parent = tmp;
            if (node->data < tmp->data)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }

        node->parent = parent;
        if (node->data < parent->data)
            parent->left = node;
        else
            parent->right = node;

        fixViolation(node);
    }
}

void RedBlackTree::inorderHelper(Node *node)
{
    if (node == nullptr)
        return;

    inorderHelper(node->left);
    cout << node->data << " ";
    inorderHelper(node->right);
}

void RedBlackTree::inorder()
{
    inorderHelper(root);
}

Node *RedBlackTree::minimum(Node *node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

void RedBlackTree::fixDelete(Node *&node)
{
    // 节点是黑色，删除变双黑
    while (node != root && node->color == BLACK)
    {
        if (node == node->parent->left)
        {
            Node *sibling = node->parent->right;
            // 兄弟是红色，兄父变色，父亲朝双黑旋转
            if (sibling->color == RED)
            {
                sibling->color = BLACK;
                node->parent->color = RED;
                rotateLeft(node->parent);
                sibling = node->parent->right;
            }

            // 兄弟是黑色且兄弟的子节点都是黑色
            if ((sibling->left == nullptr || sibling->left->color == BLACK) && (sibling->right == nullptr || sibling->right->color == BLACK))
            {
                sibling->color = RED; // 兄弟变红
                node = node->parent;  // 上移双黑节点
            }
            else
            // 兄弟是黑色，至少有一个红色节点
            {
                if (sibling->right == nullptr || sibling->right->color == BLACK)
                {
                    if (sibling->left != nullptr)
                        sibling->left->color = BLACK;
                    sibling->color = RED;
                    rotateRight(sibling);
                    sibling = node->parent->right;
                }
                // 兄弟是黑，右子节点为红
                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                if (sibling->right != nullptr)
                    sibling->right->color = BLACK;
                rotateLeft(node->parent);
                node = root;
            }
        }
        else
        {
            Node *sibling = node->parent->left; // 获取兄弟节点

            // 兄弟是红色
            if (sibling->color == RED)
            {
                sibling->color = BLACK;       // 兄弟变黑
                node->parent->color = RED;    // 父节点变红
                rotateRight(node->parent);    // 右旋转
                sibling = node->parent->left; // 更新兄弟节点
            }

            // 兄弟是黑色且兄弟的子节点都是黑色
            if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
                (sibling->right == nullptr || sibling->right->color == BLACK))
            {
                sibling->color = RED; // 兄弟变红
                node = node->parent;  // 上移双黑节点
            }
            else
            {
                // 兄弟是黑色，至少有一个红色子节点
                if (sibling->left == nullptr || sibling->left->color == BLACK)
                {
                    if (sibling->right != nullptr)
                        sibling->right->color = BLACK; // 右子节点变黑
                    sibling->color = RED;              // 兄弟变红
                    rotateLeft(sibling);               // 左旋转兄弟节点
                    sibling = node->parent->left;      // 更新兄弟节点
                }
                // 兄弟是黑色，左子节点为红色
                sibling->color = node->parent->color; // 兄弟变成父节点的颜色
                node->parent->color = BLACK;          // 父节点变黑
                if (sibling->left != nullptr)
                    sibling->left->color = BLACK; // 左子节点变黑
                rotateRight(node->parent);        // 右旋转
                node = root;                      // 修复结束
            }
        }
    }
    node->color = BLACK;
}

void RedBlackTree::deleteNode(int data)
{
    Node *node = root;
    Node *z = nullptr;
    Node *x, *y;

    while (node != nullptr)
    {
        if (node->data == data)
            z = node;

        if (node->data < data)
            node = node->right;
        else
            node = node->left;
    }

    if (z == nullptr)
        return;

    y = z;
    Color y_original_color = y->color;
    // 无节点或单子节点时删除
    if (z->left == nullptr)
    {
        x = z->right;
        if (x != nullptr)
            x->parent = z->parent;

        if (z->parent == nullptr)
            root = x;
        else if (z = z->parent->left)
            z->parent->left = x;
        else
            z->parent->right = x;

        delete z;
    }
    else if (z->right == nullptr)
    {
        x = z->left;
        if (x != nullptr)
            x->parent = z->parent;

        if (z->parent == nullptr)
            root = x;

        else if (z == z->parent->left)
            z->parent->left = x;
        else
            z->parent->right = x;

        delete z;
    }
    else
    {
        y = minimum(z->right); // 找到右子树中最小的节点
        y_original_color = y->color;
        x = y->right;

        if (y->parent == z)
        {
            if (x != nullptr)
                x->parent = y;
        }
        else
        {
            if (x != nullptr)
                x->parent = y->parent;
            y->parent->left = x;
            y->right = z->right;
            z->right->parent = y;
        }

        if (z->parent == nullptr)
            root = y; // 如果 z 是根节点
        else if (z == z->parent->left)
            z->parent->left = y; // 更新父节点的左子指针
        else
            z->parent->right = y; // 更新父节点的右子指针

        y->parent = z->parent; // 更新 y 的父节点
        y->color = z->color;   // 更新 y 的颜色
        y->left = z->left;     // 将 z 的左子树接到 y
        z->left->parent = y;   // 更新 z 的左子树的父节点

        delete z; // 删除节点
    }

    if (y_original_color == BLACK)
    {
        fixDelete(x); // 处理双黑情况
    }
}

int main()
{
    RedBlackTree rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);

    std::cout << "Inorder Traversal: ";
    rbt.inorder();
    std::cout << std::endl;

    rbt.deleteNode(20); // 删除节点
    std::cout << "Inorder Traversal after deletion: ";
    rbt.inorder(); // 打印中序遍历结果
    std::cout << std::endl;

    return 0;
}