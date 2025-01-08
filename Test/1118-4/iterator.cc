#include <iostream>

class MyArray
{
    int *arr;
    int size;
    bool isDestroyed;

public:
    class Iterator
    {
        int *ptr;
        MyArray *myArray;

    public:
        Iterator(int *ptr, MyArray *myArray) : ptr(ptr), myArray(myArray) {}

        bool get(int &value) const
        {
            if (myArray && !myArray->isDestroyed && ptr >= myArray->arr && ptr < myArray->arr + myArray->size)
            {
                value = *ptr;
                return true;
            }
            return false;
        }

        bool put(int value)
        {
            if (myArray && !myArray->isDestroyed && ptr >= myArray->arr && ptr < myArray->arr + myArray->size)
            {
                *ptr = value;
                return true;
            }
            return false;
        }

        // 前置++
        Iterator &operator++()
        {
            if (myArray && !myArray->isDestroyed && ptr < myArray->arr + myArray->size)
            {
                ++ptr;
            }
            return *this;
        }

        // 后置++
        Iterator operator++(int)
        {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        // 前置--
        Iterator &operator--()
        {
            if (myArray && !myArray->isDestroyed && ptr > myArray->arr)
            {
                --ptr;
            }
            return *this;
        }

        // 后置--
        Iterator operator--(int)
        {
            Iterator temp = *this;
            --(*this);
            return temp;
        }

        bool operator==(const Iterator &other) const
        {
            return ptr == other.ptr && myArray == other.myArray;
        }

        bool operator!=(const Iterator &other) const
        {
            return !(*this == other);
        }

        Iterator operator+(int len)
        {
            Iterator temp = *this;
            if (myArray && !myArray->isDestroyed)
            {
                int *newPtr = temp.ptr + len;
                if (newPtr < myArray->arr + myArray->size)
                {
                    temp.ptr = newPtr;
                }
                else
                {
                    temp.ptr = myArray->arr + myArray->size;
                }
            }
            return temp;
        }

        Iterator operator-(int len)
        {
            Iterator temp = *this;
            if (myArray && !myArray->isDestroyed)
            {
                int *newPtr = temp.ptr - len;
                if (newPtr >= myArray->arr)
                {
                    temp.ptr = newPtr;
                }
                else
                {
                    temp.ptr = myArray->arr;
                }
            }
            return temp;
        }
    };

    MyArray(int sz) : size(sz), isDestroyed(false), arr(sz > 0 ? new int[sz] : nullptr) {}

    ~MyArray()
    {
        delete[] arr;
        isDestroyed = true;
    }

    Iterator begin()
    {
        return Iterator(arr, this);
    }

    Iterator end()
    {
        return Iterator(arr + size, this);
    }
};

int main()
{
    MyArray ma(5); // 创建一个包含5个元素的MyArray
    // MyArray::Iterator iter;

    // 使用迭代器初始化所有元素
    for (MyArray::Iterator iter = ma.begin(); iter != ma.end(); ++iter)
    {
        iter.put(0); // 初始化所有元素为0
    }

    // 使用迭代器修改元素值
    for (MyArray::Iterator iter = ma.begin(); iter != ma.end(); ++iter)
    {
        int v = 0;
        iter.put(iter.get(v) + 10); // 将所有元素增加10
    }

    // 使用迭代器遍历并打印所有元素
    std::cout << "Elements of MyArray:" << std::endl;
    for (MyArray::Iterator iter = ma.begin(); iter != ma.end(); ++iter)
    {
        int v;
        if (iter.get(v))
        {
            std::cout << v << " "; // 打印出v的值
        }
    }
    std::cout << std::endl;

    return 0;
    // int v = -1;
    // bool res = iter.get(v); // true, v=20
}