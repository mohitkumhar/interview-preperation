/*
https://www.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1

Min and Max in Array
Difficulty: Basic

Given an array arr[]. Your task is to find the minimum and maximum elements in the array.

Examples:

Input: arr[] = [1, 4, 3, 5, 8, 6]
Output: [1, 8]
Explanation: minimum and maximum elements of array are 1 and 8.

Input: arr[] = [12, 3, 15, 7, 9]
Output: [3, 15]
Explanation: minimum and maximum element of array are 3 and 15.

Constraints:
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^9

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{

    int maxi = INT_MIN;
    int mini = INT_MAX;

    vector<int> nums{1, 2, 3, 4};

    for (int num : nums)
    {
        if (num < mini)
            mini = num;

        if (num > maxi)
            maxi = num;
    }
    cout << "Maximum Number is: " << maxi << endl << "Minimum Number is: " << mini << endl;
    return 0;
}
