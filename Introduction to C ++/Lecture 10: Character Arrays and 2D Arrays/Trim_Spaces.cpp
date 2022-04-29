/*
*  Trim Spaces
    Given an input string S that contains multiple words, you need to remove all the spaces present in the input string.
    There can be multiple spaces present after any word.
    Input Format :
    String S
    Output Format :
    Updated string
    Constraints :
    1 <= Length of string S <= 10^6
    Sample Input :
    abc def g hi
    Sample Output :
    abcdefghi
*/
#include <iostream>
#include <cstring>
using namespace std;

int length(char input[])
{
    int length = 0;

    for (int index = 0; input[index] != '\0'; ++index)
    {
        length++;
    }

    return length;
}

void trimSpaces(char input[])
{
    // Write your code here
    int size = length(input);

    int spaceIndex = 0;
    for (int index = 0; index < size; ++index)
    {
        if (input[index] != ' ')
        {
            input[spaceIndex++] = input[index];
        }
    }

    input[spaceIndex] = '\0';
}

int main()
{
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}