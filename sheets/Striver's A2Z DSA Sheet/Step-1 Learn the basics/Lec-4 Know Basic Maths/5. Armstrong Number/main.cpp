/*
Armstrong Number

Given an integer n, determine whether it is an Armstrong Number.

An Armstrong Number is a number that is equal to the sum of its digits, where each digit is raised to the power of the total number of digits in the number.

Return True if `N` is an Armstrong Number; otherwise, return False.


Example 1
Input: n = 153
Output:True
Explanation
* Number of digits = 3
* (1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153)

Since the sum equals the original number, **153 is an Armstrong Number**.

* Time Complexity: (O(D)), where D is the number of digits in `N`.
* Space Complexity: (O(1))
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int nums = 153;
    string value = to_string(nums);

    int n = value.size();

    int ans = 0;
    for (char num : value)
    {
        ans += round(pow(num - '0', n));
    }
    cout << ans << endl;

    return 0;
}