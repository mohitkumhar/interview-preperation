/*
Word Break
Difficulty: Medium

You are given a string s and a list dictionary[] of words. Your task is to determine whether the string s can be formed by concatenating one or more words from the dictionary[].

Note: From dictionary[], any word can be taken any number of times and in any order.

Examples :
Input: s = "ilike", dictionary[] = ["i", "like", "gfg"]
Output: true
Explanation: s can be breakdown as "i like".

Input: s = "ilikegfg", dictionary[] = ["i", "like", "man", "india", "gfg"]
Output: true
Explanation: s can be breakdown as "i like gfg".

Input: s = "ilikemangoes", dictionary[] = ["i", "like", "man", "india", "gfg"]
Output: false
Explanation: s cannot be formed using dictionary[] words.

Constraints:
1 ≤ s.size() ≤ 3000
1 ≤ dictionary.size() ≤ 1000
1 ≤ dictionary[i].size() ≤ 100

Expected Complexities
Time Complexity: O(n * m)
Auxiliary Space: O(n)

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool solve(int i, string s, unordered_set<string> &dict, vector<int> &memo)
{
    if (i == s.length())
        return true;
    if (memo[i] != 0)
        return memo[i];

    for (int j = i; j < s.length(); j++)
        if (dict.find(s.substr(i, j - i + 1)) != dict.end() && solve(j + 1, s, dict, memo))
        {
            memo[i] = true;
            return memo[i];
        }
    memo[i] = false;
    return memo[i];
}

int main()
{
    string s = "ilikegfg";
    vector<string> dictionary = {"i", "like", "man", "india", "gfg"};

    int n = s.length();
    unordered_set<string> dict(dictionary.begin(), dictionary.end());

    vector<int> memo(n, 0);

    if (solve(0, s, dict, memo))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
