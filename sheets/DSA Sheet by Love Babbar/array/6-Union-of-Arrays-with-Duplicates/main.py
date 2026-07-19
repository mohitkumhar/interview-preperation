"""
https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1
Union of Arrays with Duplicates
Difficulty: Easy

You are given two arrays a[] and b[], 
return the Union of both the arrays in any order.

The Union of two arrays is a collection of all distinct elements present in either of the arrays. If an element appears more than once in one or both arrays, it should be included only once in the result.

Note: Elements of a[] and b[] are not necessarily distinct.
Note that, You can return the Union in any order but the driver code will print the result in sorted order only.

Examples:

Input: a[] = [1, 2, 3, 2, 1], b[] = [3, 2, 2, 3, 3, 2]
Output: [1, 2, 3]
Explanation: Union set of both the arrays will be 1, 2 and 3.

Input: a[] = [1, 2, 3], b[] = [4, 5, 6] 
Output: [1, 2, 3, 4, 5, 6]
Explanation: Union set of both the arrays will be 1, 2, 3, 4, 5 and 6.

Input: a[] = [1, 2, 1, 1, 2], b[] = [2, 2, 1, 2, 1] 
Output: [1, 2]
Explanation: Union set of both the arrays will be 1 and 2.

Constraints:
1 ≤ a.size(), b.size() ≤ 10^6
0 ≤ a[i], b[i] ≤ 10^5

Expected Complexities
Time Complexity: O(n + m)
Auxiliary Space: O(n + m)

"""

# Approch-1 (simple looping)

# Time  = O(n + m)
# Space = O(n + m)

from typing import List


def find_union(nums1: List[int], nums2: List[int]) -> List[int]:

    seen = set()
    result = []

    for num in nums1 + nums2:
        if num in seen:
            continue
        seen.add(num)
        result.append(num)

    return result


nums1 = [1, 2, 3, 4]
nums2 = [3, 4, 5, 6]

result = find_union(nums1, nums2)
print(result)


# Approch-2 (taking benefit as both nums are sorted)

# Time  = O(n + m)
# Space = O(1) [aside from result, which is required in output]

nums1 = [1, 2, 3, 4]
nums2 = [3, 4, 5, 6]

n1 = len(nums1)
n2 = len(nums2)

result = []

i = 0
j = 0

while i < n1 and j < n2:
    if nums1[i] < nums2[j]:
        val = nums1[i]
        i += 1
    else:
        val = nums2[j]
        j += 1

    if not result or result[-1] != val:
        result.append(val)

while i < n1:
    val = nums1[i]
    if result[-1] != val:
        result.append(val)
    i += 1


while j < n2:
    val = nums2[j]
    if result[-1] != val:
        result.append(val)
    j += 1

print(result)
