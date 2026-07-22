"""
https://www.geeksforgeeks.org/problems/power-set4302/1
All Subsequences of a String
Difficulty: Medium

Given a string s, generate all possible subsequences of the string (including the empty subsequence) and return them in lexicographical order.

A subsequence is obtained by deleting zero or more characters from the string without changing the relative order of the remaining characters.

Examples:

Input : s = "abc"
Output: ["","a", "ab", "abc", "ac", "b", "bc", "c"]
Explanation: There are a total of 8 non-empty subsequences for the given string.
These subsequences are listed above in lexicographical order.

Input: s = "aa"
Output: ["", "a", "a", "aa"]


Constraints:
1 ≤ n ≤ 16
s consists of lowercase English letters.

"""


def solve(i: int, curr_str: str) -> None:
    if i == n:
        result.append(curr_str)
        return None

    # take
    solve(i + 1, curr_str + s[i])

    # skip
    solve(i + 1, curr_str)


s = "abc"
n = len(s)
result = []

solve(0, "")
result.sort()
print(result)
