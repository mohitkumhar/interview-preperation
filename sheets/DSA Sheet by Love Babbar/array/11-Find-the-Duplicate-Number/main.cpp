/*
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

*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Approch - 1 [Expected]
// Time  = O(n)
// Space = O(1)

int approch_1()
{
    vector<int> nums{1, 3, 4, 2, 2};

    int slow = nums[0];
    int fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];

    while (fast != slow)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    cout << fast << endl;

    return 0;
}

// Approch- 2
// Time  = O(n)
// Space = O(n)

int approch_2()
{
    vector<int> nums{1, 3, 4, 2, 2};
    unordered_set<int> seen;

    for (int num : nums)
    {
        if (seen.find(num) != seen.end())
        {
            cout << num << endl;
            return 0;
        }
        seen.insert(num);
    }
    return 0;
}

int main()
{
    approch_1();
    approch_2();

    return 0;
}