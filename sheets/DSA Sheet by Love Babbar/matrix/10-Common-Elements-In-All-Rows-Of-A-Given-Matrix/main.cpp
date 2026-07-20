/*
Common elements in all rows of a given matrix

Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.

Example:

Input:
mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9}};

Output:
1 8 or 8 1
8 and 1 are present in all rows.

*/

// Approch-1 [Brute Force]

// Time  = O(m * n^2)
// Space = O(n)

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void approch_1()
{
    vector<vector<int>> matrix{{1, 2, 1, 4, 8}, {3, 7, 8, 5, 1}, {8, 7, 7, 3, 1}, {8, 1, 2, 7, 9}};

    unordered_set<int> seen;
    vector<int> result;

    int m = matrix.size();
    int n = matrix[0].size();

    for (int k = 0; k < n; k++)
    {
        int val = matrix[0][k];
        if (seen.find(val) != seen.end())
            continue;

        seen.insert(val);
        int count = 1;

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == val)
                {
                    count++;
                    break;
                }
            }
        }
        if (count == m)
            result.push_back(val);
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

// Approch-2 [Binary Search]
// Time  = O(m*n * log(n))
// Space = O(n)

bool binarySearch(vector<int> &nums, int val)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == val)
        {
            return true;
        }
        else if (nums[mid] > val)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return false;
}

void approch_2()
{
    vector<vector<int>> matrix{{1, 2, 1, 4, 8}, {3, 7, 8, 5, 1}, {8, 7, 7, 3, 1}, {8, 1, 2, 7, 9}};

    unordered_set<int> seen;
    vector<int> result;

    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
        sort(matrix[i].begin(), matrix[i].end());

    for (int k = 0; k < n; k++)
    {
        int val = matrix[0][k];
        if (seen.find(val) != seen.end())
            continue;

        seen.insert(val);
        int count = 1;

        for (int i = 1; i < m; i++)
        {
            if (binarySearch(matrix[i], val))
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if (count == m)
        {
            result.push_back(val);
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}

int main()
{
    approch_1();
    approch_2();

    return 0;
}
