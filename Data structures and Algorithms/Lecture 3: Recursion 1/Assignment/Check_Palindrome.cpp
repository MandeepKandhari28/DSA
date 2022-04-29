/**
 * Check Palindrome
    Check whether a given String S is a palindrome using recursion. Return true or false.
    Input Format :
    String S
    Output Format :
    'true' or 'false'
    Constraints :
    0 <= |S| <= 1000
    where |S| represents length of string S.
    Sample Input 1 :
    racecar
    Sample Output 1:
    true
    Sample Input 2 :
    ninja
    Sample Output 2:
    false
*/

#include <iostream>
using namespace std;

int length(char input[])
{
    int length = 0;

    while (input[length] != '\0')
    {
        length++;
    }

    return length;
}

bool checkPalindrome(char input[], int startIndex, int endIndex)
{
    // Base Case
    /**
      A string of length 0 or 1 is
      a palindrome. No question about it. So, how do know that we are dealing with a 0 or 1
      size string? It’s easy. The start index must be equal to the end index (for string size 1) or
      it must be greater than the end index (for string size 0). So our base case could be:

      if(start >= end):
      return true
     */

    if (startIndex >= endIndex)
    {
        return true;
    }

    // calculation Step
    if (input[startIndex] == input[endIndex])
    {
        return checkPalindrome(input, startIndex + 1, endIndex - 1);
    }
    else
    {
        return false;
    }
}

bool checkPalindrome(char input[])
{
    // Write your code here
    int endIndex = length(input) - 1;
    return checkPalindrome(input, 0, endIndex);
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
