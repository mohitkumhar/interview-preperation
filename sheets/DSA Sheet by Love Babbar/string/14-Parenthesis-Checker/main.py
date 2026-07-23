"""
https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1
Parenthesis Checker
Difficulty: Easy

Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']'. Determine whether the Expression is balanced or not.
An expression is balanced if:

Each opening bracket has a corresponding closing bracket of the same type.
Opening brackets must be closed in the correct order.

Examples :

Input: s = "[{()}]"
Output: true
Explanation: All the brackets are well-formed.

Input: s = "[()()]{}"
Output: true
Explanation: All the brackets are well-formed.

Input: s = "([]"
Output: false
Explanation: The expression is not balanced as there is a missing ')' at the end.

Input: s = "([{]})"
Output: false
Explanation: The expression is not balanced as there is a closing ']' before the closing '}'.

Constraints:
1 ≤ s.size() ≤ 10^6
s[i] ∈ {'{', '}', '(', ')', '[', ']'}
"""

s = r"([{]})"
flag = True

stack = []

for char in s:
    if char in set("[({"):
        stack.append(char)

    else:
        if not stack:
            flag = False
            break

        if (
            (char == ")" and stack[-1] == "(")
            or (char == "}" and stack[-1] == "{")
            or (char == "]" and stack[-1] == "[")
        ):
            stack.pop()
        else:
            flag = False
            break
if stack:
    flag = False

if flag:
    print(True)
else:
    print(False)
