#include <vector>
using namespace std;

int fib(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// 爬楼梯
int climbStairs(int n)
{
    // dp[i] 达到第i阶有dp[i]种方法
    // dp[i] = dp[i-1] + dp[i-2]
    vector<int> dp(n + 1);
    // dp[0] = 1; // 没有实际意义
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

// 最小花费爬楼
int leastCost(vector<int> &cost)
{
    // dp[i] 到达第i阶的最小花费
    // dp[i] = min(dp[i-1] + co st[i-1], dp[i-2]+cost[i-2])
    vector<int> dp(cost.size());
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= cost.size() + 1; i++)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    return dp[cost.size() + 1];
}

// 不同路径
int differentPath(int m, int n)
{
    // dp[i][j] 到达第i行第j列的路径数
    // dp[i][j] = dp[i-1][j] + dp[i][j-1]
    vector<vector<int>> dp(m, vector<int>(n));
    // 初始化边界条件 都只有1种走法
    for (int i = 0; i < m; i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++)
    {
        dp[0][j] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

// 不同路径 有障碍
int differentPath2(int m, int n, vector<vector<int>> &obs)
{
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        if (obs[i][0] == 1)
        {
            break;
        }
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++)
    {
        if (obs[0][j] == 1)
        {
            break;
        }
        dp[0][j] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (obs[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
}

// 整数拆分 使得拆分得到的数乘积最大
int maxMulti(int n)
{
    // dp[i] i拆分得到的最大乘积
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        }
    }
}

// 不同二叉搜索树
int differentSearchTree(int n)
{
    // dp[i] 有i个节点的二叉搜索树的个数
    // 以j为头节点 左边有j-1个 右边有i-j个
    // dp[i] += dp[j-1] * dp[i-j] 有不用的J 所以用+=
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
}