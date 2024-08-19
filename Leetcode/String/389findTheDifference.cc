#include <string>
using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int cs = 0, ct = 0;
        for (char c : s)
        {
            cs += c;
        }
        for (char c : t)
        {
            ct += c;
        }
        return ct - cs;
    }
};