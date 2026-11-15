/*
204. Count Primes

Given an integer n, return the number of prime numbers that are strictly less than n.



Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0


Constraints:

0 <= n <= 5 * 10^6
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bruteForce(int n)
{
    if (n < 2)
        return 0;

    int count = 0;

    for (int i = 2; i < n; i++)
    {
        bool isPrime = true;

        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            count++;
    }
    return count;
}

int optimalApproch(int n)
{
    if (n < 2)
        return 0;

    vector<bool> isPrime(n, true);

    isPrime[0] = false;
    isPrime[1] = false;

    int i = 2;

    while (i * i < n)
    {
        if (isPrime[i])
        {
            int j = i * i;

            while (j < n)
            {
                isPrime[j] = false;
                j += i;
            }
        }
        i++;
    }

    return count(isPrime.begin(), isPrime.end(), true);
}

int main()
{
    cout << bruteForce(10) << endl;
    cout << optimalApproch(10) << endl;

    return 0;
}
