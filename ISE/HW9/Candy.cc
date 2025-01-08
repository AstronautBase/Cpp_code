#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCandies(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> candy(n, 1);
    int totalCandies = n;

    for (int i = 1; i < n; ++i)
    {
        if (ratings[i] > ratings[i - 1] && candy[i] <= candy[i - 1])
        {
            candy[i] = candy[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; --i)
    {
        if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1])
        {
            candy[i] = candy[i + 1] + 1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        totalCandies += candy[i] - 1;
    }

    return totalCandies;
}

int main()
{
    int n;
    vector<int> ratings;
    while (cin >> n)
    {
        ratings.push_back(n);
    }

    cout << minCandies(ratings) << endl;

    return 0;
}