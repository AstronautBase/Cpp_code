#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class TwoStackOneQueue
{
private:
    stack<int> A;
    stack<int> B;
    vector<string> operations;

    void transferToB()
    {
        while (!A.empty())
        {
            B.push(A.top());
            A.pop();
            operations.push_back("move A B");
        }
    }

public:
    void enqueue()
    {
        A.push(0);
        operations.push_back("push A");
    }

    void dequeue()
    {
        if (B.empty())
        {
            transferToB();
        }

        if (!B.empty())
        {
            B.pop();
            operations.push_back("pop B");
        }
    }

    void print()
    {
        for (string operation : operations)
        {
            cout << operation << endl;
        }
    }
};

int main()
{
    TwoStackOneQueue queue;
    string cmd;
    while (cin >> cmd)
    {
        if (cmd == "enqueue")
        {
            queue.enqueue();
        }
        else if (cmd == "dequeue")
        {
            queue.dequeue();
        }
    }
    queue.print();
    return 0;
}