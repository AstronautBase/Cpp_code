#include <iostream>
#include <string>

class LinkedList
{
public:
    struct Node
    {
        int data;
        Node *next;
    };

    Node *head;
    Node *tail;
    int size;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void push_back(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void push_front(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = head;

        if (head == nullptr)
        {
            tail = newNode;
        }
        head = newNode;
    }

    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void search(int value)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                std::cout << 1 << std::endl;
                return;
            }
            current = current->next;
        }
        std::cout << 0 << std::endl;
    }

    void remove(int value)
    {
        Node *current = head;
        Node *previous = nullptr;

        while (current != nullptr)
        {
            if (current->data == value)
            {
                if (previous == nullptr)
                {
                    head = current->next;
                }
                else
                {
                    previous->next = current->next;
                }
                delete current;
                size--;
                return;
            }
            previous = current;
            current = current->next;
        }
    }
};

int main()
{
    LinkedList list;
    std::string cmd;

    while (std::cin >> cmd)
    {
        if (cmd == "pushFront")
        {
            int value;
            std::cin >> value;
            list.push_front(value);
        }
        else if (cmd == "pushBack")
        {
            int value;
            std::cin >> value;
            list.push_back(value);
        }
        else if (cmd == "print")
        {
            list.print();
        }
        else if (cmd == "search")
        {
            int value;
            std::cin >> value;
            list.search(value);
        }
        else if (cmd == "remove")
        {
            int value;
            std::cin >> value;
            list.remove(value);
        }
    }
}