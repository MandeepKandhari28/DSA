/**
 * Pair Star
    Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
    Input format :
    String S
    Output format :
    Modified string
    Constraints :
    0 <= |S| <= 1000
    where |S| represents length of string S.
    Sample Input 1 :
    hello
    Sample Output 1:
    hel*lo
    Sample Input 2 :
    aaaa
    Sample Output 2 :
    a*a*a*a
*/

#include <iostream>
#include <cstring>
using namespace std;

void insertStarBetweenChars(char input[])
{
    int size = strlen(input);
    int index = size;
    for (; index >= 1; --index)
    {
        input[index + 1] = input[index];
    }

    input[1] = '*';
}

void pairStar(char input[])
{
    // Write your code here
    // Base Case
    if (input[0] == '\0' || input[1] == '\0')
    {
        return;
    }

    // Calculation Step
    if (input[0] == input[1])
    {
        insertStarBetweenChars(input);
        pairStar(input + 2);
    }
    else
    {
        pairStar(input + 1);
    }
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
}
