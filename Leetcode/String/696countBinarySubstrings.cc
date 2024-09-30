#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int ptr = 0, n = s.size(), last = 0, ans = 0;
        while (ptr < n)
        {
            char c = s[ptr];
            int cnt = 0;
            while (ptr < n && s[ptr] == c)
            {
                ++ptr;
                ++cnt;
            }
            ans += min(cnt, last);
            last = cnt;
        }
        return ans;
    }
};