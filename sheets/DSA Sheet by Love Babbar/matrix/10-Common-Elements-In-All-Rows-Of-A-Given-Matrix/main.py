
"""
Common elements in all rows of a given matrix

Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.

Example: 

Input:
mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

Output: 
1 8 or 8 1
8 and 1 are present in all rows.
"""

# Approch-1 [Brute Force]

# Time  = O(m * n^2)
# Space = O(n)

from typing import List
common_elements = []

mat = [[1, 2, 1, 4, 8],
       [3, 7, 8, 5, 1],
       [8, 7, 7, 3, 1],
       [8, 1, 2, 7, 9]]

m = len(mat)
n = len(mat[0])

seen = set()

for k in range(n):
    val = mat[0][k]
    if val in seen:
        continue
    seen.add(val)
    count = 1

    for i in range(1, m):
        for j in range(n):
            if mat[i][j] == val:
                count += 1
                break

    if count == m:
        common_elements.append(val)

print(common_elements)


# Approch-2 [Binary Search]
# Time  = O(m*n * log(n))
# Space = O(n)

def binary_search(nums: List[int], val: int) -> bool:
    left = 0
    right = len(nums) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if nums[mid] == val:
            return True
        elif nums[mid] > val:
            right = mid - 1
        else:
            left = mid + 1
    return False


mat = [[1, 2, 1, 4, 8],
       [3, 7, 8, 5, 1],
       [8, 7, 7, 3, 1],
       [8, 1, 2, 7, 9]]

m = len(mat)
n = len(mat[0])

common_elements = []
# sorting
for i in range(m):
    mat[i].sort()

seen = set()
# applying binary search
for k in range(n):
    val = mat[0][k]
    if val in seen:
        continue
    seen.add(val)
    count = 1

    for i in range(1, m):
        if binary_search(mat[i], val):
            count += 1
        else:
            break

    if count == m:
        common_elements.append(val)


print(common_elements)
