#include <iostream>

using namespace std;

int main()
{
    char ans;
    cout << "[Y/N] \n";
    cin >> ans;

    switch (ans)
    {
    case 'Y':
    case 'y':
        cout << "yes";
        break;
    case 'N':
    case 'n':
        cout << "no";
        break;

    default:
        cout << "error";
        break;
    }

    int var = 123;
    int *varp = &var;
    *varp = 124;
    cout << var;

    int array[3] = {10, 5, 3};
    int *p = array;
    cout << *p + 1 << "," << *(p + 1) << endl;

    return 0;
}