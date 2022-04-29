/* Selection Sort*/

#include <iostream>
using namespace std;

void selectionSort(int *input, int size)
{

    /* We will only need to perform N - 2 iterations in total as the last element
       will automatically be placed at its right position. Secondly, the minimum
       loop runs from index + 1 positions
    */
    for (int index = 0; index < size - 1; ++index)
    {
        int min = input[index], minIndex = index;

        cout << "min1: " << min << " minIndex: " << minIndex << endl;

        // Find the minimum element in the array starting from the next element to the last element.
        for (int j = index + 1; j < size; ++j)
        {
            cout << "min2: " << min << " minIndex: " << minIndex << endl;
            if (min > input[j])
            {
                min = input[j];
                minIndex = j;
            }
        }

        // Swap the current Index number with the minimum number
        int temp = input[index];
        input[index] = min;
        input[minIndex] = temp;

        cout << "input[index]: " << input[index] << " input[minIndex]: " << input[minIndex] << endl;
    }
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int index = 0; index < size; ++index)
    {
        cin >> input[index];
    }

    selectionSort(input, size);

    for (int index = 0; index < size; ++index)
    {
        cout << input[index] << " ";
    }

    cout << endl;

    delete[] input;

    return 0;
}