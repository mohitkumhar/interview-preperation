/*
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

*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{

    string s = "[{()}]";
    bool flag = true;
    stack<char> stack;

    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            stack.push(c);

        else
        {
            if (stack.empty())
            {
                flag = false;
                break;
            }
            if ((c == ')' && stack.top() == '(') ||
                (c == ']' && stack.top() == '[') ||
                (c == '}' && stack.top() == '{'))
                stack.pop();
            else
            {
                flag = false;
                break;
            }
        }
    }
    if (!stack.empty())
        flag = false;

    if (flag)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
