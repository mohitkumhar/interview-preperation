"""
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
"""


def find_smaller_element(val):
    i = n - 1
    j = 0
    count = 0

    while i >= 0 and j < n:
        if matrix[i][j] <= val:
            count += i + 1
            j += 1
        else:
            i -= 1

    return count


matrix = [[16, 28, 60, 64],
          [22, 41, 63, 91],
          [27, 50, 87, 93],
          [36, 78, 87, 94]]
k = 3

n = len(matrix)

# smallest val
left = matrix[0][0]

# largest val
right = matrix[n - 1][n - 1]


while left < right:
    mid = left + (right - left) // 2
    smaller_element = find_smaller_element(mid)

    if smaller_element >= k:
        right = mid
    else:
        left = mid + 1

print(right)
