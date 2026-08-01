"""
Reverse Integer
Medium

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).


Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21
 

Constraints:
-2^31 <= x <= 2^31 - 1
 
"""


INT_MAX = 2**31 - 1
INT_MIN = -2**31


num = -123
sign = 1

num = str(num)

sign = -1 if num[0] == "-" else 1
if sign == -1:
    num = num[1:]

num = int(num[::-1])

num *= sign

if num >= INT_MAX or num <= INT_MIN:
    print(0)
else:
    print(num)



