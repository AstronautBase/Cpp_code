#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int a = 0, b = 0;
        vector<int> cntS(10), cntG(10);
        for (int i = 0; i < secret.length(); i++)
        {
            if (secret[i] == guess[i])
            {
                a++;
            }
            else
            {
                ++cntS[secret[i] - '0'];
                ++cntG[guess[i] - '0'];
            }
        }
        for (int i = 0; i < 10; i++)
        {
            b += min(cntS[i], cntG[i]);
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};
