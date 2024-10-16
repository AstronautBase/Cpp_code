#include <iostream>
using namespace std;

class Deque
{
private:
    struct Node
    {
        int data;
        Node *prev;
        Node *next;
    };

    Node *front;
    Node *back;
    size_t count;

public:
    Deque();
    ~Deque();
    void push_front(int x);
    void push_back(int x);
    void pop_front();
    void pop_back();
    size_t size() const;
};

Deque::Deque()
{
    front = nullptr;
    back = nullptr;
    count = 0;
}

Deque::~Deque()
{
    while (front)
    {
        pop_front();
    }
}

void Deque::push_front(int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    if (count == 0)
    {
        front = back = newNode;
    }
    else
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    count++;
}

void Deque::push_back(int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    if (count == 0)
    {
        front = back = newNode;
    }
    else
    {
        newNode->prev = back;
        back->next - newNode;
        back = newNode;
    }
    count++;
}

void Deque::pop_front()
{
    if (count == 0)
        return;
    Node *tmp = front;
    if (front == back)
    {
        front = back = nullptr;
    }
    else
    {
        front = front->next;
        front->prev = nullptr;
    }
    delete tmp;
    count--;
}

void Deque::pop_back()
{
    if (count == 0)
        return;
    Node *tmp = back;
    if (front == back)
    {
        front = back = nullptr;
    }
    else
    {
        back = back->prev;
        back->next = nullptr;
    }
    delete tmp;
    count--;
}

size_t Deque::size() const
{
    return count;
}

// #include <iostream>

// class Matrix
// {
//     int *p_data;
//     int row, col;

// public:
//     Matrix(int r, int c)
//     {
//         if (r <= 0 || c <= 0)
//         {
//             exit(-1);
//         }
//         row = r;
//         col = c;
//         for (int i = 0; i < row * col; i++)
//             p_data[i] = 0;
//     }
//     ~Matrix() { delete[] p_data; }

//     int &element(int i, int j) // 访问矩阵元素
//     {
//         if (i < 0 || i >= row || j < 0 || j >= col)
//         {
//             exit(-1);
//         }
//         return *(p_data + i * col + j);
//     }
//     int element(int i, int j) const
//     {
//         // 重载的特殊情况
//         // 为常量对象提供
//         if (i < 0 || i >= row || j < 0 || j >= col)
//         {
//             exit(-1);
//         }
//         return *(p_data + i * col + j);
//     }

//     int dimension_row() const
//     {
//         return row;
//     }
//     int dimension_column() const
//     {
//         return col;
//     }

//     void input_data()
//     {
//         for (int i = 0; i < row * col; i++)
//             std::cin >> p_data[i];
//     }

//     void display() const
//     {
//         int *p = p_data;
//         for (int i = 0; i < row; i++)
//         {
//             for (int j = 0; j < col; j++)
//             {
//                 std::cout << *p << ' ';
//                 p++;
//             }
//             std::cout << std::endl;
//         }
//     }

//     friend void multiply(const Matrix &m, const Vector &v, Vector &r);
// };

// class Vector
// {
//     int *p_data;
//     int num;

// public:
//     Vector(int n)
//     {
//         if (n <= 0)
//             exit(-1);
//         num = n;
//         p_data = new int[num];
//         for (int i = 0; i < num; i++)
//             p_data[i] = 0;
//     }
//     ~Vector() { delete[] p_data; }

//     int &element(int i)
//     {
//         if (i < 0 || i >= num)
//             exit(-1);
//         return p_data[i];
//     }
//     int element(int i) const
//     {
//         if (i < 0 || i >= num)
//             exit(-1);
//         return p_data[i];
//     }

//     int dimension() const { return num; }
//     void input_data()
//     {
//         for (int i = 0; i < num; i++)
//             std::cin >> p_data[i];
//     }
//     void display() const
//     {
//         int *p = p_data;
//         for (int i = 0; i < num; i++, p++)
//             std::cout << *p << ' ';
//         std::cout << std::endl;
//     }

//     friend void multiply(const Matrix &m, const Vector &v, Vector &r);
// };

// void multiply(const Matrix &m, const Vector &v, Vector &r)
// {
//     if (m.dimension_column() != v.dimension() || m.dimension_row() != r.dimension()) // 判断合法性
//     {
//         std::cerr << "矩阵和向量的尺寸不匹配！\n";
//         exit(-1);
//     }
//     int row = m.dimension_row(), col = m.dimension_column();
//     for (int i = 0; i < row; i++)
//     {
//         r.element(i) = 0;
//         for (int j = 0; j < col; j++) // 计算r[i]
//             r.element(i) += m.element(i, j) * v.element(j);
//     }
// }
