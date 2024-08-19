#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int len = s.size() - 1;
        int cnt = 0;

        // 从字符串尾部开始遍历
        while (len >= 0 && s[len] == ' ')
        {
            len--; // 跳过尾部的空格
        }

        // 计算最后一个单词的长度
        while (len >= 0 && s[len] != ' ')
        {
            cnt++;
            len--;
        }

        return cnt;
    }
};
