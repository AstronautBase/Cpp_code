#include <iostream>
#include <stack>
#include <vector>
#include "MonotononicStack.h"
using namespace std;

int MonotononicStack::push(int pos, double height)
{
    // 弹出栈中所有身高小于当前身高的元素
    while (!people.empty() && people.top().height < height)
    {
        people.pop();
    }
    // 如果栈为空，当前人可以看到前面所有的人
    if (people.empty())
    {
        people.push(People(pos, height));
        return pos; // 能看到的前面人数就是当前位置
    }
    else
    {
        int visibleCount = pos - people.top().pos;
        people.push(People(pos, height));
        return visibleCount;
    }
}

int MonotononicStack::top()
{
    if (!people.empty())
    {
        return people.top().pos;
    }
    return -1;
}

void Solve()
{
    int n;
    cin >> n;
    vector<double> heights(n);
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    MonotononicStack ms;
    for (int i = 0; i < n; i++)
    {
        ans[i] = ms.push(i, heights[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    Solve();
    return 0;
}
