"""
https://www.geeksforgeeks.org/problems/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/1
Balanced Splits of a Binary String
Difficulty: Easy

Given binary string `s` find the maximum number of substrings it can be splitted into such that all substrings have equal number of 0s and 1s. If it is not possible to split s satisfying the conditions then return -1.

Examples:
Input: s = "0100110101"
Output: 4
Explanation: The required substrings are 01, 0011, 01 and 01.

Input: s = "0111100010"
Output: 3

Input: s = "0010"
Output: -1

Constraints:
1 ≤ s.length ≤ 10^5

"""

s = "0100110101"

zero_count = 0
one_count = 0
result = 0

for char in s:
    if char == "0":
        zero_count += 1
    else:
        one_count += 1

    if zero_count == one_count:
        result += 1

print(result)
