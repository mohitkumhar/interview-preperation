/*
Check for Prime Number

You are given an integer n. You need to check if the number is prime or not.
Return true if it is a prime number, otherwise return false.

A prime number is a number which has no divisors except 1 and itself.

Example 1
Input: n = 5
Output: true
Explanation: The only divisors of 5 are 1 and 5 , So the number 5 is prime.

Example 2
Input: n = 8
Output: false
Explanation: The divisors of 8 are 1, 2, 4, 8, thus it is not a prime number.

Constraints
1 <= n <= 5000
*/

#include <iostream>

using namespace std;

int main()
{
    int n = 112;
    bool is_prime = true;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            is_prime = false;
            break;
        }
    }
    if (is_prime == true)
        cout << "Number is Prime" << endl;
    else
        cout << "Number is not Prime" << endl;

    return 0;
}
