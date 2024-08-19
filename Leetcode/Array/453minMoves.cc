#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int mini = *min_element(nums.begin(), nums.end());
        int res = 0;
        for (auto &x : nums)
        {
            res += x - mini;
        }
        return res;
    }
};