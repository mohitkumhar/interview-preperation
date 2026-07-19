/*
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

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums{1, 1, 0, 0, 2, 0, 1};

    int zeros = 0;
    int ones = 0;
    int twos = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            zeros++;
        else if (nums[i] == 1)
            ones++;
        else
            twos++;
    }

    int idx = 0;
    while (zeros--)
        nums[idx++] = 0;

    while (ones--)
        nums[idx++] = 1;

    while (twos--)
        nums[idx++] = 2;

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";

    return 0;
}
