/*
https://www.geeksforgeeks.org/dsa/move-negative-numbers-beginning-positive-end-constant-extra-space/
Move all negative numbers to beginning and positive to end with constant extra space

Given an array containing both positive and negative numbers in random order. The task is to rearrange the array elements so that all negative numbers appear before all positive numbers.

Note:
- Given array does not contain any zeroes.
- Order of resultant array does not matter.

[Naive approach] Using Sorting - O(nlogn) Time and O(1) Space
[Expected Approach] Using Quick Sort Partition - O(n) time and O(1) space

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> nums{-12, 11, -13, -5, 6, -7, 5, -3, -6};

    int i = 0;
    int j = nums.size() - 1;

    while (i < j)
    {
        if (nums[i] > 0 && nums[j] < 0)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        else if (nums[i] < 0)
            i++;
        else if (nums[j] > 0)
            j--;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
