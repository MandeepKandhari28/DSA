/**
 * Print all Codes - String
    Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
    Note : The order of codes are not important. Just print them in different lines.
    Input format :
    A numeric string S
    Output Format :
    All possible codes in different lines
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

void printCode(string input, string output)
{
    // Base Case
    if (input.empty())
    {
        cout << output << endl;
        return;
    }

    int stringLength = input.length();

    char lastDigit = (input[stringLength - 1] - '0') + 96;

    printCode(input.substr(0, stringLength - 1), lastDigit + output);

    int digit = (input[stringLength - 2] - '0') * 10 + (input[stringLength - 1] - '0');

    if (digit >= 10 && digit <= 26)
    {
        char tensDigit = digit + 96;
        printCode(input.substr(0, stringLength - 2), tensDigit + output);
    }
}

void printAllPossibleCodes(string input)
{
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    For eg: Input: 1123
            output: aaabc, kbc, alc, aaw, kw

            In order to get the above mentioned pattern we would need to call the recursion two times:
                1. with only decreasing the input by 1 and copying that input to output
                   RC: printCode(input.substr(0, stringLength - 1), lastDigit + output);

                2. By decreasing the input by two and copy the two digits to the output
                   RC: printCode(input.substr(0, stringLength - 2), tensDigit + output);

                            1   1    2   3
                            /           \
                           /             \
                         112, C         11, w
                          / \            |
                         /   \           |
            11, bc   1, lc    1, aw     0, kw
            /   \     \          |
           /     \     \         |
       1, abc  0, kbc  0, alc  0, aaw
        |
        |
     0, aabc

    */

    printCode(input, "");
}

int main()
{
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
