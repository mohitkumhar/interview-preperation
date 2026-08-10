#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;

    /*
     * * * * *
     * * * * *
     * * * * *
     * * * * *
     * * * * *
     */
    n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    cout << "\n\n\n";

    /*
     *
     * *
     * * *
     * * * *
     * * * * *
     */
    n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    cout << "\n\n\n";

    /*
    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5
    */
    n = 5;
    for (int i = 0; i < n; i++)
    {
        int val = 1;
        for (int j = 0; j < i + 1; j++)
        {
            cout << val << " ";
            val += 1;
        }
        cout << endl;
    }

    cout << "\n\n\n";

    /*
    1
    2 2
    3 3 3
    4 4 4 4
    5 5 5 5 5
    */
    n = 5;
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        val += 1;
        for (int j = 0; j < i + 1; j++)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}