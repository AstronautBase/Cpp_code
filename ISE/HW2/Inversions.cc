#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int> &arr, int left, int mid, int right)
{
    long long inv_count = 0;
    int i = left, j = mid + 1;
    vector<int> temp(right - left + 1);
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (int k = 0; k < temp.size(); k++)
    {
        arr[left + k] = temp[k];
    }

    return inv_count;
}

long long mergeSort(vector<int> &arr, int left, int right)
{
    long long inv_count = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        inv_count += mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);
        inv_count += merge(arr, left, mid, right);
    }
    return inv_count;
}

int main()
{
    long long N;
    cin >> N;

    if (N <= 0)
    {
        return 0;
    }

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    long long inv_count = mergeSort(arr, 0, N - 1);
    cout << inv_count << endl;

    return 0;
}