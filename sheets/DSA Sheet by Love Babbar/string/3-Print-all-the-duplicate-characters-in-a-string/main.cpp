/*
https://www.geeksforgeeks.org/dsa/print-all-the-duplicates-in-the-input-string/
Print all the duplicate characters in a string

Given a string s, the task is to identify all characters that appear more than once and print each as a list containing the character and its count.

Examples:
Input: s = "geeksforgeeks"
Output: ['e', 4], ['g', 2], ['k', 2], ['s', 2]
Explanation: Characters e, g, k, and s appear more than once. Their counts are shown in order of first occurrence.

Input: s = "programming"
Output: ['r', 2], ['g', 2], ['m', 2]
Explanation: Only r, g, and m are duplicates. Output lists them with their counts.

Input: s = "mississippi"
Output: ['i', 4], ['s', 4], ['p', 2]
Explanation: Characters i, s, and p have multiple occurrences. The output reflects that with count and order preserved.

Table of Content:
[Approach - 1] Using Sorting - O(n*log(n)) Time and O(1) Space
[Approach - 2] Using Hashing - O(n) Time and O(k) Space

*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    string s = "programming";

    map<char, int> freq;

    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]]++;
    }

    vector<pair<char, int>> result;
    for (const auto &pair : freq)
    {
        if (pair.second > 1)
        {
            result.push_back(pair);
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << "[" << result[i].first << ": " << result[i].second << "]" << " ";
    }
}
