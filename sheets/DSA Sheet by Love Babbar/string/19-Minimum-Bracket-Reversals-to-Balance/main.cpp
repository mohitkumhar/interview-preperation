/*
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

*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string s = "}{{}}{{{";
    stack<char> stack;

    int open_brack = 0;
    int close_brack = 0;

    for (char c : s)
    {
        if (c == '}')
        {
            if (!stack.empty() && stack.top() == '{')
            {
                open_brack--;
                stack.pop();
            }
            else
            {
                close_brack++;
                stack.push(c);
            }
        }
        else
        {
            if (c == '{')
                open_brack++;
            else
                close_brack--;
            stack.push(c);
        }
    }

    if ((open_brack + close_brack) % 2 == 1)
        cout << -1 << endl;
    else
        cout << (open_brack + 1) / 2 + (close_brack + 1) / 2 << endl;

    return 0;
}
