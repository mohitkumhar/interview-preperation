// Factorial of N numbers

#include <iostream>

using namespace std;

int solve(int num)
{
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;

    return num * solve(num - 1);
}

int main()
{
    cout << solve(5) << endl;

    return 0;
}
