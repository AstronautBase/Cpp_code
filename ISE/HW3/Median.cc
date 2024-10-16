#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int num;
    int i = 0;
    while (cin >> num)
    {

        maxHeap.push(num);

        if (!minHeap.empty() && maxHeap.top() > minHeap.top())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if ((i + 1) % 2 == 1)
        {
            cout << maxHeap.top() << endl;
        }
        else
        {
            cout << maxHeap.top() << endl;
        }
        i++;
    }

    return 0;
}