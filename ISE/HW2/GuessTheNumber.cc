#include <iostream>
#include <string>

using namespace std;

int main()
{
    unsigned long long left = 0;
    unsigned long long right = 2e64;
    int guessCount = 0;

    while (true)
    {
        guessCount++;
        unsigned long long mid = left + (right - left) / 2;
        cout << mid << endl
             << flush;

        string response;
        cin >> response;

        if (response == "TooBig")
        {
            right = mid - 1;
        }
        else if (response == "TooSmall")
        {
            left = mid + 1;
        }
        else if (response == "Correct")
        {
            return 0;
        }
        else if (response == "GameOver")
        {
            return 0;
        }

        if (guessCount > 75)
        {
            return 0;
        }
    }
    return 0;
}