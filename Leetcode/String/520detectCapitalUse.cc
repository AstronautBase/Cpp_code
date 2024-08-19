#include <ctype.h>
#include <string>

class Solution
{
public:
    bool detectCapitalUse(std::string word)
    {
        int num = word.size();
        if (num >= 2 && islower(word[0]) && isupper(word[1]))
        {
            return false;
        }
        for (int i = 2; i < num; i++)
        {
            if (islower(word[i]) ^ islower(word[1]))
            {
                return false;
            }
        }
        return true;
    }
};