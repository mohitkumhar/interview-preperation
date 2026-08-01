"""
https://leetcode.com/problems/palindrome-number

Palindrome Number
Easy

Given an integer x, return true if x is a palindrome, and false otherwise.



Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Constraints:

-2^31 <= x <= 2^31 - 1


Follow up: Could you solve it without converting the integer to a string?
"""

# Approch- 1 [Converting into String]


def check_pal(num: str) -> bool:
    i = 0
    j = len(num) - 1

    while i < j:
        if num[i] != num[j]:
            return False
        i += 1
        j -= 1
    return True


print(check_pal(str(1221)))

print()
# Approch- 2 [Wiithout Converting into String]


def check_pal(num: int) -> bool:
    original = num
    reversed = 0

    while num > 0:
        digit = num % 10
        reversed = (10 * reversed) + digit
        num = num // 10

    return original == reversed


print(check_pal(1221))
