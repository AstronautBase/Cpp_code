#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool checkRecord(string s)
    {
        int a = 0, l = 0;
        for (char c : s)
        {
            if (c == 'A')
            {
                a++;
                if (a >= 2)
                    return false;
            }
            if (c == 'L')
            {
                l++;
                if (l >= 3)
                    return false;
            }
            else
            {
                l = 0;
            }
        }
        return true;
    }
};