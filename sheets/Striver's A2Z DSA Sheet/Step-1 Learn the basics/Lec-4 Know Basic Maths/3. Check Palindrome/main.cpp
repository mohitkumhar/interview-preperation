/*
https://leetcode.com/problems/palindrome-number

Palindrome Number
Easy

Given an integer x, return true if x is a palindrome, and false otherwise.



Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Constraints:

-2^31 <= x <= 2^31 - 1

Follow up: Could you solve it without converting the integer to a string?
*/

#include <iostream>
#include <string>

using namespace std;

// Approch- 1 [Converting into String]

void approch_1(void)
{
    int num = 1221;

    string nums = to_string(num);

    int i = 0;
    int j = nums.size() - 1;

    while (i < j)
    {
        if (nums[i] != nums[j])
        {
            cout << "Not Pal" << endl;
            return;
        }
        i++;
        j--;
    }
    cout << "Is Pal" << endl;
    return;
}

// Approch- 2 [Wiithout Converting into String]

void approch_2(void)
{
    int num = 123321;

    int original = num;
    long reversed = 0;

    while (num > 0)
    {
        int digit = num % 10;
        reversed = (10 * reversed) + digit;
        num = num / 10;
    }

    if (original == reversed)
    {
        cout << "Is Pal" << endl;
        return;
    }
    cout << "Not Pal" << endl;
}

int main()
{
    approch_1();
    approch_2();

    return 0;
}