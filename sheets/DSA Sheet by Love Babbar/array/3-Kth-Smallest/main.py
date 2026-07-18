"""
https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
Kth Smallest
Difficulty: Medium

Given an integer array arr[] and an integer k, find and return the kth smallest element in the given array.
Note: The kth smallest element is determined based on the sorted order of the array.

Examples :

Input: arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
Output: 5
Explanation: 4th smallest element in the given array is 5.

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output: 7
Explanation: 3rd smallest element in the given array is 7.

Constraints:
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^5
1 ≤ k ≤ arr.size() 

Expected Complexities
Time Complexity: O(n log k)
Auxiliary Space: O(k)

"""
from typing import List

def find_pivot(left: int, right: int, nums: List[int]):
    pivot = nums[left]
    pivot_idx = left

    while left <= right:
        if nums[left] > pivot and nums[right] < pivot:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1

        if nums[left] <= pivot:
            left += 1

        if nums[right] >= pivot:
            right -= 1

    nums[pivot_idx], nums[right] = nums[right], nums[pivot_idx]

    return right


def kth_smallest_element(nums: List[int], k: int) -> int:

    left = 0
    right = len(nums) - 1

    while left <= right:
        pivot = find_pivot(left, right, nums)
        if pivot == (k - 1):
            return nums[pivot]

        if pivot > (k - 1):
            right = pivot - 1

        if pivot < (k - 1):
            left = pivot + 1

    return -1

nums = list(map(int, input("Enter the elements with space seperated: ").split()))

k = int(input("Enter value of K: "))

element = kth_smallest_element(nums, k)
print(element)
