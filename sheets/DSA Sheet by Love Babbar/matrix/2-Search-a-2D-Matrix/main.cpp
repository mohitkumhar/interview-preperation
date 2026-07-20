/*
https://leetcode.com/problems/search-a-2d-matrix/description
Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.


Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false


Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10^4 <= matrix[i][j], target <= 10^4

*/

//  Approch - 1 [Expected]
// Time  = O(log(m * n))
// Space = O(1)

#include <iostream>
#include <vector>

using namespace std;

void approch_1()
{
    vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 13;

    int rows = matrix.size();
    int cols = matrix[0].size();

    int left = 0;
    int right = rows * cols - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int mid_val = matrix[mid / cols][mid % cols];

        if (mid_val == target)
        {
            cout << "Target Value is Found" << endl;
            break;
        }
        else if (mid_val > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << "Value Not Found!!" << endl;
}

// Approch-2 [Linear Search]
// Time  = O(m * n)
// Space = O(1)

void approch_2()
{

    vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 11;

    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == target)
            {
                cout << "Value is Found !" << endl;
                return;
            }
        }
    }
    cout << "Value is not Found" << endl;
}

int main()
{
    approch_1();
    approch_2();

    return 0;
}
