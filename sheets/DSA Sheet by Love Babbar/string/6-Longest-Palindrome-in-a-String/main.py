"""
https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

Longest Palindrome in a String
Difficulty: Medium

Given a string s, your task is to find the longest palindromic substring within s.

A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).

A palindrome is a string that reads the same forward and backward. More formally, s is a palindrome if reverse(s) == s.

Note: If there are multiple palindromic substrings with the same length, return the first occurrence of the longest palindromic substring from left to right.

Examples :
Input: s = “forgeeksskeegfor”
Output: “geeksskeeg”
Explanation: There are several possible palindromic substrings like “kssk”, “ss”, “eeksskee” etc. But the substring “geeksskeeg” is the longest among all.

Input: s = “Geeks”
Output: “ee”
Explanation: "ee" is the longest palindromic substring of "Geeks".

Input: s = “abc”
Output: “a”
Explanation: "a", "b" and "c" are longest palindromic substrings of same length. So, the first occurrence is returned.

Constraints:
1 ≤ s.size() ≤ 103
s consist of only lowercase English letters.

Expected Complexities
Time Complexity: O(n^2)
Auxiliary Space: O(1)

"""


# Approch- 1 [Brute Force]
# Time  - O(n^3)
# Space - O(1)
def is_pal(string: str, i: int, j: int) -> bool:
    while i < j:
        if string[i] != string[j]:
            return False
        i += 1
        j -= 1
    return True


s = "forgeeksskeegfor"
ans = ""
n = len(s)

for i in range(n):
    for j in range(i, n):
        if is_pal(s, i, j):
            if (j - i + 1) > len(ans):
                ans = s[i : j + 1]

print(ans)


# Approch- 2 [DP]
# Time  - O(n^2)
# Space - O(n^2)

s = "mkppkm"
n = len(s)

dp = [[False for _ in range(n)] for _ in range(n)]

for L in range(1, n + 1):
    i = 0
    while (i + L - 1) < n:
        j = i + L - 1

        if L == 1:
            dp[i][j] = True
        elif L == 2:
            dp[i][j] = s[i] == s[j]
        else:
            dp[i][j] = s[i] == s[j] and dp[i + 1][j - 1]
        i += 1

ans = ""

for i in range(n):
    for j in range(n):
        if dp[i][j]:
            if (j - i + 1) > len(ans):
                ans = s[i : j + 1]

print(ans)
