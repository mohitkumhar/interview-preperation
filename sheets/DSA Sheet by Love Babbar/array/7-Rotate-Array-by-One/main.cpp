/*
https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1?utm=codolio
Rotate Array by One
Difficulty: Basic

Given an array arr, rotate the array by one position in clockwise direction.

Examples:
Input: arr[] = [1, 2, 3, 4, 5]
Output: [5, 1, 2, 3, 4]
Explanation: If we rotate arr by one position in clockwise 5 come to the front and remaining those are shifted to the end.

Input: arr[] = [9, 8, 7, 6, 4, 2, 1, 3]
Output: [3, 9, 8, 7, 6, 4, 2, 1]
Explanation: After rotating clock-wise 3 comes in first position.

Constraints:
1 ≤ arr.size() ≤ 10^5
0 ≤ arr[i] ≤ 10^5

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums{1, 2, 3, 4, 5};
    if (nums.size() == 0)
    {
        cout << "Array is empty" << endl;
        return 0;
    }

    int prev = nums[0];
    nums[0] = nums[nums.size() - 1];

    for (int i = 1; i < nums.size(); i++)
    {
        int temp = nums[i];
        nums[i] = prev;
        prev = temp;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
