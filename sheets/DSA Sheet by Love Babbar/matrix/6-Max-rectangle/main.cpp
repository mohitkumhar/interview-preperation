/*
https://www.geeksforgeeks.org/problems/max-rectangle/1
Max rectangle
Difficulty: Hard

You are given a 2D binary matrix mat[ ][ ], where each cell contains either 0 or 1. Your task is to find the maximum area of a rectangle that can be formed using only 1's within the matrix.

Examples:

Input: mat[][] = [[0, 1, 1, 0],
                [1, 1, 1, 1],
                [1, 1, 1, 1],
                [1, 1, 0, 0]]
Output: 8
Explanation: The largest rectangle with only 1’s is from (1, 0) to (2, 3) which is
[1, 1, 1, 1]
[1, 1, 1, 1]
and area is 4 * 2 = 8.

Input: mat[][] = [[0, 1, 1],
                [1, 1, 1],
                [0, 1, 1]]
Output: 6
Explanation: The largest rectangle with only 1’s is from (0, 1) to (2, 2) which is
[1, 1]
[1, 1]
[1, 1]
and area is 2 * 3 = 6.

Constraints:
1 ≤ mat.size(), mat[0].size() ≤ 1000
0 ≤ mat[][] ≤ 1

Expected Complexities
Time Complexity: O(n * m)
Auxiliary Space: O(n)

*/

// This PS is the extention of https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// the `find_histogram` function is copy from that `largest-rectangle-in-histogram` problem

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int findHistogram(vector<int> heights)
{
    int n = heights.size();

    vector<int> leftMiniVal;
    stack<int> stack;

    for (int i = 0; i < n; i++)
    {
        while (!stack.empty() && heights[stack.top()] >= heights[i])
            stack.pop();

        if (stack.empty())
            leftMiniVal.push_back(-1);
        else if (heights[stack.top()] < heights[i])
            leftMiniVal.push_back(stack.top());

        stack.push(i);
    }

    while (!stack.empty())
        stack.pop();

    vector<int> rightMiniVal;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stack.empty() && heights[stack.top()] >= heights[i])
            stack.pop();

        if (stack.empty())
            rightMiniVal.push_back(n);
        else if (heights[stack.top()] < heights[i])
            rightMiniVal.push_back(stack.top());

        stack.push(i);
    }
    reverse(rightMiniVal.begin(), rightMiniVal.end());

    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        int width = rightMiniVal[i] - leftMiniVal[i] - 1;
        maxArea = max(maxArea, heights[i] * width);
    }

    return maxArea;
}

int main()
{
    vector<vector<int>> matrix{{1, 0, 1, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}};

    int m = matrix.size();
    int n = matrix[0].size();
    int maxArea = 0;

    vector<int> heights(n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
                heights[j] += 1;
            else
                heights[j] = 0;
        }
        int currArea = findHistogram(heights);
        maxArea = max(maxArea, currArea);
    }

    cout << "Max Area of this rectangle is: " << maxArea << endl;
}
