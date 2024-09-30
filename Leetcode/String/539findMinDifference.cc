#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    int getMinutes(string &t)
    {
        return (int(t[0] - '0') * 10 + int(t[1] - '0')) * 60 + int(t[3] - '0') * 10 + int(t[4] - '0');
    }

public:
    int findMinDifference(vector<string> &timePoints)
    {
        if (timePoints.size() > 1440)
        {
            return 0;
        }
        sort(timePoints.begin(), timePoints.end());
        int ans = INT_MAX;
        int t0 = getMinutes(timePoints[0]);
        int pre = t0;
        for (int i = 1; i < timePoints.size(); i++)
        {
            int mins = getMinutes(timePoints[i]);
            ans = min(ans, mins - pre);
            pre = mins;
        }
        ans = min(ans, t0 + 1440 - pre);
        return ans;
    }
};