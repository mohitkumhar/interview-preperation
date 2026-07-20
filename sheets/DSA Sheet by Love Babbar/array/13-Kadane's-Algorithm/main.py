"""
https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
Kadane's Algorithm
Difficulty: Medium

You are given an integer array arr[]. You need to find the maximum sum of a subarray (containing at least one element) in the array arr[].

Examples:

Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray [7, -1, 2, 3] has the largest sum 11.

Input: arr[] = [-2, -4]
Output: -2
Explanation: The subarray [-2] has the largest sum -2.

Input: arr[] = [5, 4, 1, 7, 8]
Output: 25
Explanation: The subarray [5, 4, 1, 7, 8] has the largest sum 25.

Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

"""

# Time  = O(n)
# Space = O(1)

from typing import List


def find_max_subarray(nums: List[int]) -> int:
    curr_max = nums[0]
    max_ans = nums[0]

    for i in range(1, len(nums)):
        curr_max = max(nums[i], nums[i] + curr_max)
        max_ans = max(max_ans, curr_max)

    return max_ans


nums = [2, 3, -8, 7, -1, 2, 3]
max_sum = find_max_subarray(nums)

print(max_sum)
