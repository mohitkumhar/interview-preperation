"""
https://www.geeksforgeeks.org/problems/count-palindromic-subsequences/1
Count Palindromic Subsequences
Difficulty: Medium

Given a string s, you have to find the number of palindromic subsequences (need not necessarily be distinct) present in the string s.

Examples:

Input: s = "abcd"
Output: 4
Explanation: palindromic subsequence are : 'a' ,'b', 'c' ,'d'

Input: s = "aab"
Output: 4
Explanation: palindromic subsequence are : 'a', 'a', 'b', 'aa'

Input: s = "b"
Output: 1
Explanation: palindromic subsequence are : 'b'

Constraints:
1<= s.size() <=30

Expected Complexities
Time Complexity: O(n^2)
Auxiliary Space: O(n^2)
"""

# Approch-1 [Brute Force]
# Time  - O(k * n^2)
# Space - O(n)

s = "aaa"


def isPal(nums):
    return nums == nums[::-1]


n = len(s)
memo = {}


def solve(i, curr_str):
    key = (i, tuple(curr_str))
    if i == n:
        if curr_str and isPal(curr_str):
            memo[key] = 1
            return 1
        memo[key] = 0
        return 0
    
    if key in memo:
        return memo[key]
    
    # take
    take = solve(i + 1, curr_str + [s[i]])

    # skip
    skip = solve(i + 1, curr_str)
    memo[key] = take + skip

    return take + skip


count = solve(0, [])
print(count)
