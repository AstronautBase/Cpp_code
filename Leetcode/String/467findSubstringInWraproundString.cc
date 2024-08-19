#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int findSubstringInWraproundString(string s)
    {
        vector<int> dp(26);
        int k = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (i && (s[i] - s[i - 1] + 26) % 26 == 1)
            {
                k++;
            }
            else
            {
                k = 1;
            }
            dp[s[i] - 'a'] = max(dp[s[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};