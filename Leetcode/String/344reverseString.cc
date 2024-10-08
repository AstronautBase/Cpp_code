#include <vector>

class Solution
{
public:
    void reverseString(std::vector<char> &s)
    {
        int l = 0, r = s.size() - 1;
        while (l <= r)
        {
            char tmp = s[r];
            s[r] = s[l];
            s[l] = tmp;
            l++;
            r--;
        }
    }
};