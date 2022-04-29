/**
 * Number Star Pattern
    Print the following pattern for given number of rows.
    Input format :

    Line 1 : N (Total number of rows)

    Sample Input :
    5
    Sample Output :
    1234554321
    1234**4321
    123****321
    12******21
    1********1
*/

#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int number;
    cin >> number;

    int row = 1;

    while (row <= number)
    {
        // Print the numbers in increasing order
        int col1 = 1;
        while (col1 <= number - row + 1)
        {
            cout << col1;
            col1++;
        }

        // Print the spaces in the first half
        int spaces = 1;
        while (spaces <= row - 1)
        {
            cout << "*";
            spaces++;
        }

        // Print the spaces in the second half
        spaces = 1;
        while (spaces <= row - 1)
        {
            cout << "*";
            spaces++;
        }

        // Print the numbers in decreasing order
        col1 = number - row + 1;
        while (col1 >= 1)
        {
            cout << col1;
            col1--;
        }

        cout << endl;
        row++;
    }
}
