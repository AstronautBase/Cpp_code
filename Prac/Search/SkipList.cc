#include <vector>
#include <stdlib.h>
#include <limits>
#include <iostream>

class SkipList
{
public:
    SkipList(size_t level = 4) : level_(level)
    {
        head_ = new SkipNode(-1, level);
    }
    bool search(int key);
    void add(int key);
    bool erase(int key);
    void print();

private:
    size_t RandomLevel()
    {
        size_t level = 1;
        while (rand() % 2)
        {
            level++;
        }
        return level > level_ ? level_ : level;
    }
    struct SkipNode
    {
        int key;
        std::vector<SkipNode *> forward;

        SkipNode(int key, size_t level) : key(key), forward(level, nullptr) {}
    };
    size_t level_;
    SkipNode *head_;
};

void SkipList::add(int key)
{
    size_t level = RandomLevel();
    SkipNode *node = new SkipNode(key, level);
    SkipNode *cur = head_;

    for (int i = level_ - 1; i >= 0; i--)
    {
        while (cur->forward[i] && cur->forward[i]->key < key)
        {
            cur = cur->forward[i];
        }
        if (i < level)
        {
            node->forward[i] = cur->forward[i];
            cur->forward[i] = node;
        }
    }
}

bool SkipList::search(int key)
{
    SkipNode *cur = head_;
    for (int i = level_ - 1; i >= 0; i--)
    {
        while (cur->forward[i] && cur->forward[i]->key < key)
        {
            cur = cur->forward[i];
        }
        if (cur->forward[i] && cur->forward[i]->key == key)
        {
            return true;
        }
    }
    return false;
}

bool SkipList::erase(int key)
{
    SkipNode *cur = head_;
    SkipNode *node = nullptr;
    for (int i = level_ - 1; i >= 0; i--)
    {
        while (cur->forward[i] && cur->forward[i]->key < key)
        {
            cur = cur->forward[i];
        }
        if (cur->forward[i] && cur->forward[i]->key == key)
        {
            node = cur->forward[i];
            cur->forward[i] = node->forward[i];
        }
    }
    if (node == nullptr)
    {
        return false;
    }
    else
    {
        delete node;
        node = nullptr;
        return true;
    }
}

void SkipList::print()
{
    for (int i = level_ - 1; i >= 0; i--)
    {
        SkipNode *cur = head_->forward[i];
        while (cur)
        {
            std::cout << cur->key << "\t";
            cur = cur->forward[i];
        }
        std::cout << std::endl;
    }
}
int main()
{
    SkipList skip_list;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        skip_list.add(rand() % 100);
    }
    // skip_list.add(10);
    // skip_list.add(22);
    // skip_list.add(13);
    // skip_list.add(44);
    // skip_list.add(15);
    // skip_list.add(6);
    skip_list.print();
}