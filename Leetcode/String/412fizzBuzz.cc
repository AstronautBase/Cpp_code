#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans;
        for (int i = 1; i <= n; i++)
        {
            string tmp;
            if (i % 3 == 0)
                tmp += "Fizz";
            if (i % 5 == 0)
                tmp += "Buzz";
            if (tmp.size() == 0)
                tmp += to_string(i);
            ans.emplace_back(tmp);
        }
        return ans;
    }
};