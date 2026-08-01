/*
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

*/
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int num = -123;
    int sign = 1;

    string s = to_string(num);

    if (s[0] == '-')
    {
        sign = -1;
        s = s.substr(1);
    }

    reverse(s.begin(), s.end());

    long long ans = stoll(s);
    ans *= sign;

    if (ans > INT_MAX || ans < INT_MIN)
        cout << 0;
    else
        cout << ans;

    return 0;
}