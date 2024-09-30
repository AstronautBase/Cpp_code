#include <iostream>
#include <vector>

class CircularQueue
{
private:
    std::vector<int> queue;
    int front;
    int rear;
    int capacity;
    int size;

public:
    CircularQueue(int N) : capacity(N), front(0), rear(0), size(0)
    {
        queue.resize(capacity);
    }
    void enqueue(int value)
    {
        if (isFull())
        {
            std::cout << "Overflow" << std::endl;
            return;
        }
        queue[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Underflow" << std::endl;
            return;
        }
        int value = queue[front];
        front = (front + 1) % capacity;
        size--;
    }

    void frontElement()
    {
        if (isEmpty())
        {
            std::cout << -1 << std::endl;
            return;
        }
        std::cout << queue[front] << std::endl;
    }

    void rearElement()
    {
        if (isEmpty())
        {
            std::cout << -1 << std::endl;
            return;
        }
        std::cout << queue[(rear - 1 + capacity) % capacity] << std::endl;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }
};

int main()
{
    int N;
    std::cin >> N;
    CircularQueue cq(N); // 创建循环队列

    std::string command;
    while (std::cin >> command)
    {
        if (command == "enqueue")
        {
            int x;
            std::cin >> x;
            cq.enqueue(x);
        }
        else if (command == "dequeue")
        {
            cq.dequeue();
        }
        else if (command == "front")
        {
            cq.frontElement();
        }
        else if (command == "rear")
        {
            cq.rearElement();
        }
        else if (command == "isEmpty")
        {
            std::cout << (cq.isEmpty() ? "True" : "False") << std::endl;
        }
        else if (command == "isFull")
        {
            std::cout << (cq.isFull() ? "True" : "False") << std::endl;
        }
    }
}