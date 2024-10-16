#include "List.h"
#include <iostream>

List::List() : size_(0)
{
    head.next = &head;
    head.back = &head;
}

List::List(const List &l_) : size_(0)
{
    head.next = &head;
    head.back = &head;

    ListNode *cur = l_.head.next;
    while (cur != &l_.head)
    {
        push_back(cur->e);
        cur = cur->next;
    }
}

List::~List()
{
    while (pop_front())
        ;
}

bool List::push_front(const Element &e)
{
    ListNode *p = new ListNode(e);
    if (!p)
        return false;

    p->next = head.next;
    p->back = &head;
    head.next->back = p;
    head.next = p;
    size_++;

    return true;
}

bool List::push_back(const Element &e)
{
    ListNode *p = new ListNode(e);
    if (!p)
        return false;

    p->next = &head;
    p->back = head.back;
    head.back->next = p;
    head.back = p;
    size_++;

    return true;
}

bool List::pop_front()
{
    if (size_ == 0)
        return false;

    ListNode *p = head.next;
    head.next = p->next;
    head.next->back = &head;
    delete p;
    size_--;
    return true;
}

bool List::pop_back()
{
    if (size_ == 0)
        return false;

    ListNode *p = head.back;
    head.back = p->back;
    head.back->next = &head;
    delete p;
    size_--;
    return true;
}

bool List::remove(const Element &e)
{
    bool flag = false;
    ListNode *cur = head.next;

    while (cur != &head)
    {
        if (cur->e == e)
        {
            ListNode *p = cur;
            cur = cur->next;
            erase(p);
            flag = true;
        }
        else
        {
            cur = cur->next;
        }
    }
    return flag;
}

bool List::insert(const Element &e, ListNode *ln)
{
    ListNode *p = new ListNode(e);
    if (!p)
        return false;

    p->next = ln->next;
    p->back = ln;
    ln->next->back = p;
    ln->next = p;
    size_++;
    return true;
}

void List::erase(ListNode *ln)
{
    if (ln == &head || size_ == 0)
        return;

    ln->back->next = ln->next;
    ln->next->back = ln->back;
    delete ln;
    size_--;
}

ListNode *List::get_item(size_t i)
{
    if (i >= size_)
        return nullptr;

    ListNode *cur = head.next;
    for (size_t index = 0; index < i; ++index)
    {
        cur = cur->next;
    }

    return cur;
}

void List::print()
{
    ListNode *cur = head.next;
    while (cur != &head)
    {
        std::cout << cur->e.num << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}
