#include <vector>
#include <iostream>

using namespace std;

int kindsOfCoins(vector<int> &coins, int amount)
{
    // dp[i] 金额为i时的组合数
    // dp[i] = dp[i] + dp[i-coin]
    // 遍历 coins
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (int coin : coins)
    {
        for (int i = coin; i <= amount; i++)
        {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}

int main()
{
    int a;
    cin >> a;
    vector<int> coins;
    int n;
    while (cin >> n)
    {
        coins.push_back(n);
    }

    cout << kindsOfCoins(coins, a) << endl;
}