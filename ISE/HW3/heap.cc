#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class MinHeap
{
public:
    MinHeap() : insert_cnt(0) {};
    void push(int x);
    int pop();
    int top();
    int size();
    void decrease(int i, int k);

private:
    vector<int> heap;
    vector<int> indices;
    int insert_cnt;
    void heapify_up(int index);
    void heapify_down(int index);
};

void MinHeap::push(int x)
{
    heap.push_back(x);
    indices.push_back(insert_cnt++);
    heapify_up(heap.size() - 1);
}

int MinHeap::pop()
{
    int min = heap[0];
    heap[0] = heap.back();
    indices[0] = indices.back();
    heap.pop_back();
    indices.pop_back();
    heapify_down(0);
    return min;
}

int MinHeap::top()
{
    return heap[0];
}

int MinHeap::size()
{
    return heap.size();
}

void MinHeap::decrease(int i, int k)
{
    int index;
    for (int j = 0; j < indices.size(); j++)
    {
        if (indices[j] == i - 1)
        {
            index = j;
            break;
        }
    }

    heap[index] = k;
    heapify_up(index);
}

void MinHeap::heapify_up(int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent])
        {
            swap(heap[index], heap[parent]);
            swap(indices[index], indices[parent]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void MinHeap::heapify_down(int index)
{
    int size = heap.size();
    while (index < size)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
        if (left < size && heap[left] < heap[smallest])
        {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest])
        {
            smallest = right;
        }
        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            swap(indices[index], indices[smallest]);
            index = smallest;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    string command;
    MinHeap heap;
    while (cin >> command)
    {
        if (command == "push")
        {
            int x;
            cin >> x;
            heap.push(x);
        }
        else if (command == "pop")
        {
            heap.pop();
        }
        else if (command == "top")
        {
            cout << heap.top() << endl;
        }
        else if (command == "size")
        {
            cout << heap.size() << endl;
        }
        else if (command == "decrease")
        {
            int i, k;
            cin >> i >> k;
            heap.decrease(i, k);
        }
    }
    return 0;
}