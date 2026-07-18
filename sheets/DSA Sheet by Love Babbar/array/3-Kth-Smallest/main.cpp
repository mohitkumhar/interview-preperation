/*
https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
Kth Smallest
Difficulty: Medium

Given an integer array nums[] and an integer k, find and return the kth smallest element in the given array.
Note: The kth smallest element is determined based on the sorted order of the array.

Examples :

Input: nums[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
Output: 5
Explanation: 4th smallest element in the given array is 5.

Input: nums[] = [7, 10, 4, 3, 20, 15], k = 3
Output: 7
Explanation: 3rd smallest element in the given array is 7.

Constraints:
1 ≤ nums.size() ≤ 10^5
1 ≤ nums[i] ≤ 10^5
1 ≤ k ≤ nums.size() 

Expected Complexities
Time Complexity: O(n log k)
Auxiliary Space: O(k)

*/

#include <iostream>
#include <vector>

using namespace std;

int find_pivot(int left, int right, vector<int> &nums)
{
    int pivot = nums[left];
    int pivot_idx = left;

    while (left <= right)
    {
        if (nums[left] > pivot && nums[right] < pivot) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
        if (left <= right && nums[left] <= pivot)
            left++;
        if (left <= right && nums[right] >= pivot)
            right--;
    }

    swap(nums[pivot_idx], nums[right]);
    return right;
    

    return 0;
}

int main()
{
    int n;
    cout << "Enter the length of Nums: ";
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element " << i + 1 << ": " ;
        cin >> nums[i];
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int pivot = find_pivot(left, right, nums);

        if (pivot == k - 1) {
            cout << "The Kth smallest elemnt is: " << nums[pivot];
            break;
        }

        if (pivot > k - 1) 
            right = pivot - 1;

        if (pivot < k - 1) 
            left = pivot + 1;
    }

    return 0;
}

