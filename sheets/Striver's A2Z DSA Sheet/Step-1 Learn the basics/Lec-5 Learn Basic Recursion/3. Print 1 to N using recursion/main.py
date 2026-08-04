"""
Print N to 1 using Recursion

Given an integer n, write a function to print all numbers from 1 to n (inclusive) using recursion.

You must not use any loops such as for, while, or do-while.
The function should print each number on a separate line, in increasing order from 1 to n

Example 1
Input: 5
Output:
1
2
3
4
5

Example 2
Input: 1
Output:
1

Constraints
1 <= n <= 100
"""


def solve(num, n):
    if num == (n + 1):
        return
    print(num)

    solve(num + 1, n)


n = 5
solve(1, n)
