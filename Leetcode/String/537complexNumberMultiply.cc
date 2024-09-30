#include <string>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;

class Solution
{
    pair<int, int> s2complex(string s)
    {
        auto add_index = s.find('+');
        return {stoi(s.substr(0, add_index)), stoi(s.substr(add_index + 1, s.length() - 2 - add_index))};
    }

public:
    string complexNumberMultiply(string num1, string num2)
    {
        regex re("\\+|i");
        vector<string> complex1(sregex_token_iterator(num1.begin(), num1.end(), re, -1), std::sregex_token_iterator());
        vector<string> complex2(sregex_token_iterator(num2.begin(), num2.end(), re, -1), std::sregex_token_iterator());
        int real1 = stoi(complex1[0]);
        int imag1 = stoi(complex1[1]);
        int real2 = stoi(complex2[0]);
        int imag2 = stoi(complex2[1]);
        return to_string(real1 * real2 - imag1 * imag2) + "+" + to_string(real1 * imag2 + imag1 * real2) + "i";
    }
    // 法二
    string complexNumberMultiply(string num1, string num2)
    {
        auto complex1 = s2complex(num1);
        auto complex2 = s2complex(num2);
        int real = complex1.first * complex2.first - complex1.second * complex2.second;
        int vir = complex1.first * complex2.second + complex1.second * complex2.first;
        return to_string(real) + "+" + to_string(vir) + "i";
    }
};