/**
 * Return all codes - String
    Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
    Note : The order of codes are not important. And input string does not contain 0s.
    Input format :
    A numeric string
    Constraints :
    1 <= Length of String S <= 10
    Sample Input:
    1123
    Sample Output:
    aabc
    kbc
    alc
    aaw
    kw
*/

#include <iostream>
#include <string.h>
using namespace std;

void getCodes(string input, string outputArray[], int &size, string output)
{
    // Base Case
    if (input.empty())
    {
        outputArray[size] = output;
        size++;
        return;
    }

    int stringLength = input.length();
    // Recursive Call
    char letter = input[stringLength - 1] + 48;
    getCodes(input.substr(0, stringLength - 1), outputArray, size, letter + output);

    int digit = (input[stringLength - 2] - 48) * 10 + (input[stringLength - 1] - 48);
    if (digit >= 10 && digit <= 26)
    {
        char letterDigit = digit + 96;
        getCodes(input.substr(0, stringLength - 2), outputArray, size, letterDigit + output);
    }
}

int getCodes(string input, string output[10000])
{
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    int size = 0;
    getCodes(input, output, size, "");
    return size;
}

int main()
{
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
