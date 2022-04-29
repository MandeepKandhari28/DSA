/**
 * Print Permutations
    Given an input string (STR), print all possible permutations of the input string.
    Note:
    The input string may contain the same characters, so there will also be the same permutations.
    The order of permutations doesn’t matter.
    Input Format:
    The only input line contains a string (STR) of alphabets in lower case
    Output Format:
    Print each permutations in a new line
    Note:
    You do not need to print anything, it has already been taken care of. Just implement the function.
    Constraint:
    1<=length of STR<=8
    Time Limit: 1sec
    Sample Input 1:
    cba
    Sample Output 1:
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

void printPermutations(string input, string output)
{
    // Base case
    if (input.empty())
    {
        cout << output << endl;
        return;
    }

    for (int index = 0; index < input.length(); ++index)
    {
        printPermutations(input.substr(0, index) + input.substr(index + 1), input[index] + output);
    }
}

void printPermutations(string input)
{

    /* Don't write main() function.
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question
     */

    printPermutations(input, "");
}

int main()
{
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
