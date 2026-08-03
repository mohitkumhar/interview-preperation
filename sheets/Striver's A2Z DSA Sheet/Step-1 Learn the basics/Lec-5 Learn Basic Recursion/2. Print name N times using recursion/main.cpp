/*
Print Name n times using Recursion

Given an integer n, write a program to print your name n times.

Examples
Input: n = 3
Output: Mohit Mohit Mohit
Explanation: Name is printed 3 times.

Input: n = 1
Output: Mohit
Explanation: Name is printed once.
*/

#include <iostream>
#include <string>

using namespace std;

void solve(int n, string name)
{
    if (n == 0)
        return;

    cout << name << " ";
    solve(n - 1, name);
}
int main()
{
    solve(5, "Mohit");

    return 0;
}