"""
https://www.geeksforgeeks.org/problems/edit-distance3702/1
Edit Distance
Difficulty: Hard

Given two strings s1 and s2. Return the minimum number of operations required to convert s1 to s2.
The possible operations are permitted:

- Insert a character at any position of the string.
- Remove any character from the string.
- Replace any character from the string with any other character.

Examples:

Input: s1 = "geek", s2 = "gesek"
Output: 1
Explanation: One operation is required, inserting 's' between two 'e' in s1.

Input: s1 = "gfg", s2 = "gfg"
Output: 0
Explanation: Both strings are same.

Input: s1 = "abcd", s2 = "bcfe"
Output: 3
Explanation: We can convert s1 into s2 by removing 'a', replacing 'd' with 'f' and inserting 'e' at the end.

Constraints:
1 ≤ s1.length(), s2.length() ≤ 10^3
Both the strings are in lowercase.

"""


def solve(i: int, j: int):
    if i >= n1:
        memo[i][j] = n2 - j
        return n2 - j
    if j >= n2:
        memo[i][j] = n1 - i
        return n1 - i
    if memo[i][j] != -1:
        return memo[i][j]

    if s1[i] == s2[j]:
        memo[i][j] = solve(i + 1, j + 1)
        return memo[i][j]

    insert = 1 + solve(i, j + 1)
    delete = 1 + solve(i + 1, j)
    replace = 1 + solve(i + 1, j + 1)

    memo[i][j] = min(insert, delete, replace)
    return memo[i][j]


s1 = "geek"
s2 = "gesek"

n1 = len(s1)
n2 = len(s2)

memo = [[-1 for _ in range(n2 + 1)] for _ in range(n1 + 1)]

operation = solve(0, 0)

print(operation)
