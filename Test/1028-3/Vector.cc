// Vector.cpp
#include "Vector.h"

Vector::Vector()
{
    arr_ = new int(1);
    arr_[0] = '\0';
    sz_ = 0;
    cap_ = 1;
}

Vector::Vector(size_t count, int value)
{
    arr_ = new int[count];
    for (size_t i = 0; i < count; ++i)
    {
        arr_[i] = value;
    }
    sz_ = count;
    cap_ = count;
}

Vector::Vector(const Vector &v)
{
    sz_ = v.sz_;
    cap_ = v.cap_;
    arr_ = new int[cap_];
    for (size_t i = 0; i < sz_; ++i)
    {
        arr_[i] = v.arr_[i];
    }
}

Vector::~Vector()
{
    delete[] arr_;
    arr_ = nullptr;
}

Vector &Vector::operator=(const Vector &v)
{
    if (this == &v)
        return *this;
    delete[] arr_;
    sz_ = v.sz_;
    cap_ = v.cap_;
    arr_ = new int[cap_];
    for (size_t i = 0; i < sz_; ++i)
    {
        arr_[i] = v.arr_[i];
    }
    return *this;
}

int &Vector::operator[](size_t n)
{
    return arr_[n];
}

size_t Vector::size() const
{
    return sz_;
}

size_t Vector::capacity() const
{
    return cap_;
}

void Vector::push_back(const int &val)
{
    if (arr_ == nullptr)
    {
        arr_ = new int[1];
        arr_[0] = val;
        sz_ = 1;
        cap_ = 1;
    }
    if (sz_ == cap_)
    {
        int *new_arr = new int[cap_ * 2];
        for (size_t i = 0; i < sz_; ++i)
        {
            new_arr[i] = arr_[i];
        }
        delete[] arr_;
        arr_ = new_arr;
        cap_ *= 2;
    }
    arr_[sz_++] = val;
}

void Vector::pop_back()
{
    if (sz_ == 0)
        return;
    sz_--;
    int *new_arr = new int[cap_];
    for (size_t i = 0; i < sz_; ++i)
    {
        new_arr[i] = arr_[i];
    }
}

int main()
{
    Vector v;       // sz_ = 0, cap_ = 0, arr_ = nullptr
    v.push_back(1); // sz_ = 1, cap_ = 1, arr_ = [1]
    v.push_back(2); // sz_ = 2, cap_ = 2, arr_ = [1, 2]
    v.pop_back();   // sz_ = 1, cap_ = 2, arr_ = [1]

    Vector v3(2, 0); // sz_ = 2, cap_ = 2, arr_ = [0, 0]
    v3.push_back(1); // sz_ = 3, cap_ = 4, arr_ = [0, 0, 1]

    Vector v1(3, 2); // sz_ = 3, cap_ = 3, arr_ = [2, 2, 2]
    Vector v2 = v1;  // sz_ = 3, cap_ = 3, arr_ = [2, 2, 2]
    v1[0] = 1;       // v1: [1, 2, 2], v2: [2, 2, 2]
    return 0;
}