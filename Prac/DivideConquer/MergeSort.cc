#include <vector>
#include <iostream>
#include <deque>

using namespace std;

void merge(vector<int> &arr, int left, int right, int mid)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
        }
        k++;
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, right, mid);
    }
}

vector<int> iter_merge(const vector<int> &left, const vector<int> &right)
{
    vector<int> res;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            res.push_back(left[i]);
            i++;
        }
        else
        {
            res.push_back(right[j]);
            j++;
        }
    }

    res.insert(res.end(), left.begin() + i, left.end());
    res.insert(res.end(), right.begin() + j, right.end());
    return res;
}

vector<int> iter_mergeSort(vector<int> &arr)
{
    deque<vector<int>> queue;
    for (int i = 0; i < arr.size(); i++)
    {
        vector<int> arr = {arr[i]};
        queue.push_back(arr);
    }

    while (queue.size() > 1)
    {
        vector<int> left = queue.front();
        queue.pop_front();
        vector<int> right = queue.front();
        queue.pop_front();
        vector<int> merged = iter_merge(left, right);
        queue.push_back(merged);
    }

    return queue.front();
}