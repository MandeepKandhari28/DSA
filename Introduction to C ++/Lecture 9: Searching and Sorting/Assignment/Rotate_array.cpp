/**
 * Rotate array
    You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).
    Note:
    Change in the input array/list itself. You don't need to return or print the elements.
    Input format :
    The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

    First line of each test case or query contains an integer 'N' representing the size of the array/list.

    Second line contains 'N' single space separated integers representing the elements in the array/list.

    Third line contains the value of 'D' by which the array/list needs to be rotated.
    Output Format :
    For each test case, print the rotated array/list in a row separated by a single space.

    Output for every test case will be printed in a separate line.
    Constraints :
    1 <= t <= 10^4
    0 <= N <= 10^6
    0 <= D <= N
    Time Limit: 1 sec
    Sample Input 1:
    1
    7
    1 2 3 4 5 6 7
    2
    Sample Output 1:
    3 4 5 6 7 1 2
    Sample Input 2:
    2
    7
    1 2 3 4 5 6 7
    0
    4
    1 2 3 4
    2
    Sample Output 2:
    1 2 3 4 5 6 7
    3 4 1 2
*/

#include <iostream>
using namespace std;

void reverseArray(int *input, int startIndex, int endIndex)
{
    int temp = 0;
    while (startIndex < endIndex)
    {
        temp = input[startIndex];
        input[startIndex] = input[endIndex];
        input[endIndex] = temp;

        startIndex++;
        endIndex--;
    }
}

void rotate(int *input, int d, int n)
{
    // Write your code here
    reverseArray(input, 0, n - 1);
    reverseArray(input, 0, n - 1 - d);
    reverseArray(input, n - d, n - 1);
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; ++i)
    {
        cin >> input[i];
    }

    int d;
    cin >> d;

    rotate(input, d, size);

    for (int i = 0; i < size; ++i)
    {
        cout << input[i] << " ";
    }

    delete[] input;
    cout << endl;

    return 0;
}

/**
 * Approach 1: For Array 2 6 3 1 5 9 8 and D = 2
 * 1. First reverse the original array which will result in 8 9 5 1 3 6 2
 *
 * 2. Then reverse the Array from 0 to size - 1 - d(rotations needed) which will result in 3 1 5 9 8 6 2
 *
 * 3. Then reverse the Array from size - d to size - 1 which will result in 3 1 5 9 8 2 6
 */

/**
 * Approach 2: For Array 2 6 3 1 5 9 8 and D = 2
 *
 * 1. Copy the first d element of the original array to another array.
 *
 * 2. left shift the array by d positions so like input[index] = input[index + d]
 *    The array will look like: 3 1 5 9 8 9 8
 *
 * 3. copy the elements from size - d to size - 1 positions from the temp array into the original array
 *    The array will look like: 3 1 5 9 8 2 6
 */
