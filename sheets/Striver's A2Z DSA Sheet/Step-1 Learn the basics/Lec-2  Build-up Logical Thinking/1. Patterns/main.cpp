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

    cout << "\n\n\n";

    /*
     * * * * *
     * * * *
     * * *
     * *
     *
     */
    n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    cout << "\n\n\n";

    /*
    1 2 3 4 5
    1 2 3 4
    1 2 3
    1 2
    1
    */
    n = 5;
    for (int i = 0; i < n; i++)
    {
        int val = 1;
        for (int j = 0; j < n - i; j++)
        {
            cout << val << " ";
            val += 1;
        }
        cout << endl;
    }

    cout << "\n\n\n";

    /*
     *
     * * *
     * * * * *
     * * * * * * *
     * * * * * * * * *
     */
    n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < i + 1; k++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    cout << "\n\n\n";

    /*
     * * * * * * * * *
     * * * * * * *
     * * * * *
     * * *
     *
     */
    n = 5;
    int stars = 9;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }
        for (int k = 0; k < stars; k++)
        {
            cout << "* ";
        }
        cout << endl;
        stars -= 2;
    }

    cout << "\n\n\n";

    /*
     *
     * * *
     * * * * *
     * * * * * * *
     * * * * * * * * *
     * * * * * * * * *
     * * * * * * *
     * * * * *
     * * *
     *
     */
    n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "  ";
        }
        for (int k = 0; k < i + 1; k++)
        {
            cout << "*  ";
        }
        cout << endl;
    }

    stars = 9;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }
        for (int k = 0; k < stars; k++)
        {
            cout << "* ";
        }
        cout << endl;
        stars -= 2;
    }

    cout << "\n\n\n";

    /*
     *
     * *
     * * *
     * * * *
     * * * * *
     * * * *
     * * *
     * *
     *
     */
    n = 5;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}