"""
Print Name n times using Recursion

Given an integer n, write a program to print your name n times.

Examples
Input: n = 3
Output: Mohit Mohit Mohit 
Explanation: Name is printed 3 times.

Input: n = 1
Output: Mohit 
Explanation: Name is printed once.

"""


def solve(n, name):
    if n == 0:
        return
    
    print(name, end=" ")
    solve(n - 1, name)


name = "Mohit"
n = 3

solve(n, name)