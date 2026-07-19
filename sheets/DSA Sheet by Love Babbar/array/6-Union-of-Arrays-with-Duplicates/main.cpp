/*
https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1
Union of Arrays with Duplicates
Difficulty: Easy

You are given two arrays a[] and b[],
return the Union of both the arrays in any order.

The Union of two arrays is a collection of all distinct elements present in either of the arrays. If an element appears more than once in one or both arrays, it should be included only once in the result.

Note: Elements of a[] and b[] are not necessarily distinct.
Note that, You can return the Union in any order but the driver code will print the result in sorted order only.

Examples:

Input: a[] = [1, 2, 3, 2, 1], b[] = [3, 2, 2, 3, 3, 2]
Output: [1, 2, 3]
Explanation: Union set of both the arrays will be 1, 2 and 3.

Input: a[] = [1, 2, 3], b[] = [4, 5, 6]
Output: [1, 2, 3, 4, 5, 6]
Explanation: Union set of both the arrays will be 1, 2, 3, 4, 5 and 6.

Input: a[] = [1, 2, 1, 1, 2], b[] = [2, 2, 1, 2, 1]
Output: [1, 2]
Explanation: Union set of both the arrays will be 1 and 2.

Constraints:
1 ≤ a.size(), b.size() ≤ 10^6
0 ≤ a[i], b[i] ≤ 10^5

Expected Complexities
Time Complexity: O(n + m)
Auxiliary Space: O(n + m)

*/

// Approch- 1 [simple looping]
// Time  = O(n + m)
// Space = O(n + m)

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int approch_1()
{
    unordered_set<int> seen;
    vector<int> nums1{1, 2, 3, 4};
    vector<int> nums2{3, 4, 5, 6};

    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> result;

    for (auto vec : {nums1, nums2})
    {
        for (int num : vec)
        {
            if (seen.find(num) == seen.end())
            {
                seen.insert(num);
                result.push_back(num);
            }
        }
    }

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}

// Approch-2 (taking benefit as both nums are sorted)

// Time  = O(n + m)
// Space = O(1) [aside from result, which is required in output]

int approch_2()
{
    vector<int> nums1{1, 2, 3, 4};
    vector<int> nums2{3, 4, 5, 6};

    vector<int> result;

    int i = 0;
    int j = 0;
    int val;

    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
        {
            val = nums1[i];
            i++;
        }
        else
        {
            val = nums2[j];
            j++;
        }

        if (result.empty() || result.back() != val)
            result.push_back(val);
    }

    while (i < nums1.size())
    {
        val = nums1[i];

        if (result.back() != val)
            result.push_back(val);
        i++;
    }

    while (j < nums2.size())
    {
        val = nums2[j];

        if (result.back() != val)
            result.push_back(val);
        j++;
    }

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}

int main()
{
    approch_1();
    cout << endl;
    approch_2();
    return 0;
}