/**
 * Print Subsets of Array
    Given an integer array (of length n), find and print all the subsets of input array.
    Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
    Note : The order of subsets are not important. Just print the subsets in different lines.
    Input format :
    Line 1 : Integer n, Size of array
    Line 2 : Array elements (separated by space)
    Constraints :
    1 <= n <= 15
    Sample Input:
    3
    15 20 12
    Sample Output:
    [] (this just represents an empty array, don't worry about the square brackets)
    12
    20
    20 12
    15
    15 12
    15 20
    15 20 12
*/

#include <iostream>
using namespace std;

void printSubsets(int input[], int inputSize, int output[], int outputSize)
{

    // Base Case
    if (inputSize == 0)
    {
        for (int index = 0; index < outputSize; ++index)
        {
            cout << output[index] << " ";
        }
        cout << endl;
        return;
    }

    // Recursive Call 1
    printSubsets(input + 1, inputSize - 1, output, outputSize);

    // Recursion Call 2
    int outputArray[1000];
    for (int index = 0; index < outputSize; ++index)
    {
        outputArray[index] = output[index];
    }
    outputArray[outputSize] = input[0];

    printSubsets(input + 1, inputSize - 1, outputArray, outputSize + 1);
}

void printSubsetsOfArray(int input[], int size)
{
    // Write your code here
    int *output = new int[size];
    printSubsets(input, size, output, 0);
    delete[] output;
}

int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}
