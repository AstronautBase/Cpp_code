#include <vector>
#include <stdlib.h>
#include <limits>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

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
    int Bigger(int key);
    ~SkipList()
    {
        clear();
        delete head_;
    }

private:
    void clear()
    {
        SkipNode *cur = head_->forward[0];
        while (cur)
        {
            SkipNode *temp = cur;
            cur = cur->forward[0];
            delete temp;
        }
    }

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
        vector<SkipNode *> forward;

        SkipNode(int key, size_t level) : key(key), forward(level, nullptr) {}
    };
    size_t level_;
    SkipNode *head_;
};

void SkipList::add(int key)
{
    if (search(key))
    {
        return;
    }

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

int SkipList::Bigger(int key)
{
    SkipNode *cur = head_;
    int count = 0;
    while (cur->forward[0] != nullptr)
    {
        cur = cur->forward[0];
        if (cur->key > key)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string cmd;
    SkipList list;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num, x;
        scanf("%d %d", &num, &x);
        switch (num)
        {
        case 1:
        {
            // add
            list.add(x);
            break;
        }
        case 2:
        {
            // search
            if (list.search(x))
            {
                printf("0\n");
            }
            else
            {
                printf("1\n");
            }
            break;
        }
        case 3:
        {
            // erase
            list.erase(x);
            break;
        }
        case 4:
        {
            // 大于x的元素个数
            int cnt = list.Bigger(x);
            printf("%d\n", cnt);
        }
        }
    }

    return 0;
}