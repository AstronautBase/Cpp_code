// String.cpp
#include "String.h"
#include <string.h>

String::String()
{
    len = 0;
    str_p = new char[1];
    str_p[0] = '\0';
}

String::String(const char *s)
{
    len = strlen(s);
    str_p = new char[len + 1];
    strcpy(str_p, s);
}

String::String(const String &s)
{
    len = s.len;
    str_p = new char[len + 1];
    strcpy(str_p, s.str_p);
}

String::~String()
{
    delete[] str_p;
    str_p = nullptr;
}

void String::print()
{
    cout << str_p << endl;
}

String &String::operator=(const String &s)
{
    if (this == &s)
        return *this;
    delete[] str_p;
    len = s.len;
    str_p = new char[len + 1];
    strcpy(str_p, s.str_p);
    return *this;
}

String &String::operator=(const char *s)
{
    delete[] str_p;
    len = strlen(s);
    str_p = new char[len + 1];
    strcpy(str_p, s);
    return *this;
}

char &String::operator[](int i)
{
    return str_p[i];
}

String String::operator+(const String &s)
{
    String tmp;
    tmp.len = len + s.len;
    tmp.str_p = new char[tmp.len + 1];
    strcpy(tmp.str_p, str_p);
    strcat(tmp.str_p, s.str_p);
    return tmp;
}

bool String::operator==(const String &s)
{
    return strcmp(str_p, s.str_p) == 0;
}

bool String::operator!=(const String &s)
{
    return strcmp(str_p, s.str_p) != 0;
}

bool String::operator<(const String &s)
{
    return strcmp(str_p, s.str_p) < 0;
}

int main()
{
    String s0; // 构造函数
    s0.print();
    // 输出：
    s0 = "abc";
    s0.print();
    String s1(s0); // 构造函数
    s1.print();
    // 输出：abc
    s1.~String(); // 析构函数，s1的析构不会影响s0
    s0.print();
    // 输出：abc
    String s2("d"); // 构造函数
    s2.print();
    // 输出：d
    String s3 = s2; // 重载 =
    s2.~String();   // 析构函数，s2的析构不会影响s3
    s3.print();
    // 输出：d
    String s4 = s3 + s3 + s3; // 重载 +，加法会考察连续+，且加法不会影响加数
    s4.print();
    // 输出：ddd
    cout << s4[2] << endl; // 重载 []
    // 输出：d
    cout << (s4 == s3) << endl; // 重载 ==
    // 输出0
    cout << (s4 != s3) << endl; // 重载 !=
    // 输出1
    cout << (s4 < s3) << endl; // 重载 <
    // 输出0
    return 0;
}