/**
 * Sort 0 1 2
    You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s. Write a solution to sort this array/list in a 'single scan'.
    'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.
    Note:
    You need to change in the given array/list itself. Hence, no need to return or print anything.
    Input format :
    The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

    First line of each test case or query contains an integer 'N' representing the size of the array/list.

    Second line contains 'N' single space separated integers(all 0s, 1s and 2s) representing the elements in the array/list.
    Output Format :
    For each test case, print the sorted array/list elements in a row separated by a single space.

    Output for every test case will be printed in a separate line.
    Constraints :
    1 <= t <= 10^2
    0 <= N <= 10^5
    Time Limit: 1 sec
    Sample Input 1:
    1
    7
    0 1 2 0 2 0 1
    Sample Output 1:
    0 0 0 1 1 2 2
    Sample Input 2:
    2
    5
    2 2 0 1 1
    7
    0 1 2 0 1 2 0
    Sample Output 2:
    0 1 1 2 2
    0 0 0 1 1 2 2
*/

/**
 * Approach 1: Use the Merge sort where the time complexity will of order O(nlogn).
 *
 * Approach2: Iterate through the loop while incrementing the count for each 0,1, and 2 encountered, then f
 *  fill the original array as per the count. The time complexity will be of O(2N) approx O(N).
 *
 * Apprqach 3: Take a zeroIndex that will point to the next non zero position where we should swap a zero
 * and an endIndex that will point to the next non Zero two index. Then fill up the temp array for the zeros
 * and two's from the end. Once the loop completes run another loop and iterate from zeroIndex to endIndex and place 1's
 *
 * then copy the elements from the temp array to the original array
 *
 */

#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int *input, int n)
{
    // Write your code here
    int zeroIndex = 0, endIndex = n - 1;

    for (int index = 0; index <= endIndex;)
    {

        if (input[index] == 1)
        {
            index++;
            continue;
        }

        if (input[index] == 0)
        {
            int temp = input[zeroIndex];
            input[zeroIndex] = input[index];
            input[index++] = temp;
            zeroIndex++;
            continue;
        }

        if (input[index] == 2)
        {
            int temp = input[endIndex];
            input[endIndex] = input[index];
            input[index] = temp; // Do not increment the index since we would need to check its position and this element might get lost
            endIndex--;
        }
    }
}

int main()
{
    int size;

    cin >> size;
    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    sort012(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
    cout << endl;

    return 0;
}