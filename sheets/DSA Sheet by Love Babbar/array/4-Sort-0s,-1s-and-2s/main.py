"""
https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
Sort 0s, 1s and 2s
Difficulty: Medium

Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.
Note: You need to solve this problem without utilizing the built-in sort function.

Examples:

Input: arr[] = [0, 1, 2, 0, 1, 2]
Output: [0, 0, 1, 1, 2, 2]
Explanation: 0s, 1s and 2s are segregated into ascending order.

Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
Explanation: 0s, 1s and 2s are segregated into ascending order.

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 2

"""

nums = list(
    map(int, input("Enter the element of array (space seperated): ").split()))

zeros = 0
ones = 0
twos = 0

for num in nums:
    if num == 0:
        zeros += 1
    elif num == 1:
        ones += 1
    else:
        twos += 1

nums = [0] * zeros + [1] * ones + [2] * twos

print(nums)
