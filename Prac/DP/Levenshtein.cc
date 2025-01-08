#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 计算字符串s1变换为字符串s2的最小编辑距离
int minDistance(const string &s1, const string &s2)
{
    int m = s1.size();
    int n = s2.size();

    // 创建一个(m+1) x (n+1)的二维DP数组
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // 初始化边界条件
    for (int i = 0; i <= m; ++i)
        dp[i][0] = i; // 删除所有字符
    for (int j = 0; j <= n; ++j)
        dp[0][j] = j; // 插入所有字符

    // 填充DP数组
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1]; // 字符相同，不需要额外操作
            }
            else
            {
                dp[i][j] = min({
                    dp[i - 1][j] + 1,    // 删除字符
                    dp[i][j - 1] + 1,    // 插入字符
                    dp[i - 1][j - 1] + 1 // 替换字符
                });
            }
        }
    }

    // 返回最终的编辑距离
    return dp[m][n];
}

int main()
{
    string s1, s2;
    cout << "请输入第一个字符串: ";
    cin >> s1;
    cout << "请输入第二个字符串: ";
    cin >> s2;

    int result = minDistance(s1, s2);
    cout << "将字符串 \"" << s1 << "\" 转换为 \"" << s2 << "\" 的最小步骤数是: " << result << endl;

    return 0;
}