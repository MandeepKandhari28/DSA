/**
 * Print the following pattern for the given number of rows.
    Pattern for N = 4
    1
    212
    32123
    4321234
    Input format : N (Total no. of rows)

    Output format : Pattern in N lines

    Sample Input :
    5
    Sample Output :
            1
        212
        32123
    4321234
    543212345
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

        // Print the spaces in the first section
        int spaces = 1;
        while (spaces <= number - row)
        {
            cout << " ";
            spaces++;
        }

        // Print the numbers in decreasing order
        int col1 = row;
        while (col1 >= 1)
        {
            cout << col1;
            col1--;
        }

        // Print the numbers in increasing order
        int col2 = 2;
        while (col2 <= row)
        {
            cout << col2;
            col2++;
        }

        // Print the spaces in the second section
        spaces = 1;
        while (spaces <= number - row)
        {
            cout << " ";
            spaces++;
        }

        cout << endl;
        row++;
    }
}
