/*
https://www.geeksforgeeks.org/problems/search-pattern0205/1
Search Pattern
Difficulty: Hard

Given two strings, a text string txt and a pattern string pat, both consisting of lowercase English alphabets. Return the starting indices (0-based) of all the occurrences of the pattern string pat in the text string txt.

Note: Return an empty list in case of no occurrences of pattern.

Examples:

Input: txt = "geeksforgeeks", pat = "geek"
Output: [0, 8]
Explanation: The string "geek" occurs twice in txt, one starts at index 0 and the other at index 8.

Input: txt = "abesdu", pat = "edu"
Output: []
Explanation: There's no substring "edu" present in txt.

Input: txt = "aabaacaadaabaaba", pat = "aaba"
Output: [0, 9, 12]
Explanation:

Constraints:
1 ≤ txt.size() ≤ 10^5
1 ≤ pat.size() ≤ txt.size()

Expected Complexities
Time Complexity: O(n + m)
Auxiliary Space: O(m)

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s = "geeksforgeeks";
    string pattern = "geek";

    int n = s.length();
    int m = pattern.length();

    vector<int> LPS(m, 0);
    LPS[0] = 0;
    int length_idx = 0;

    int k = 1;

    while (k < m)
    {
        if (pattern[k] == pattern[length_idx])
        {
            length_idx++;
            LPS[k] = length_idx;
            k++;
        }
        else
        {
            if (length_idx == 0)
            {
                LPS[k] = 0;
                k++;
            }
            else
                length_idx = LPS[length_idx - 1];
        }
    }

    int i = 0;
    int j = 0;

    vector<int> result;

    while (i < n)
    {
        if (s[i] == pattern[j])
        {
            i++;
            j++;
            if (j == m)
            {
                result.push_back(i - m);
                j = LPS[j - 1];
            }
        }
        else
        {
            if (j == 0)
                i++;
            else
                j = LPS[j - 1];
        }
    }


    
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}
