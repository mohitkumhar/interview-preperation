/*
https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

Longest Palindrome in a String
Difficulty: Medium

Given a string s, your task is to find the longest palindromic substring within s.

A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).

A palindrome is a string that reads the same forward and backward. More formally, s is a palindrome if reverse(s) == s.

Note: If there are multiple palindromic substrings with the same length, return the first occurrence of the longest palindromic substring from left to right.

Examples :
Input: s = “forgeeksskeegfor”
Output: “geeksskeeg”
Explanation: There are several possible palindromic substrings like “kssk”, “ss”, “eeksskee” etc. But the substring “geeksskeeg” is the longest among all.

Input: s = “Geeks”
Output: “ee”
Explanation: "ee" is the longest palindromic substring of "Geeks".

Input: s = “abc”
Output: “a”
Explanation: "a", "b" and "c" are longest palindromic substrings of same length. So, the first occurrence is returned.

Constraints:
1 ≤ s.size() ≤ 103
s consist of only lowercase English letters.

Expected Complexities
Time Complexity: O(n^2)
Auxiliary Space: O(1)

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Approch- 1 [Brute Force]
// Time  - O(n^3)
// Space - O(1)

bool is_pal(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void approch_1()
{
    string s = "forgeeksskeegfor";
    string ans = "";

    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (is_pal(s, i, j))
                if ((j - i + 1) > ans.size())
                    ans = s.substr(i, j - i + 1);
        }
    }
    cout << ans << endl;
}

// Approch- 2 [DP]
// Time  - O(n^2)
// Space - O(n^2)

void approch_2()
{
    string s = "forgeeksskeegfor";
    int n = s.length();

    vector<vector<bool>> dp(n, vector<bool>(n));

    for (int L = 1; L <= n; L++)
    {
        int i = 0;
        while ((i + L - 1) < n)
        {
            int j = i + L - 1;

            if (L == 1)
                dp[i][j] = true;
            else if (L == 2)
                dp[i][j] = s[i] == s[j];
            else
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1] == true;
            i++;
        }
    }

    string ans = "";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == true)
            {
                if ((j - i + 1) > ans.length())
                    ans = s.substr(i, j - i + 1);
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    approch_1();
    approch_2();

    return 0;
}
