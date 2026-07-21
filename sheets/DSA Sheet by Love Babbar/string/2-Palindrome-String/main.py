"""
https://www.geeksforgeeks.org/problems/palindrome-string0817/1
Palindrome String
Difficulty: Easy

Given a string `s`, return true if the string is a palindrome. Otherwise, return false.

A string is considered a palindrome if it reads the same forwards and backwards.

Examples :
Input: s = "abba"
Output: true

Explanation: "abba" reads the same forwards and backwards, so it is a palindrome.
Input: s = "abc"
Output: false
Explanation: "abc" does not read the same forwards and backwards, so it is not a palindrome.

Constraints:
1 ≤ s.size() ≤ 10^6
The string s contains only lowercase english letters (a-z).

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
"""


def check_pal(s: str):
    i = 0
    j = len(s) - 1

    while i < j:
        if s[i] != s[j]:
            return False
        i += 1
        j -= 1
    return True


s = "abba"
if check_pal(s):
    print("String is Palindrome")
else:
    print("String is not Palindrome")
