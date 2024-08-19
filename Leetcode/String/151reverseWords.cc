#include <string>
#include <stack>
class Solution
{
public:
    std::string reverseWords(std::string s)
    {
        std::stack<std::string> words;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            std::string sub;
            while (i < n && s[i] != ' ')
            {
                sub += s[i];
                i++;
            }

            if (sub != "")
                words.push(sub);
        }
        std::string ans;
        ans = words.top();
        words.pop();
        while (!words.empty())
        {
            ans += " ";
            ans += words.top();
            words.pop();
        }
        return ans;
    }
};