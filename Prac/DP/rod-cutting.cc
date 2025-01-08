#include <iostream>
#include <vector>
using namespace std;

int RodCutting(const std::vector<int> &prices, int length)
{
    // dp[j] 表示长度为j的杆的最大价值
    // dp[j] = max(dp[j] , dp[j-i]+prices[i])
    std::vector<int> dp(length + 1, 0);
    dp[0] = 0;

    // 从1到length，因为0长度的杆价值为0
    // for (int j = 1; j <= length; j++)
    // {
    //     // 对于每个可能的切割点i
    //     for (int i = 0; i < prices.size() && i + 1 <= j; i++)
    //     {
    //         // 更新dp[j]，取当前价值和之前的最大价值中较大的一个
    //         dp[j] = std::max(dp[j], dp[j - i - 1] + prices[i]);
    //     }
    // }

    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = length; j >= i + 1; j--)
        {
            dp[j] = std::max(dp[j], dp[j - i - 1] + prices[i]);
        }
    }

    return dp[length]; // 返回长度为length的杆的最大价值
}

int main()
{
    std::vector<int> prices = {1, 3, 6}; // 价格数组
    int length = 3;                      // 杆的长度
    cout << RodCutting(prices, length) << endl;
    return 0;
}