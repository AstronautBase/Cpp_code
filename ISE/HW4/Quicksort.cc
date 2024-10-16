#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// 选定一个 pivot 并将 left 到 right 之间的元素通过 pivot 划分成两部分，然后返回 pivot 的下标
int _partition(vector<int> &nums, int left, int right)
{
    int random_pivot = left + rand() % (right - left + 1);
    swap(nums[random_pivot], nums[right]);

    int pivot = nums[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (nums[j] <= pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[right]);
    return i + 1;
}

// 将 nums 通过 _partition 划分成两部分，对每个部分调用 _quick_sort
void _quick_sort(vector<int> &nums, int left, int right)
{
    if (left < right)
    {
        if (right - left <= 10)
        {
            for (int i = left + 1; i <= right; i++)
            {
                int key = nums[i];
                int j = i - 1;
                while (j >= left && nums[j] > key)
                {
                    nums[j + 1] = nums[j];
                    j--;
                }
                nums[j + 1] = key;
            }
            return;
        }
        int pivotIndex = _partition(nums, left, right);
        _quick_sort(nums, left, pivotIndex - 1);
        _quick_sort(nums, pivotIndex + 1, right);
    }
}

void QuickSort(vector<int> &nums)
{
    _quick_sort(nums, 0, nums.size() - 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // QuickSort(arr);
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}