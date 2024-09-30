#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

double distance(const vector<int> &p1, const vector<int> &p2)
{
    return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
}

double stripClosest(vector<vector<int>> points, double d)
{
    double minDist = d;
    sort(points.begin(), points.end(), [](const vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });

    for (int i = 0; i < points.size(); i++)
    {
        for (int j = 0; j < points.size() && points[j][1] - points[i][1] < minDist; j++)
        {
            minDist = min(minDist, distance(points[i], points[j]));
        }
    }
    return minDist;
}

double closestUtil(vector<vector<int>> &points, int left, int right)
{
    if (right - left <= 3)
    {
        double minDist = numeric_limits<double>::max();
        for (int i = left; i < right; i++)
        {
            for (int j = i + 1; j < right; j++)
            {
                minDist = min(minDist, distance(points[i], points[j]));
            }
        }
    }

    int mid = left + (right - left) / 2;
    double d1 = closestUtil(points, left, mid);
    double d2 = closestUtil(points, mid, right);
    double d = min(d1, d2);

    vector<vector<int>> strip;
    for (int i = left; i < right; i++)
    {
        if (abs(points[i][0] - points[mid][0]) < d)
        {
            strip.push_back(points[i]);
        }
    }

    return min(d, stripClosest(strip, d));
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0];
        cin >> points[i][1];
    }

    sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });
    double minDist = closestUtil(points, 0, n);
    cout << fixed << setprecision(4) << minDist << endl;
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <limits>
// #include <iomanip>
// #include <cmath>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> points(n, vector<int>(2));
//     for (int i = 0; i < n; i++)
//     {
//         cin >> points[i][0];
//         cin >> points[i][1];
//     }

//     double min = _I64_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             double distance = sqrt(pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2));
//             if (distance < min)
//             {
//                 min = distance;
//             }
//         }
//     }

//     cout << fixed << setprecision(4) << min << endl;
// }