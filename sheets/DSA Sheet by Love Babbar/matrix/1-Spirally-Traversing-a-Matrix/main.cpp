/*
https://leetcode.com/problems/spiral-matrix/submissions/2075313154/
Spirally Traversing a Matrix
Difficulty: Medium

Given a rectangular matrix mat[][] of size n x m, and return a 1D array containing all its elements in spiral order.

Examples:

Input: mat[][] = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]

Input: mat[][] = [[1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12], [13, 14, 15, 16, 17, 18]]
Output: [1, 2, 3, 4, 5, 6, 12, 18, 17, 16, 15, 14, 13, 7, 8, 9, 10, 11]

Input: mat[][] = [[32, 44, 27, 23], [54, 28, 50, 62]]
Output: [32, 44, 27, 23, 62, 50, 28, 54]

Constraints:
1 ≤ n, m ≤1000
0 ≤ mat[i][j] ≤100

Expected Complexities
Time Complexity: O(n * m)
Auxiliary Space: O(n * m)

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    int m = matrix.size();
    int n = matrix[0].size();

    int top = 0;
    int down = m - 1;

    int left = 0;
    int right = n - 1;

    vector<int> result;

    while (top <= down && left <= right)
    {
        // top row
        for (int i = left; i <= right; i++)
            result.push_back(matrix[top][i]);
        top++;

        // right column
        for (int i = top; i <= down; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;

        // down row
        if (top <= down)
        {
            for (int i = right; i >= left; i--)
            {
                result.push_back(matrix[down][i]);
            }
            down--;
        }

        // left column
        if (left <= right)
        {
            for (int i = down; i >= top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    cout << endl;
    // Output: [1,2,3,4,8,12,11,10,9,5,6,7]
    return 0;
}
