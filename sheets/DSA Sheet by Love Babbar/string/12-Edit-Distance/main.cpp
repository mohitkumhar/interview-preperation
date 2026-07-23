/*
https://www.geeksforgeeks.org/problems/edit-distance3702/1
Edit Distance
Difficulty: Hard

Given two strings s1 and s2. Return the minimum number of operations required to convert s1 to s2.
The possible operations are permitted:

- Insert a character at any position of the string.
- Remove any character from the string.
- Replace any character from the string with any other character.

Examples:

Input: s1 = "geek", s2 = "gesek"
Output: 1
Explanation: One operation is required, inserting 's' between two 'e' in s1.

Input: s1 = "gfg", s2 = "gfg"
Output: 0
Explanation: Both strings are same.

Input: s1 = "abcd", s2 = "bcfe"
Output: 3
Explanation: We can convert s1 into s2 by removing 'a', replacing 'd' with 'f' and inserting 'e' at the end.

Constraints:
1 ≤ s1.length(), s2.length() ≤ 10^3
Both the strings are in lowercase.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int i, int j, string s1, string s2, vector<vector<int>> &memo)
{
    if (i == s1.length())
        return s2.length() - j;
    if (j == s2.length())
        return s1.length() - i;

    if (memo[i][j] != -1)
        return memo[i][j];

    if (s1[i] == s2[j])
    {
        memo[i][j] = solve(i + 1, j + 1, s1, s2, memo);
        return memo[i][j];
    }

    // insert
    int insert = 1 + solve(i, j + 1, s1, s2, memo);

    // replace
    int replace = 1 + solve(i + 1, j + 1, s1, s2, memo);

    // delete
    int del = 1 + solve(i + 1, j, s1, s2, memo);

    memo[i][j] = min({insert, replace, del});
    return memo[i][j];
}

int main()
{
    string s1 = "abcd";
    string s2 = "bcfe";

    vector<vector<int>> memo(s1.length() + 1, vector<int>(s2.length() + 1, -1));

    int minOperation = solve(0, 0, s1, s2, memo);

    cout << minOperation << endl;

    return 0;
}
