#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class MYArray
{
private:
    vector<vector<double>> data;
    void reshape(int rows, int cols);

public:
    int rows, cols;
    void read();
    void print();
    MYArray apply(function<double(double, double)> f, int axis = -1);
    MYArray applySub(function<double(double, double)> f, int axis = -1);
    MYArray operator/(double x);
    MYArray T();
};