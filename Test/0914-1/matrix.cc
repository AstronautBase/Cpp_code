#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct MYArray
{
    int rows, cols;
    vector<vector<double>> data;
};

void reshape(int rows, int cols, MYArray &arr)
{
    arr.rows = rows;
    arr.cols = cols;
    arr.data.resize(rows);
    for (int i = 0; i < rows; ++i)
    {
        arr.data[i].resize(cols);
    }
}
void read(MYArray &arr)
{
    // TODO
    cin >> arr.rows >> arr.cols;
    reshape(arr.rows, arr.cols, arr);
    for (int i = 0; i < arr.rows; ++i)
    {
        for (int j = 0; j < arr.cols; ++j)
        {
            cin >> arr.data[i][j];
        }
    }
    // END TODO
}

MYArray divide(double x, MYArray &arr)
{
    // TODO
    MYArray result;
    for (int i = 0; i < arr.rows; ++i)
    {
        for (int j = 0; j < arr.cols; ++j)
        {
            result.data[i][j] = arr.data[i][j] / x;
        }
    }
    return result;
    // END TODO
}

MYArray T(MYArray &arr)
{
    MYArray result;
    reshape(arr.cols, arr.rows, result);
    for (int i = 0; i < arr.rows; ++i)
    {
        for (int j = 0; j < arr.cols; ++j)
        {
            result.data[j][i] = arr.data[i][j];
        }
    }
    return result;
}
void print(MYArray &arr)
{
    for (int i = 0; i < arr.rows; ++i)
    {
        for (int j = 0; j < arr.cols; ++j)
        {
            cout << fixed << setprecision(3) << arr.data[i][j] << " ";
        }
        cout << endl;
    }
}

MYArray apply(function<double(double, double)> f, int axis, MYArray &arr)
{
    // TODO
    // END TODO
}

void Solve()
{
    // TODO
    MYArray arr;
    read(arr);
    int type;
    cin >> type;
    switch (type)
    {
    case 1:
    {
        // * 输出最大身高
        double res = 0;
        for (int i = 0; i < arr.rows; ++i)
        {
            for (int j = 0; j < arr.cols; ++j)
            {
                res = arr.data[i][j] > res ? arr.data[i][j] : res;
            }
        }
        cout << fixed << setprecision(3) << res << endl;
        break;
    }
    case 2:
    {
        // * 输出最小身高
        double res = 200;
        for (int i = 0; i < arr.rows; ++i)
        {
            for (int j = 0; j < arr.cols; ++j)
            {
                res = arr.data[i][j] < res ? arr.data[i][j] : res;
            }
        }
        cout << fixed << setprecision(3) << res << endl;
        break;
    }
    case 3:
    {
        // * 输出平均身高
        double res = 0;
        for (int i = 0; i < arr.rows; ++i)
        {
            for (int j = 0; j < arr.cols; ++j)
            {
                res += arr.data[i][j];
            }
        }
        cout << fixed << setprecision(3) << res / arr.rows / arr.cols << endl;
        break;
    }
    case 4:
    {
        // * 输出每行平均身高
        for (int i = 0; i < arr.rows; ++i)
        {
            double res = 0;
            for (int j = 0; j < arr.cols; ++j)
            {
                res += arr.data[i][j];
            }
            cout << fixed << setprecision(3) << res / arr.cols << " ";
        }
        cout << endl;
        break;
    }
    case 5:
    {
        // * 输出每列平均身高
        for (int i = 0; i < arr.cols; ++i)
        {
            double res = 0;
            for (int j = 0; j < arr.rows; ++j)
            {
                res += arr.data[j][i];
            }
            cout << fixed << setprecision(3) << res / arr.rows << " ";
        }
        cout << endl;
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