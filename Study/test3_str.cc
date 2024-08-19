#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    // cin >> str; // 遇到空格会自动中止
    getline(cin, str);
    cout << str;

    int len = str.size(); // str.length()
    cout << str.empty();  // 判断是否为空

    // cctype
    isalnum(str[0]);
    isalpha(str[0]);
    // digit / lower / upper / space
    toupper(str[0]);

    // 遍历
    string s1 = "nice to meet you~";
    for (auto &c : s1)
        c = toupper(c);
    cout << s1 << endl;

    s1.insert(0, "1");
    // append / erase(pos, len) / replace(3, 6, "a")
    s1.find("i");  // 第一次出现
    s1.rfind("i"); // 最后一次出现

    string s = to_string(123);

    string s2 = "11"; // 初始化一个空字符串
    int a1 = stoi(s2);

    // algorithm头文件的reverse
    reverse(s2.begin(), s2.end()); // 翻转

    return 0;
}