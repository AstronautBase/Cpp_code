#include <iomanip>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Matrix2.h"
#include <limits>
using namespace std;

void MYArray::read()
{
    cin >> rows >> cols;
    reshape(rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> data[i][j];
        }
    }
}
void MYArray::reshape(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    data.resize(rows);
    for (int i = 0; i < rows; ++i)
    {
        data[i].resize(cols);
    }
}
MYArray MYArray::operator/(double x)
{
    MYArray result;
    result.reshape(rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result.data[i][j] = data[i][j] / x;
        }
    }
    return result;
}
MYArray MYArray::T()
{
    MYArray result;
    result.reshape(cols, rows);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}
void MYArray::print()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << fixed << setprecision(3) << data[i][j] << " ";
        }
        cout << endl;
    }
}

MYArray MYArray::apply(function<double(double, double)> f, int axis)
{
    // TODO
    MYArray result;

    if (axis == -1)
    {
        double accumulated = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                accumulated = f(data[i][j], accumulated);
            }
        }
        result.reshape(1, 1);
        result.data[0][0] = accumulated;
    }
    else if (axis == 0)
    {
        result.reshape(1, cols);
        for (int j = 0; j < cols; ++j)
        {
            double accumulated = 0;
            for (int i = 0; i < rows; ++i)
            {
                accumulated = f(data[i][j], accumulated);
            }
            result.data[0][j] = accumulated;
        }
    }
    else if (axis == 1)
    {
        result.reshape(rows, 1);
        for (int i = 0; i < rows; ++i)
        {
            double accumulated = 0;
            for (int j = 0; j < cols; ++j)
            {
                accumulated = f(data[i][j], accumulated);
            }
            result.data[i][0] = accumulated;
        }
    }

    return result;
    // END TODO
}

void Solve()
{
    // TODO
    MYArray arr;
    arr.read();
    int type;
    cin >> type;
    switch (type)
    {
    case 1:
    {
        MYArray ans = arr.apply([](double current, double accumulated)
                                { return max(current, accumulated); }, -1);
        ans.print();
        break;
    }
    case 2:
    {
        // *最小值
        MYArray ans = arr.apply([](double current, double accumulated)
                                { return (accumulated == 0 ? current : min(current, accumulated)); }, -1);
        ans.print();
        break;
    }
    case 3:
    {
        MYArray ans = arr.apply([&](double current, double accumulated)
                                { return current + accumulated; }, -1);
        ans = ans / (arr.rows * arr.cols);
        ans.print();
        break;
    }
    case 4:
    {
        MYArray ans = arr.apply([&](double current, double accumulated)
                                { return current + accumulated; }, 1);
        ans = ans / arr.cols;
        ans.T();
        ans.print();
        break;
    }
    case 5:
    {
        MYArray ans = arr.apply([&](double current, double accumulated)
                                { return current + accumulated; }, 0);
        ans = ans / arr.rows;
        ans.print();
        break;
    }
    }
    // END TODO
}
int main()
{
    Solve();
    return 0;
}