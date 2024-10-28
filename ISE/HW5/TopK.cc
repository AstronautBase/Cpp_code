#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivotIndex = low + rand() % (high - low + 1);
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]);
    int storeIndex = low;

    for (int i = low; i < high; i++)
    {
        if (arr[i] > pivotValue)
        {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[high]);
    return storeIndex;
}

int randomizedSelect(vector<int> &arr, int low, int high, int K)
{
    if (low == high)
    {
        return arr[low];
    }

    int pivotIndex = partition(arr, low, high);
    int count = pivotIndex - low + 1;

    if (count == K)
    {
        return arr[pivotIndex];
    }
    else if (K < count)
    {
        return randomizedSelect(arr, low, pivotIndex - 1, K);
    }
    else
    {
        return randomizedSelect(arr, pivotIndex + 1, high, K - count);
    }
}

int main()
{
    srand(time(0));

    int K;
    cin >> K;
    vector<int> numbers;
    int x;

    while (cin >> x)
    {
        numbers.push_back(x);
    }

    int N = numbers.size();

    int result = randomizedSelect(numbers, 0, N - 1, K);
    cout << result << endl;

    return 0;
}