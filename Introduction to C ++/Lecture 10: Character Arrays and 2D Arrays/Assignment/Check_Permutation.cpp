/**
 * Check Permutation
    For a given two strings, 'str1' and 'str2', check whether they are a permutation of each other or not.
    Permutations of each other
    Two strings are said to be a permutation of each other when either of the string's characters can be rearranged so that it becomes identical to the other one.

    Example:
    str1= "sinrtg"
    str2 = "string"

    The character of the first string(str1) can be rearranged to form str2 and hence we can say that the given strings are a permutation of each other.
    Input Format:
    The first line of input contains a string without any leading and trailing spaces, representing the first string 'str1'.

    The second line of input contains a string without any leading and trailing spaces, representing the second string 'str2'.
    Note:
    All the characters in the input strings would be in lower case.
    Output Format:
    The only line of output prints either 'true' or 'false', denoting whether the two strings are a permutation of each other or not.

    You are not required to print anything. It has already been taken care of. Just implement the function.
    Constraints:
    0 <= N <= 10^6
    Where N is the length of the input string.

    Time Limit: 1 second
    Sample Input 1:
    abcde
    baedc
    Sample Output 1:
    true
    Sample Input 2:
    abc
    cbd
    Sample Output 2:
    false
*/

/**
 * We first need to initialize a frequency array of type int and size 256 bytes with 0;
 * 1. Then iterate over the string1 and increment the index value corresponding to character's ASCII value.
 * 2. Iterate over string2 and decrement the indexes corresponding to the character's ASCII value.
 * 3. Then iterate over the frequeny array and check if each index has a  value 0 or not.
 *      a. If each of the index value is 0 then it shows that the string 1 and string 2 are permutation of each other.
 *      b. Else it means that both the strings are not permutation of each other.
 */

#include <iostream>
#include <cstring>
using namespace std;

bool isPermutation(char input1[], char input2[])
{
    // Write your code here
    int len1 = strlen(input1);
    int len2 = strlen(input2);

    if (len1 != len2)
    {
        return false;
    }

    // Initialize a 256 byte int array with 0 values
    int freqArray[256] = {0};

    for (int index = 0; index < len1; ++index)
    {
        freqArray[input1[index]]++;
    }

    for (int index = 0; index < len2; ++index)
    {
        freqArray[input2[index]]--;
    }

    for (int index = 0; index < 255; ++index)
    {
        if (freqArray[index] != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}
