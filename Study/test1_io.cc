#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    // 读取
    ifstream in;
    in.open("test.txt");
    // ifstream in("test.txt");
    if (!in)
    {
        cerr << "fail" << endl;
        return 0;
    }

    char x;
    while (in >> x)
    {
        cout << x;
    }

    cout << endl;
    in.close();

    // 写入
    ofstream out("test.txt", ios::app);
    if (!out)
    {
        cerr << "fail" << endl;
        return 0;
    }

    for (int i = 10; i > 0; i--)
    {
        out << i;
    }
    out << endl;
    out.close();

    return 0;
}