"""
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

"""

matrix = [[1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12], [13, 14, 15, 16, 17, 18]]

m = len(matrix)
n = len(matrix[0])

top = 0
down = m - 1

left = 0
right = n - 1
result = []


while top <= down and left <= right:
    # top traversal
    for i in range(left, right + 1):
        result.append(matrix[top][i])
    top += 1

    # right traversal
    for i in range(top, down + 1):
        result.append(matrix[i][right])
    right -= 1

    # down traversal
    if top <= down:
        for i in range(right, left - 1, -1):
            result.append(matrix[down][i])
        down -= 1

    # left traversal
    if left <= right:
        for i in range(down, top - 1, -1):
            result.append(matrix[i][left])
        left += 1

print(result)  # Output: [1, 2, 3, 4, 5, 6, 12, 18, 17, 16, 15, 14, 13, 7, 8, 9, 10, 11]
