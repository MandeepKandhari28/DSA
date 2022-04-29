/**
 * Find Duplicate
    You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging from 0 to 3 and among these, there is a single integer value that is present twice. You need to find and return that duplicate number present in the array.
    Note :
    Duplicate number is always present in the given array/list.
    Input format :
    The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

    First line of each test case or query contains an integer 'N' representing the size of the array/list.

    Second line contains 'N' single space separated integers representing the elements in the array/list.
    Output Format :
    For each test case, print the duplicate element in the array/list.

    Output for every test case will be printed in a separate line.
    Constraints :
    1 <= t <= 10^2
    0 <= N <= 10^3
    Time Limit: 1 sec
    Sample Input 1:
    1
    9
    0 7 2 5 4 7 1 3 6
    Sample Output 1:
    7
    Sample Input 2:
    2
    5
    0 2 1 3 1
    7
    0 3 1 5 4 3 2
    Sample Output 2:
    1
    3
*/

#include <iostream>
using namespace std;

int duplicateNumber(int *arr, int size)
{
    /*
        As per the condition, in a given array of size N, there will be N - 2 unique values
        ranging from 0 to N - 2. However, there will be one value that is repeated twice to
        fill in the last array of size N.

        If we consider that if the duplicate value was not added then we would have an array
        whose values will start from 0 till N (where order of the numbers with respect to their indexes
        can be interchanged).

        For N = 5: 1 2 0 4 3 from index 0 to 4.

        If we find the difference of these indexes and that of the array elements, it would be zero.
        Similarly, in case there is one element that has been repeated twice we could first
            1. find the sum of the indexes up until N - 2
            2. Find of the sum of all the array elements
            3. Subtract both, the difference will give the number that has been repeated twice.
    */

    int sum_of_unique_numbers = 0;

    for (int index = 0; index <= size - 2; ++index)
    {
        sum_of_unique_numbers += index;
    }

    int sum_of_array = 0;

    for (int index = 0; index < size; ++index)
    {
        sum_of_array += arr[index];
    }

    return sum_of_array - sum_of_unique_numbers;
}

int main()
{

    int size;
    cin >> size;
    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    cout << duplicateNumber(input, size) << endl;

    return 0;
}