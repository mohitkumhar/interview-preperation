"""
https://www.geeksforgeeks.org/problems/count-the-reversals0401/1
Minimum Bracket Reversals to Balance
Difficulty: Medium

Given a string s consisting of only opening and closing curly brackets '{' and '}', find out the minimum reversals required to convert the string into a balanced expression. A reversal means changing '{' to '}' or vice-versa.

Examples:

Input: s = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.

Input: s = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance this sequence of braces.

Constraints:
1 ≤ |s| ≤ 10^5
"""

s = r"}{{}}{{{"


def bracket_reversal_to_balance(s: str) -> int:
    stack = []
    opening_brack = 0
    closing_brack = 0

    for char in s:
        if char == "}":
            if stack and stack[-1] == "{":
                stack.pop()
                opening_brack -= 1
            else:
                if char == "}":
                    closing_brack += 1
                stack.append(char)

        else:
            if char == "}":
                closing_brack += 1
            else:
                opening_brack += 1

            stack.append(char)

    if len(stack) % 2 == 1:
        return -1

    return ((opening_brack + 1) // 2) + ((closing_brack + 1) // 2)


print(bracket_reversal_to_balance(s))
