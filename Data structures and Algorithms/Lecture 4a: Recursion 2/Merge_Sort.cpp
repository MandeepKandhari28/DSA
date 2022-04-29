#include <iostream>
using namespace std;

void mergeTwoSortedArrays(int input[], int startIndex, int endIndex)
{

    int mid = (startIndex + endIndex) / 2;
    int index = startIndex, jIndex = mid + 1, outputIndex = 0;

    int *output = new int[endIndex - startIndex + 1];

    while (index <= mid && jIndex <= endIndex)
    {
        if (input[index] >= input[jIndex])
        {
            output[outputIndex++] = input[jIndex++];
        }
        else
        {
            output[outputIndex++] = input[index++];
        }
    }

    while (index <= mid)
    {
        output[outputIndex++] = input[index++];
    }

    while (jIndex <= endIndex)
    {
        output[outputIndex++] = input[jIndex++];
    }

    // Copy the values back to the input array
    outputIndex = 0; // Make sure that the index for the output array starts from 0 while for the input index starts from startIndex
    for (int index = startIndex; index <= endIndex; ++index)
    {
        input[index] = output[outputIndex++];
    }
}

void mergeSort(int input[], int startIndex, int endIndex)
{
    if (startIndex >= endIndex)
    {
        return;
    }

    int mid = (startIndex + endIndex) / 2;

    mergeSort(input, startIndex, mid);
    mergeSort(input, mid + 1, endIndex);

    mergeTwoSortedArrays(input, startIndex, endIndex);
}

void mergeSort(int input[], int size)
{
    // Write your code here
    mergeSort(input, 0, size - 1);
}

int main()
{
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    // mergeTwoSortedArrays(input, 0, length - 1);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
}
