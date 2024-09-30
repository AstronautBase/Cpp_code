#include <stack>
using namespace std;

class MonotononicStack
{
private:
    class People
    {
    public:
        int pos;
        double height;
        People(int pos, double height) : pos(pos), height(height) {}
    };
    stack<People> people;

public:
    int push(int pos, double height);
    int top();
};