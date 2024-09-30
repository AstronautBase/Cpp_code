#include <iostream>
using namespace std;

const int STACK_SIZE = 100;
class Stack
{
public:
    Stack();
    void push(int e);
    void pop(int &e);

private:
    int buffer[STACK_SIZE];
    int top;
};
Stack::Stack()
{
    top = -1;
}

void Stack::push(int e)
{
    if (top == STACK_SIZE - 1)
    {
        cout << "Stack is full" << endl;
        return;
    }
    buffer[++top] = e;
}

void Stack::pop(int &e)
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    e = buffer[top--];
}

// 链表
class Stack1
{
public:
    Stack1();
    void push(int e);
    void pop(int &e);

private:
    struct Node
    {
        int content;
        Node *next;
    };
    Node *top;
};

Stack1::Stack1()
{
    top = NULL;
}

void Stack1::push(int e)
{
    Node *p = new Node;
    if (p == NULL)
    {
        cout << "Out of space" << endl;
        exit(-1);
    }
    p->content = e;
    p->next = top;
    top = p;
    return;
}

void Stack1::pop(int &e)
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    Node *p = top;
    e = p->content;
    top = p->next;
    delete p;
    return;
}