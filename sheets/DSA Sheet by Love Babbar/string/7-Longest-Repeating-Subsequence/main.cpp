/*
https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
Longest Repeating Subsequence
Difficulty: Medium

Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

The two identified subsequences A and B can use the same ith character from string s if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of the first "x" must be different in the original string for A and B.

Examples :

Input: s = "axxzxy"
Output: 2
Explanation: The given array with indexes looks like
a x x z x y
0 1 2 3 4 5
The longest subsequence is "xx". It appears twice as explained below.
subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of s
subsequence B
x x
0 1  <-- index of subsequence B
------
2 4  <-- index of s
We are able to use character 'x' (at index 2 in s) in both subsequences as it appears on index 1 in subsequence A and index 0 in subsequence B.

Input: s = "axxxy"
Output: 2
Explanation: The given array with indexes looks like
a x x x y
0 1 2 3 4
The longest subsequence is "xx". It appears twice as explained below.
subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of s
subsequence B
x x
0 1  <-- index of subsequence B
------
2 3  <-- index of s
We are able to use character 'x' (at index 2 in s) in both subsequencesas it appears on index 1 in subsequence A and index 0 in subsequence B.

Constraints:
1 <= s.size() <= 10^3

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s = "axxxy";

    string s1 = s;
    string s2 = s;
    int n = s.length();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][n] << endl;

    return 0;
}
