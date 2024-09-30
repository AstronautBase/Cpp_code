#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class DynamicArray
{
private:
    int *arr;
    int size;
    int capacity;

public:
    DynamicArray(int capacity);
    ~DynamicArray();
    void append(int value);
    void set(int index, int value);
    void erase(int index);
    void get(int index);
    void getSize();
    void getCapacity();
    void print();
};

DynamicArray::DynamicArray(int capacity)
{
    this->capacity = capacity;
    this->size = 0;
    this->arr = new int[this->capacity];
}

DynamicArray::~DynamicArray()
{
    delete[] arr;
}

void DynamicArray::append(int value)
{
    if (size == capacity)
    {
        int *newArr = new int[capacity * 2];
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity *= 2;
    }
    arr[size++] = value;
}

void DynamicArray::set(int index, int value)
{
    if (index >= 0 && index < size)
    {
        arr[index] = value;
    }
}

void DynamicArray::erase(int index)
{
    if (index >= 0 && index < size)
    {
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        if (size > 0 && size <= capacity / 2)
        {
            int *newArr = new int[capacity / 2];
            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            capacity /= 2;
        }
    }
}

void DynamicArray::get(int index)
{
    if (index >= 0 && index < size)
    {
        std::cout << arr[index] << std::endl;
    }
}

void DynamicArray::getSize()
{
    std::cout << size << std::endl;
}

void DynamicArray::getCapacity()
{
    std::cout << capacity << std::endl;
}

void DynamicArray::print()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i < size - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::string command;
    DynamicArray arr(10);
    while (std::getline(std::cin, command))
    {
        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;
        if (cmd == "append")
        {
            int value;
            iss >> value;
            arr.append(value);
        }
        else if (cmd == "set")
        {
            int index, value;
            iss >> index >> value;
            arr.set(index, value);
        }
        else if (cmd == "erase")
        {
            int index;
            iss >> index;
            arr.erase(index);
        }
        else if (cmd == "get")
        {
            int index;
            iss >> index;
            arr.get(index);
        }
        else if (cmd == "size")
        {
            arr.getSize();
        }
        else if (cmd == "capacity")
        {
            arr.getCapacity();
        }
        else if (cmd == "print")
        {
            arr.print();
        }
    }
    return 0;
}