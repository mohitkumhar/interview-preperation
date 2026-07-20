/*
https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1
Kth smallest element in a Matrix

Difficulty: Medium
Given a matrix mat[][] of size n*n, where each row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Examples:
Input: mat[][] = [[16, 28, 60, 64], k = 3
                [22, 41, 63, 91],
                [27, 50, 87, 93],
                [36, 78, 87, 94]]
Output: 27
Explanation: 27 is the 3rd smallest element.
Input: mat[][] = [[10, 20, 30, 40], k = 7
                [15, 25, 35, 45],
                [24, 29, 37, 48],
                [32, 33, 39, 50]]
Output: 30
Explanation: 30 is the 7th smallest element.

Constraints:
1 ≤ n ≤ 500
1 ≤ mat[i][j] ≤ 10^4
1 ≤ k ≤ n*n

Expected Complexities
Time Complexity: O(n * log(max(mat) - min(mat)))
Auxiliary Space: O(1)

*/

#include <iostream>
#include <vector>

using namespace std;

int findSmallerKValues(int val, int n, vector<vector<int>> matrix)
{
    int i = n - 1;
    int j = 0;
    int count = 0;

    while (i >= 0 && j < n)
    {
        if (matrix[i][j] <= val)
        {
            count += i + 1;
            j++;
        }
        else
            i--;
    }
    return count;
}

int main()
{
    vector<vector<int>> matrix{{16, 28, 60, 64}, {22, 41, 63, 91}, {27, 50, 87, 93}, {36, 78, 87, 94}};
    int k = 3;
    int n = matrix.size();

    // smallest value in matrix
    int left = matrix[0][0];

    // largest value in matrix
    int right = matrix[n - 1][n - 1];

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        int smallerKValues = findSmallerKValues(mid, n, matrix);

        if (smallerKValues >= k)
            right = mid;

        else
            left = mid + 1;
    }
    cout << left << endl;

    return 0;
}
