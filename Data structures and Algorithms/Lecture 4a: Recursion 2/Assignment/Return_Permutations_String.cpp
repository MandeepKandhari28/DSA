/**
 * Return Permutations - String
    Given a string S, find and return all the possible permutations of the input string.
    Note 1 : The order of permutations is not important.
    Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
    Input Format :
    String S
    Output Format :
    All permutations (in different lines)
    Sample Input :
    abc
    Sample Output :
    abc
    acb
    bac
    bca
    cab
    cba
*/

#include <iostream>
#include <string>
using namespace std;

void stringPermutation(string input, string outputArray[], int &outputSize, string output)
{
    // Base Case
    if (input.size() == 1)
    {
        output = output + input[0];
        outputArray[outputSize++] = output;
        return;
    }

    for (int index = 0; index < input.length(); ++index)
    {
        string inputString = input.substr(0, index) + input.substr(index + 1);
        stringPermutation(inputString, outputArray, outputSize, output + input[index]);
    }
}

int returnPermutations(string input, string output[])
{
    /* Don't write main() function.
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question
     */

    int outputSize = 0;

    stringPermutation(input, output, outputSize, "");

    return outputSize;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
