"""
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

"""

# This PS is the extention of https://leetcode.com/problems/largest-rectangle-in-histogram/description/
# the `find_histogram` function is copy from that `largest-rectangle-in-histogram` problem 

from typing import List


def find_histogram(heights: List[int]) -> int:
    n = len(heights)
    left_smaller_val = []
    stack = []

    for i in range(n):
        while stack and heights[stack[-1]] >= heights[i]:
            stack.pop()

        if not stack:
            left_smaller_val.append(-1)
        elif heights[stack[-1]] < heights[i]:
            left_smaller_val.append(stack[-1])

        stack.append(i)

    right_smaller_val = []
    stack = []

    for i in range(n - 1, -1, -1):
        while stack and heights[stack[-1]] >= heights[i]:
            stack.pop()

        if not stack:
            right_smaller_val.append(n)
        elif heights[stack[-1]] < heights[i]:
            right_smaller_val.append(stack[-1])

        stack.append(i)
    right_smaller_val.reverse()
    max_area = 0

    for i in range(n):
        width = right_smaller_val[i] - left_smaller_val[i] - 1
        curr_area = heights[i] * width

        max_area = max(max_area, curr_area)

    return max_area


matrix = [[0, 1, 1, 0], [1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 0, 0]]
m = len(matrix)
n = len(matrix[0])
max_area = 0

heights = [0] * n

for i in range(m):
    for j in range(n):
        if matrix[i][j] == 1:
            heights[j] += 1
        else:
            heights[j] = 0

    curr_area = find_histogram(heights)
    max_area = max(max_area, curr_area)

print(max_area)
