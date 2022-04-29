/**
 * Pair sum in array
    You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.
    Note:
    Given array/list can contain duplicate elements.
    Input format :
    The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

    First line of each test case or query contains an integer 'N' representing the size of the first array/list.

    Second line contains 'N' single space separated integers representing the elements in the array/list.

    Third line contains an integer 'num'.
    Output format :
    For each test case, print the total number of pairs present in the array/list.

    Output for every test case will be printed in a separate line.
    Constraints :
    1 <= t <= 10^2
    0 <= N <= 10^4
    0 <= num <= 10^9

    Time Limit: 1 sec
    Sample Input 1:
    1
    9
    1 3 6 2 5 4 3 2 4
    7
    Sample Output 1:
    7
    Sample Input 2:
    2
    9
    1 3 6 2 5 4 3 2 4
    12
    6
    2 8 10 5 -2 5
    10
    Sample Output 2:
    0
    2


    Explanation for Input 2:
    Since there doesn't exist any pair with sum equal to 12 for the first query, we print 0.

    For the second query, we have 2 pairs in total that sum up to 10. They are, (2, 8) and (5, 5).
*/
#include <iostream>
#include <algorithm>
using namespace std;

void merge_two_sorted_arrays(int *arr, int startIndex, int mid, int endIndex)
{
    int index = startIndex, j = mid + 1, outputIndex = 0;
    int *output = new int[endIndex - startIndex + 1];

    while (index <= mid && j <= endIndex)
    {
        if (arr[index] <= arr[j])
        {
            output[outputIndex++] = arr[index++];
        }
        else
        {
            output[outputIndex++] = arr[j++];
        }
    }

    while (index <= mid)
    {
        output[outputIndex++] = arr[index++];
    }

    while (j <= endIndex)
    {
        output[outputIndex++] = arr[j++];
    }

    outputIndex = 0;
    for (int index = startIndex; index <= endIndex; ++index)
    {
        arr[index] = output[outputIndex++];
    }
}

void merge_sort(int *arr, int startIndex, int endIndex)
{
    // Base Case
    if (startIndex >= endIndex)
    {
        return;
    }

    int mid = (startIndex + endIndex) / 2;

    merge_sort(arr, startIndex, mid);
    merge_sort(arr, mid + 1, endIndex);

    merge_two_sorted_arrays(arr, startIndex, mid, endIndex);
}

int pairSum(int *arr, int n, int num)
{
    // Write your code here
    merge_sort(arr, 0, n - 1);

    for (int index = 0; index < n; ++index)
    {
        cout << arr[index] << " ";
    }

    cout << endl;

    int startIndex = 0, endIndex = n - 1, count = 0;
    ;

    while (startIndex < endIndex)
    {
        if (arr[startIndex] + arr[endIndex] > num)
        {
            endIndex--;
        }
        else if (arr[startIndex] + arr[endIndex] < num)
        {
            startIndex++;
        }
        else
        {
            if (arr[startIndex] != arr[startIndex + 1] && arr[endIndex] != arr[endIndex - 1] && startIndex < endIndex)
            {
                startIndex++;
                endIndex--;
                count++;
                continue;
            }

            if (arr[startIndex] == arr[startIndex + 1] && arr[endIndex] != arr[endIndex - 1])
            {
                int index1 = startIndex, numCount1 = 1;
                while (arr[index1] == arr[index1 + 1] && index1 < endIndex)
                {
                    numCount1++;
                    index1++;
                }

                count += numCount1;
                startIndex = index1;
                endIndex--;
                continue;
            }

            if (arr[startIndex] != arr[startIndex + 1] && arr[endIndex] == arr[endIndex - 1])
            {
                int index2 = endIndex, numCount2 = 1;
                while (arr[index2] == arr[index2 - 1] && index2 > startIndex)
                {
                    numCount2++;
                    index2--;
                }
                count += numCount2;
                startIndex++;
                endIndex = index2;
                continue;
            }

            if (arr[startIndex] == arr[startIndex + 1] && arr[endIndex] == arr[endIndex - 1] && startIndex < endIndex)
            {
                int index1 = startIndex, index2 = endIndex, numCount1 = 1, numCount2 = 1;
                while (arr[index1] == arr[index1 + 1])
                {
                    numCount1++;
                    index1++;
                }

                while (arr[index2] == arr[index2 + 1])
                {
                    numCount2++;
                    index2++;
                }

                count += numCount1 * numCount2;
                startIndex = index1;
                endIndex = index2;
            }
        }
    }

    return count;
}

int main()
{
    int size;
    int x;

    cin >> size;
    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    cin >> x;

    cout << pairSum(input, size, x) << endl;

    delete[] input;

    return 0;
}

/**
 * 1
5
3 3 2 2 2
5
*/