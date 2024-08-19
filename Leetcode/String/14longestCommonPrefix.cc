#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int minlen = strs[0].size();
        for (string s : strs)
        {
            if (s.size() < minlen)
            {
                minlen = s.size();
            }
        }
        string q = "";
        for (int i = 0; i < minlen; i++)
        {
            char a = strs[0][i];
            for (string s : strs)
            {
                if (s[i] != a)
                {
                    return q;
                }
            }
            q += a;
        }
        return q;
    }

    // ** 优化版
    string longestCommonPrefix(vector<string> &strs)
    {
        for (int i = 0; i < strs[0].size(); i++)
        {
            auto c = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
                if (i == strs[j].size() || strs[j][i] != c)
                    return strs[0].substr(0, i);
        }

        return strs[0];
    }
};