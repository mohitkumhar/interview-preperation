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
