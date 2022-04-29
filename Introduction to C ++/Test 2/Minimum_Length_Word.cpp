/**
 * Minimum Length Word
    Given a string S (that can contain multiple words), you need to find the word which has minimum length.
    Note : If multiple words are of same length, then answer will be first minimum length word in the string.
    Words are seperated by single space only.
    Input Format :
    String S
    Output Format :
    Minimum length word
    Constraints :
    1 <= Length of String S <= 10^5
    Sample Input 1 :
    this is test string
    Sample Output 1 :
    is
    Sample Input 2 :
    abc de ghihjk a uvw h j
    Sample Output 2 :
    a
*/

#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

void minLengthWord(char input[], char output[])
{

    // Write your code here
    int minWordLength = INT_MAX, count = 0;
    int size = strlen(input);
    int startIndex = 0;

    for (int index = 0; index < size; ++index)
    {
        if (input[index] != ' ')
        {
            count++;
            continue;
        }

        if (input[index] == ' ')
        {
            if (minWordLength > count)
            {
                startIndex = index - count;
                minWordLength = count;
            }
        }
        count = 0;
    }

    if (count < minWordLength)
    {
        minWordLength = count;
        startIndex = size - count;
    }

    for (int index = 0; index < minWordLength; ++index)
    {
        output[index] = input[startIndex++];
    }
}

int main()
{
    char ch[10000], output[10000];
    cin.getline(ch, 10000);
    minLengthWord(ch, output);
    cout << output << endl;
}
