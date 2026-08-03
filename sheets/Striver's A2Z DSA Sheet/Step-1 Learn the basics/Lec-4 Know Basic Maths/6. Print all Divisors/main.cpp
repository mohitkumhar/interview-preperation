/*
Divisors of a Number

You are given an integer n.
You need to find all the divisors of n.
Return all the divisors of n as an array or list in a sorted order.


A number which completely divides another number is called it's divisor.


Example 1
Input: n = 6
Output = [1, 2, 3, 6]
Explanation: The divisors of 6 are 1, 2, 3, 6.

Example 2
Input: n = 8
Output: [1, 2, 4, 8]
Explanation: The divisors of 8 are 1, 2, 4, 8.

Constraints
1 <= n <= 1000

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n = 6;
    vector<int> result;

    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            result.push_back(i);

    for (int j = 0; j < result.size(); j++)
        cout << result[j] << " ";

    return 0;
}