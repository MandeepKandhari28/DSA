/**
 * Remove Consecutive Duplicates
    For a given string(str), remove all the consecutive duplicate characters.
    Example:
    Input String: "aaaa"
    Expected Output: "a"

    Input String: "aabbbcc"
    Expected Output: "abc"
    Input Format:
    The first and only line of input contains a string without any leading and trailing spaces. All the characters in the string would be in lower case.
    Output Format:
    The only line of output prints the updated string.
    Note:
    You are not required to print anything. It has already been taken care of.
    Constraints:
    0 <= N <= 10^6
    Where N is the length of the input string.

    Time Limit: 1 second
    Sample Input 1:
    aabccbaa
    Sample Output 1:
    abcba
    Sample Input 2:
    xxyyzxx
    Sample Output 2:
    xyzx
*/

#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char input[])
{
    // Write your code here
    int nextChar = 0;
    int size = strlen(input);
    int index = 0;
    for (; index < size - 1; ++index)
    {
        if (input[index] != input[index + 1])
        {
            input[++nextChar] = input[index + 1];
        }
    }

    input[++nextChar] = '\0';
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}