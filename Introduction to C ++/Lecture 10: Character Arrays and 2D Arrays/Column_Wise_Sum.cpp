/**
 * Column Wise Sum
    Given a 2D integer array of size M*N, find and print the sum of ith column elements separated by space.
    Input Format :
    First and only line of input contains M and N, followed by M * N space separated integers representing the elements in the 2D array.
    Output Format :
    Sum of every ith column elements (separated by space)
    Constraints :
    1 <= M, N <= 10^3
    Sample Input :
    4 2 1 2 3 4 5 6 7 8
    Sample Output :
    16 20
*/

#include <iostream>
using namespace std;

int main()
{

    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */

    int rows, columns;
    cin >> rows >> columns;

    int arr[rows][columns];
    // Take the input from the user
    for (int index = 0; index < rows; ++index)
    {
        for (int j = 0; j < columns; ++j)
        {
            cin >> arr[index][j];
        }
    }

    // Evaluate the sum of the column items
    for (int j = 0; j < columns; ++j)
    {
        int colSum = 0;
        for (int index = 0; index < rows; ++index)
        {
            colSum += arr[index][j];
        }

        cout << colSum << " ";
    }

    return 0;
}
