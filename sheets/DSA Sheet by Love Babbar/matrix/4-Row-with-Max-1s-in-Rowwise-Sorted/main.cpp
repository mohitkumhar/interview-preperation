/*
https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
Row with Max 1s in Rowwise Sorted
Difficulty: Medium

You are given a 2D binary array arr[][] consisting of only 1s and 0s.
Each row of the array is sorted in non-decreasing order.
Your task is to find and return the index of the first row that contains the maximum number of 1s. If no such row exists, return -1.

Note:

The array follows 0-based indexing.
The number of rows and columns in the array are denoted by n.
Examples:

Input: arr[][] = [[0,1,1,1],
                  [0,0,1,1],
                  [1,1,1,1],
                  [0,0,0,0]]
Output: 2
Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.

Input: arr[][] = [[0,0],
                  [1,1]]
Output: 1
Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.

Input: arr[][] = [[0,0],
                  [0,0]]
Output: -1
Explanation: No row contains any 1s, so the output is -1.

Constraints:
1 ≤ arr.size(), arr[i].size() ≤ 10^3

Expected Complexities
Time Complexity: O(n + m)
Auxiliary Space: O(1)

*/

#include <iostream>
#include <vector>

using namespace std;

// Approch-1 [Brute Force]
// Time  = O(n^2) [rows and cols are expected to be same]
// Space = O(1)

void approch_1()
{
    vector<vector<int>> matrix{{0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};

    int n = matrix.size();
    int j = n - 1;
    int maxOne = -1;
    int maxIdx = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                int totalOne = n - j;
                if (totalOne > maxOne)
                {
                    maxOne = totalOne;
                    maxIdx = i;
                }
                break;
            }
        }
    }

    cout << "Output From First Approch: " << maxIdx << endl;
}

// Approch-2 [Expected Approch]

// Time  - O(n + m) [n and m are same as per question]
// Space - O(1)

void approch_2()
{
    vector<vector<int>> matrix{{0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
    int n = matrix.size();
    int maxIdx = 0;

    int j = n - 1;

    for (int i = 0; i < n; i++)
    {
        while (j > -1)
        {
            if (matrix[i][j] == 0)
                break;
            if (matrix[i][j] == 1)
            {
                maxIdx = i;
                j--;
            }
        }
        if (j == -1)
            break;
    }
    cout << "Output From Second Approch: " << maxIdx << endl;
}

int main()
{
    approch_1();
    approch_2();

    return 0;
}
