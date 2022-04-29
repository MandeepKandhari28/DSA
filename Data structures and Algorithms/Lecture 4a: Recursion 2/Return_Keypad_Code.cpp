/**
 * Return Keypad Code
    Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
    Return empty string for numbers 0 and 1.
    Note : 1. The order of strings are not important.
    2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
    Input Format :
    Integer n
    Output Format :
    All possible strings in different lines
    Constraints :
    1 <= n <= 10^6
    Sample Input:
    23
    Sample Output:
    ad
    ae
    af
    bd
    be
    bf
    cd
    ce
    cf
*/

#include <iostream>
#include <string>
using namespace std;

string keypadArray[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int keypad(int num, string output[])
{
    // Base Case
    if (num == 0 || num == 1)
    {
        output[0] = " ";
        return 1;
    }

    // Recursive Call
    int outputSize = keypad(num / 10, output);

    // Calculation Step
    string keypadLetters = keypadArray[num % 10];
    int letterSize = keypadLetters.size();

    for (int index = 0; index < (letterSize - 1) * outputSize; ++index)
    {
        output[index + outputSize] = output[index];
    }

    int j = 0, sizeCheck = 0;
    for (int index = 0; index < letterSize * outputSize; ++index)
    {
        output[index] = output[index] + keypadLetters[j];
        sizeCheck++;
        if (sizeCheck == outputSize)
        {
            sizeCheck = 0;
        }

        if (sizeCheck == 0)
        {
            j++;
        }
    }

    return letterSize * outputSize;
}

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}

/* Alternate approach:

    Time Complexity: O(n * n)

 int keypad(int num, string output[])
{
    Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.


// Base Case
if (num == 0 || num == 1)
{
    return 1;
}

// Recursive Call
int numCount = keypad(num / 10, output);

string numLetters = keypadLettersArray[num % 10];
int size = numLetters.size();

for (int index = 1; index < size; index++)
{
    for (int j = 0; j < numCount; j++)
    {
        output[numCount * index + j] = output[j];
    }
}

for (int index = 0; index < size; index++)
{
    for (int j = 0; j < numCount; j++)
    {
        output[numCount * index + j] = output[numCount * index + j] + numLetters[index];
    }
}

return size * numCount;
}
*/
