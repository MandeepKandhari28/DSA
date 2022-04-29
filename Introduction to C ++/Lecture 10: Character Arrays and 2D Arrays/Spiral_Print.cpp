/**
 * Spiral Print
    For a given two-dimensional integer array/list of size (N x M), print it in a spiral form. That is, you need to print in the order followed for every iteration:
    a. First row(left to right)
    b. Last column(top to bottom)
    c. Last row(right to left)
    d. First column(bottom to top)
    Mind that every element will be printed only once.
    Refer to the Image:
    Spiral path of a matrix

    Input format :
    The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

    First line of each test case or query contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

    Second line onwards, the next 'N' lines or rows represent the ith row values.

    Each of the ith row constitutes 'M' column values separated by a single space.
    Output format :
    For each test case, print the elements of the two-dimensional array/list in the spiral form in a single line, separated by a single space.

    Output for every test case will be printed in a seperate line.
    Constraints :
    1 <= t <= 10^2
    0 <= N <= 10^3
    0 <= M <= 10^3
    Time Limit: 1sec
    Sample Input 1:
    1
    4 4
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
    Sample Output 1:
    1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
    Sample Input 2:
    2
    3 3
    1 2 3
    4 5 6
    7 8 9
    3 1
    10
    20
    30
    Sample Output 2:
    1 2 3 6 9 8 7 4 5
    10 20 30
*/

#include <iostream>
using namespace std;

void spiralPrint(int **input, int nRows, int nCols)
{
    // Write your code here
    int rowStart = 0, colStart = 0;
    int rowEnd = nRows - 1, colEnd = nCols - 1;

    while (rowStart <= rowEnd && colStart <= colEnd)
    {
        int row = rowStart, col = colStart;
        // Print the first Row
        for (; col < nCols - colStart; ++col)
        {
            cout << input[row][col] << " ";
        }

        // Decrease the col value by 1 so to get to the end column and
        // increase the row value to point it to the next element in the same row
        col--;
        row++;

        // Print the last row
        for (; row < nRows - rowStart; ++row)
        {
            cout << input[row][col] << " ";
        }

        // Decrease the column by 1 to point to the next element that needs to be printed
        // Decrease the row by 1 so to get to the end of the row
        row--;
        col--;

        // Print the last column
        for (; col >= colStart; col--)
        {
            cout << input[row][col] << " ";
        }

        // Increase the column by 1 to point to the first column
        // Decrease the row to point to the next element that needs to be printed
        col++;
        row--;

        for (; row > rowStart; --row)
        {
            cout << input[row][col] << " ";
        }

        rowStart++;
        colStart++;
    }
}

int main()
{
    int row, col;
    cin >> row >> col;
    int **matrix = new int *[row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    spiralPrint(matrix, row, col);

    for (int i = 0; i < row; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    cout << endl;
}