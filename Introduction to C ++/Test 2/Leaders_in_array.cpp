/**
 * Leaders in array
    Given an integer array A of size n. Find and print all the leaders present in the input array. An array element A[i] is called Leader, if all the elements following it (i.e. present at its right) are less than or equal to A[i].
    Print all the leader elements separated by space and in the same order they are present in the input array.
    Input Format :
    Line 1 : Integer n, size of array
    Line 2 : Array A elements (separated by space)
    Output Format :
    leaders of array (separated by space)
    Constraints :
    1 <= n <= 10^6
    Sample Input 1 :
    6
    3 12 34 2 0 -1
    Sample Output 1 :
    34 2 0 -1
    Sample Input 2 :
    5
    13 17 5 4 6
    Sample Output 2 :
    17 6
*/

/**
 * Leaders in Array means pick the largest element starting from the end of the array. For eg:
 * input: 485 28 127 181 159 255 316 117 179 120
 * output: 120 179 316 485 (i.e. find the largest element starting from the end of the array)
 */

#include <iostream>
#include <climits>
using namespace std;

void Leaders(int *arr, int len)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print your output exactly in the same format as shown.
     * Don't print any extra line.
     */
    int *output = new int[len];

    int leaderIndex = 0, largest = INT_MIN;

    for (int index = len - 1; index >= 0; --index)
    {
        if (largest <= arr[index])
        {
            largest = arr[index];
            output[++leaderIndex] = largest;
        }
    }

    for (int index = leaderIndex; index > 0; --index)
    {
        cout << output[index] << " ";
    }
}

int main()
{
    int len;
    cin >> len;
    int *arr = new int[len + 1];

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    Leaders(arr, len);
}
