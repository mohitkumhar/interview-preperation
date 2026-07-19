"""
https://www.geeksforgeeks.org/dsa/move-negative-numbers-beginning-positive-end-constant-extra-space/
Move all negative numbers to beginning and positive to end with constant extra space

Given an array containing both positive and negative numbers in random order. The task is to rearrange the array elements so that all negative numbers appear before all positive numbers.

Note:
- Given array does not contain any zeroes.
- Order of resultant array does not matter.

[Naive approach] Using Sorting - O(nlogn) Time and O(1) Space
[Expected Approach - 1] Using Quick Sort Partition - O(n) time and O(1) space
"""


nums = list(map(int, input("Enter the element (space seperate): ").split()))

i = 0
j = len(nums) - 1

while i < j:
    if nums[i] > 0 and nums[j] < 0:
        nums[i], nums[j] = nums[j], nums[i]
        i += 1
        j -= 1

    if nums[i] < 0:
        i += 1
    if nums[j] > 0:
        j -= 1

print(nums)
