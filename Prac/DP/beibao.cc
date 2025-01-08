#include <vector>
#include <iostream>
using namespace std;

int beibao01(vector<int> &w, vector<int> &v, int maxWeight)
{
    // dp[i][j] 前i个物品，背包重量为j的最大价值
    // 不放物品i dp[i][j] = dp[i-1][j]
    // 放物品i dp[i][j] = dp[i-1][j-w[i]] + v[i]  不放物品i且减去物品i的重量 加上物品i的价值
    int n = w.size();
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= maxWeight; j++)
    {
        if (j < w[0])
        {
            dp[0][j] = 0;
        }
        else
        {
            dp[0][j] = v[0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            if (j < w[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    return dp[n - 1][maxWeight];
}

// 0-1背包问题 滚动数组方法 一维dp
int beibao01_2(vector<int> &w, vector<int> &v, int maxWeight)
{
    // dp[j] 背包重量为j的最大价值
    // dp[j] = max(dp[j], dp[j-w[i]] + v[i]) 第一个相当于不放i 拷贝上一份数据  第二个放i 不放i的重量的dp加上i的价值
    vector<int> dp(maxWeight + 1);
    int n = w.size();
    dp[0] = 0;
    for (int weight : w)
    {
        for (int j = maxWeight; j >= weight; j--)
        {
            dp[j] = max(dp[j], dp[j - weight] + v[weight]);
        }
    }
    return dp[maxWeight];
}

int main()
{
    vector<int> w = {1, 3, 4};
    vector<int> v = {15, 20, 30};
    int maxWeight = 4;
    cout << beibao01(w, v, maxWeight) << endl;
}