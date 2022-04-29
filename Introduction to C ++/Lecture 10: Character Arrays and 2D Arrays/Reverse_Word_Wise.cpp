/**
 * Reverse Word Wise
    Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
    Input format :
    String in a single line
    Output format :
    Word wise reversed string in a single line
    Constraints :
    0 <= |S| <= 10^7
    where |S| represents the length of string, S.
    Sample Input 1:
    Welcome to Coding Ninjas
    Sample Output 1:
    Ninjas Coding to Welcome
    Sample Input 2:
    Always indent your code
    Sample Output 2:
    code your indent Always
*/

#include <iostream>
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

void reverse(char input[], int startIndex, int endIndex)
{

    int temp = 0;

    while (startIndex < endIndex)
    {
        temp = input[startIndex];
        input[startIndex] = input[endIndex];
        input[endIndex] = temp;

        startIndex++;
        endIndex--;
    }
};

void reverseStringWordWise(char input[])
{
    // Write your code here
    int size = length(input);

    reverse(input, 0, size - 1);

    int startIndex = 0;
    for (int index = 0; input[index] != '\0'; ++index)
    {
        if (input[index] == ' ')
        {
            reverse(input, startIndex, index - 1);
            startIndex = index + 1;
            continue;
        };

        if (input[index + 1] == '\0')
        {
            reverse(input, startIndex, index);
        }
    }
}

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
