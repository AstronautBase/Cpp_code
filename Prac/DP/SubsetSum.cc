#include <vector>
#include <iostream>

using namespace std;

int SubsetSum(vector<int> &arr, int s)
{
    // dp[i] 数组中元素是否能构成i
    // dp[i] = dp[i] || dp[i - arr[j]]
    vector<bool> dp(arr.size() + 1);
    dp[0] = false;
    for (int a : arr)
    {
        for (int j = s; j >= a; j--)
        {
            dp[j] = dp[j] || dp[j - a];
        }
    }
}