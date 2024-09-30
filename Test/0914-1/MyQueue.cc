// MyQueue.cpp
#include "MyQueue.h"

MyQueue::MyQueue()
{
    // TODO
    top = NULL;
}

// 元素从队尾入队
void MyQueue::push(char c)
{
    // TODO
    Node *p = new Node;
    p->content = c;
    p->next = NULL;
    if (top == NULL)
    {
        top = p;
    }
    else
    {
        Node *q = top;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}

// 队首元素出队，返回出队的元素（我们没有定义空队列pop操作，测试用例中不会涉及）
char MyQueue::pop()
{
    char result;
    // TODO
    if (top != NULL)
    {
        Node *p = top;
        top = top->next;
        result = p->content;
        delete p;
    }
    return result;
}

// 返回队列的大小（队列内元素的个数）
int MyQueue::size()
{
    int result;
    // TODO
    Node *p = top;
    result = 0;
    while (p != NULL)
    {
        result++;
        p = p->next;
    }
    return result;
}