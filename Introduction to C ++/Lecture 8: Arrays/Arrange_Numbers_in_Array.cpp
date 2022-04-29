/**
 * Arrange Numbers in Array
    You have been given an empty array(ARR) and its size N. The only input taken from the user will be N and you need not worry about the array.
    Your task is to populate the array using the integer values in the range 1 to N(both inclusive) in the order - 1,3,.......4,2.
    Note:
    You need not print the array. You only need to populate it.
    Input Format :
    The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

    The first and the only line of each test case or query contains an integer 'N'.
    Output Format :
    For each test case, print the elements of the arra/listy separated by a single space.

    Output for every test case will be printed in a separate line.
    Constraints :
    1 <= t <= 10^2
    0 <= N <= 10^4

    Time Limit: 1sec
    Sample Input 1 :
    1
    6
    Sample Output 1 :
    1 3 5 6 4 2
    Sample Input 2 :
    2
    9
    3
    Sample Output 2 :
    1 3 5 7 9 8 6 4 2
    1 3 2
*/

#include <iostream>
using namespace std;

void swapAlternate(int *arr, int size)
{
    // Write your code here
    int currentIndex = 0, nextIndex = 1;

    if (size % 2 != 0)
    {
        size -= 1;
    }

    while (nextIndex < size)
    {
        cout << "currentIndex: " << currentIndex << " nextIndex: " << nextIndex << endl;

        if (nextIndex > size)
        {
            break;
        }

        int temp = arr[currentIndex];
        arr[currentIndex] = arr[nextIndex];
        arr[nextIndex] = temp;

        nextIndex += 2;
        currentIndex += 2;
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
    swapAlternate(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
}
