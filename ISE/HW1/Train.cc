#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

string can_schedule_trains(const vector<int> &sequence)
{
    stack<int> s;
    int next_train = 1; // 下一辆入站的火车编号

    for (int train : sequence)
    {
        // 将火车入栈直到栈顶的车等于当前目标车
        while (next_train <= train)
        {
            s.push(next_train);
            next_train++;
        }

        // 检查栈顶的火车是否等于当前车
        if (!s.empty() && s.top() == train)
        {
            s.pop(); // 出站
        }
        else
        {
            return "NO"; // 无法按照给定顺序出站
        }
    }

    return "YES"; // 所有火车都可以按照顺序出站
}

int main()
{
    // 输入部分
    string line;
    getline(cin, line);
    vector<int> sequence;
    int number;

    // 读取输入
    stringstream ss(line);
    while (ss >> number)
    {
        sequence.push_back(number);
    }

    // 处理并输出结果
    cout << can_schedule_trains(sequence) << endl;

    return 0;
}