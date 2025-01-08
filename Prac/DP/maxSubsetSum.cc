#include <vector>
#include <iostream>

using namespace std;

int maxSubsetSum(vector<int> &nums)
{
    // dp[i] 以nums[i]为结尾的最大连续子序列的和
    // dp=[i] = max(dp[i-1]+nums[i], nums[i]) 要么沿着前面的子序列，要么重新开始
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    }

    int res = dp[0];
    for (int d : dp)
    {
        if (d > res)
            res = d;
    }
    return res;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubsetSum(nums) << endl;
    return 0;
}