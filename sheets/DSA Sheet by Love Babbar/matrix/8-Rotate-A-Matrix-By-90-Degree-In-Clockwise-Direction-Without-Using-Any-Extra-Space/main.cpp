/*
https://www.geeksforgeeks.org/dsa/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/
Rotate an Image 90 Degree Clockwise

Given a square matrix mat[][], turn it by 90 degrees in an clockwise direction without using any extra space

Examples:

Input: mat[][] = {{1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}}
Output: {{7, 4, 1},
    {8, 5, 2},
    {9, 6, 3}}

Input: mat[][] = {{1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11,12}
    {13, 14, 15, 16}}
Output: {{13, 9, 5, 1},
    {14, 10, 6, 2},
    {15, 11, 7, 3},
    {16, 12, 8, 4}}

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int n = matrix.size();

    vector<vector<int>> result(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[j][n - i - 1] = matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
