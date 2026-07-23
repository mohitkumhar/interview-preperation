/*
https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1
Longest Prefix Suffix
Difficulty: Hard

Given a string s, of lowercase english alphabets, find the length of the longest proper prefix which is also a suffix.
Note: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Examples :
Input: s = "abab"
Output: 2
Explanation: The string "ab" is the longest prefix and suffix.

Input: s = "aabcdaabc"
Output: 4
Explanation: The string "aabc" is the longest prefix and suffix.

Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest prefix and suffix.

Constraints:
1 ≤ s.size() ≤ 10^6
s contains only lowercase English alphabets.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s = "aaaa";
    int n = s.length();

    vector<int> LPS(n, 0);
    LPS[0] = 0;
    int length_idx = 0;

    int i = 1;

    while (i < n)
    {
        if (s[i] == s[length_idx])
        {
            length_idx++;
            LPS[i] = length_idx;
            i++;
        }
        else
        {
            if (length_idx == 0)
            {
                LPS[i] = 0;
                i++;
            }
            else
                length_idx = LPS[length_idx - 1];
        }
    }

    for (int i = 0; i < LPS.size(); i++)
        cout << LPS[i] << " ";
    
    cout <<endl << LPS[n - 1] << endl;
    return 0;
}
