#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<int, int> freq;
        for (char c : magazine)
        {
            ++freq[c];
        }
        for (char c : ransomNote)
        {
            --freq[c];
            if (freq[c] < 0)
                return false;
        }
        return true;
    }
};