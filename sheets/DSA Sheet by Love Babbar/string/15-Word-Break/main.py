"""
Word Break
Difficulty: Medium

You are given a string s and a list dictionary[] of words. Your task is to determine whether the string s can be formed by concatenating one or more words from the dictionary[].

Note: From dictionary[], any word can be taken any number of times and in any order.

Examples :
Input: s = "ilike", dictionary[] = ["i", "like", "gfg"]
Output: true
Explanation: s can be breakdown as "i like".

Input: s = "ilikegfg", dictionary[] = ["i", "like", "man", "india", "gfg"]
Output: true
Explanation: s can be breakdown as "i like gfg".

Input: s = "ilikemangoes", dictionary[] = ["i", "like", "man", "india", "gfg"]
Output: false
Explanation: s cannot be formed using dictionary[] words.

Constraints:
1 ≤ s.size() ≤ 3000
1 ≤ dictionary.size() ≤ 1000
1 ≤ dictionary[i].size() ≤ 100

Expected Complexities
Time Complexity: O(n * m)
Auxiliary Space: O(n)

"""


def solve(i: int) -> bool:
    if i == n:
        return True
    if memo[i] != -1:
        return memo[i]

    for j in range(i, n):
        if s[i : j + 1] in dictionary and solve(j + 1):
            memo[i] = True
            return memo[i]
    memo[i] = False
    return memo[i]


s = "ilikegfg"
dictionary = ["i", "like", "man", "india", "gfg"]

n = len(s)
memo = [-1] * (n + 1)

print(solve(0))
