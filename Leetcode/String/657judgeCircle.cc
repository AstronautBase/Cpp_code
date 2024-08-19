#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        vector<int> pos(2, 0); // 设置零点
        for (int i = 0; i < moves.size(); i++)
        {
            if (moves[i] == 'U')
            {
                pos[1]++;
            }
            else if (moves[i] == 'D')
            {
                pos[1]--;
            }
            else if (moves[i] == 'L')
            {
                pos[0]--;
            }
            else if (moves[i] == 'R')
            {
                pos[0]++;
            }
        }
        return pos[0] == 0 && pos[1] == 0;
    }
};