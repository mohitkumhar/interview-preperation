"""
https://www.geeksforgeeks.org/problems/search-pattern0205/1
Search Pattern
Difficulty: Hard

Given two strings, a text string txt and a pattern string pat, both consisting of lowercase English alphabets. Return the starting indices (0-based) of all the occurrences of the pattern string pat in the text string txt.

Note: Return an empty list in case of no occurrences of pattern.

Examples:

Input: txt = "geeksforgeeks", pat = "geek"
Output: [0, 8]
Explanation: The string "geek" occurs twice in txt, one starts at index 0 and the other at index 8.

Input: txt = "abesdu", pat = "edu"
Output: []
Explanation: There's no substring "edu" present in txt.

Input: txt = "aabaacaadaabaaba", pat = "aaba"
Output: [0, 9, 12]
Explanation:

Constraints:
1 ≤ txt.size() ≤ 10^5
1 ≤ pat.size() ≤ txt.size()

Expected Complexities
Time Complexity: O(n + m)
Auxiliary Space: O(m)
"""



txt = "geeksforgeeks"
pat = "geek"

n = len(txt)
m = len(pat)

LPS = [0] * m
LPS[0] = 0
length_idx = 0

i = 1

while i < m:
    if pat[i] == pat[length_idx]:
        length_idx += 1
        LPS[i] = length_idx
        i += 1
    else:
        if length_idx == 0:
            LPS[length_idx] = 0
            i += 1
        else:
            length_idx = LPS[length_idx - 1]


result = []

i = 0
j = 0

while i < n:
    if txt[i] == pat[j]:
        i += 1
        j += 1
        if j == m:
            result.append(i - m)
            j = LPS[j - 1]

    else:
        if j != 0:
            j = LPS[j - 1]
        else:
            i += 1

print(result)
