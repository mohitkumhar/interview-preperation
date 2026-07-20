"""
https://www.geeksforgeeks.org/problems/sorted-matrix2333/1
Sort a Matrix
Difficulty: Basic

Given an n*n matrix mat[][]. returns the matrix with all elements sorted in non-decreasing order.

Examples:

Input: mat[][] = [[10, 20, 30, 40],
                  [15, 25, 35, 45], 
                  [27, 29, 37, 48],
                  [32, 33, 39, 50]]
Output:
       [[10, 15, 20, 25], 
        [27, 29, 30, 32],
        [33, 35, 37, 39],
        [40, 45, 48, 50]]
Explanation: Sorting the matrix gives this result.

Input: mat[][] = [[1, 5, 3],
                  [2, 8, 7],
                  [4, 6, 9]]
Output:
       [[1, 2, 3], 
        [4, 5, 6],
        [7, 8, 9]]
Explanation:
Sorting the matrix gives this result.

Constraints:
1 ≤ n ≤ 1000
1 ≤ mat[i][j] ≤ 10^5

Expected Complexities
Time Complexity: O(n^2*(logn))
Auxiliary Space: O(n^2)

"""
from typing import List


def sort_matrix(matrix: List[List[int]]):
    m = len(matrix)
    n = len(matrix[0])

    array = []

    for i in range(m):
        for j in range(n):
            array.append(matrix[i][j])
    array.sort()

    idx = 0
    for i in range(m):
        for j in range(n):
            matrix[i][j] = array[idx]
            idx += 1

    print(matrix)


matrix = [[10, 20, 30, 40], [15, 25, 35, 45],
          [27, 29, 37, 48], [32, 33, 39, 50]]
sort_matrix(matrix)
