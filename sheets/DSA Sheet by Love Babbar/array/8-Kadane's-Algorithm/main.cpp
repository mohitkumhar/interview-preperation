/*

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


*/

// Time  = O(n)
// Space = O(1)

#include <iostream>
#include <vector>

using namespace std;

int findMaxSubarray(vector<int> &nums)
{
    int currSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        currSum = max(nums[i], nums[i] + currSum);
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main()
{
    vector<int> nums{2, 3, -8, 7, -1, 2, 3};
    int maxSubSum = findMaxSubarray(nums);
    cout << maxSubSum;

    return 0;
}
