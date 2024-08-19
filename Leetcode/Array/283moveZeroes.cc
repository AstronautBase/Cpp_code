#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[cnt] = nums[i];
                cnt++;
            }
        }
        for (int i = cnt; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};
