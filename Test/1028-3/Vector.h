// Vector.h
// Note: The current file is Vector.h. Please implement each function in the Vector.cpp!
// Note: The current file is Vector.h. Please implement each function in the Vector.cpp!
// Note: The current file is Vector.h. Please implement each function in the Vector.cpp!
#include <iostream>
/*
In this assignment, you will need to implement a simplified
version of std::vector, which supports some modifiers
*/
class Vector
{
public:
    Vector();
    Vector(size_t count, int value = 0);
    Vector(const Vector &v);
    ~Vector();

    Vector &operator=(const Vector &v);

    int &operator[](size_t n);

    size_t size() const;
    size_t capacity() const;

    void push_back(const int &val);
    void pop_back();

private:
    int *arr_;
    size_t sz_;  // the size of vector
    size_t cap_; // the capacity of vector
};