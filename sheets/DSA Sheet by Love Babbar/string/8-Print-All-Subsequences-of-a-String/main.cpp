/*
https://www.geeksforgeeks.org/problems/power-set4302/1
All Subsequences of a String
Difficulty: Medium

Given a string s, generate all possible subsequences of the string (including the empty subsequence) and return them in lexicographical order.

A subsequence is obtained by deleting zero or more characters from the string without changing the relative order of the remaining characters.

Examples:

Input : s = "abc"
Output: ["","a", "ab", "abc", "ac", "b", "bc", "c"]
Explanation: There are a total of 8 non-empty subsequences for the given string.
These subsequences are listed above in lexicographical order.

Input: s = "aa"
Output: ["", "a", "a", "aa"]


Constraints:
1 ≤ n ≤ 16
s consists of lowercase English letters.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve(int i, string curr_str, vector<string> &result, string s)
{
    if (i == s.length())
    {
        result.push_back(curr_str);
        return;
    }

    // take
    solve(i + 1, curr_str + s[i], result, s);

    // skip
    solve(i + 1, curr_str, result, s);
}

int main()
{
    string s = "abc";
    int n = s.length();

    vector<string> result;

    solve(0, "", result, s);
    
    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}
