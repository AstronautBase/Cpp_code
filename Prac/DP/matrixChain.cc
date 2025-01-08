#include <iostream>
#include <vector>

using namespace std;

int matrixChain(vector<int> &dimensions)
{
    int n = dimensions.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // dp[i][j] 第i个到第j个矩阵的最小乘法次数
    // dp[i][j] = min(dp[i,j], dp[i][k]+dp[k+1][j]+dimensions[i]*dimensions[k+1]*dimensions[j+1])
    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i <= n - length; i++)
        {
            int j = i + length - 1;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1]);
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    vector<int> dimensions = {10, 20, 30, 40, 30};
    cout << matrixChain(dimensions) << endl;
    return 0;
}