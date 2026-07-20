"""
https://leetcode.com/problems/find-the-duplicate-number/description/

Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.


Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
 

Constraints:

1 <= n <= 10^5
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:
- How can we prove that at least one duplicate number must exist in nums?
- Can you solve the problem in linear runtime complexity?

"""

# Approch 1 [Expected]
# Time  = O(n)
# Space = O(1)

from typing import List


def approch_1(nums: List[int]) -> int:
    slow = nums[0]
    fast = nums[0]

    while True:
        slow = nums[slow]
        fast = nums[nums[fast]]

        if fast == slow:
            break

    slow = nums[0]
    while fast != slow:
        slow = nums[slow]
        fast = nums[fast]

    return slow


# Approch - 2 [using set]

# Time  = O(n)
# Space = O(n)

def approch_2(nums: List[int]) -> int:
    seen = set()

    for num in nums:
        if num in seen:
            return num
        seen.add(num)

    return -1



nums = [1, 3, 4, 2, 2]
duplicate_val_1 = approch_1(nums)
duplicate_val_2 = approch_2(nums)

print(duplicate_val_1)
print(duplicate_val_2)
