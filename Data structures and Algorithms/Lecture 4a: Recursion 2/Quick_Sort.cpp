/**
 * Quick Sort
    Sort an array A using Quick Sort.
    Change in the input array itself. So no need to return or print anything.


    Input format :
    Line 1 : Integer n i.e. Array size
    Line 2 : Array elements (separated by space)
    Output format :
    Array elements in increasing order (separated by space)
    Constraints :
    1 <= n <= 10^3
    Sample Input 1 :
    6
    2 6 8 5 4 3
    Sample Output 1 :
    2 3 4 5 6 8
    Sample Input 2 :
    5
    1 5 2 7 3
    Sample Output 2 :
    1 2 3 5 7
*/

#include <iostream>
using namespace std;

int partition(int arr[], int startIndex, int endIndex)
{
    // First Take the element present at the starting Index as the pivot
    int pivot = arr[startIndex];

    // Then count the elements in the array that are smaller than the pivot
    // This will tell you the correct position/ index at which the pivot element should be placed.

    int index = startIndex + 1, indexCount = 0;
    while (index <= endIndex)
    {
        if (arr[index] <= pivot)
        {
            indexCount++;
        }
        index++;
    }

    int pivotIndex = startIndex + indexCount;

    // Now swap the element present at the pivot index with the starting Index
    // so that the pivot position can be placed at the right position

    arr[startIndex] = arr[pivotIndex];

    arr[pivotIndex] = pivot;

    // Now the pivot element has been placed at the right position, the next step
    // is to make sure that all the elements that are smaller than the pivot element
    // are placed at the left side of the pivot element and all the elements greater than
    // the pivot element are placed at the right side of the pivot element.

    while (startIndex < endIndex)
    {
        if (arr[startIndex] <= arr[pivotIndex])
        {
            startIndex++;
        }
        else if (arr[endIndex] > arr[pivotIndex])
        {
            endIndex--;
        }
        else
        {
            int temp = arr[startIndex];
            arr[startIndex] = arr[endIndex];
            arr[endIndex] = temp;

            startIndex++;
            endIndex--;
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int startIndex, int endIndex)
{
    // Base case
    if (startIndex >= endIndex)
    {
        return;
    }

    // calculation Step
    int partitionIndex = partition(arr, startIndex, endIndex);

    // recursive Call to partition the left half and the right half
    // After placing the element present at the starting index to its
    // correct in the array.
    quickSort(arr, startIndex, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, endIndex);
}

void quickSort(int input[], int size)
{
    /* Don't write main().
       Don't read input, it is passed as function argument.
       Change in the given array itself.
       Taking input and printing output is handled automatically.
    */

    quickSort(input, 0, size - 1);
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}
