#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> arr;
    int sum = 0;
    while (cin >> n)
    {
        arr.push_back(n);
        sum += n;
    }
    if (sum % 2 != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int target = sum / 2;
    // dp[i] 数组中的元素是否能组成和为i
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int a : arr)
    {
        for (int j = target; j >= a; j--)
        {
            dp[j] = dp[j] || dp[j - a];
        }
    }

    if (dp[target])
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}