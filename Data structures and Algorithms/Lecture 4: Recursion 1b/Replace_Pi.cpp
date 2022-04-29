/**
 * Replace pi
    Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
    Constraints :
    1 <= |S| <= 50
    where |S| represents the length of string S.
    Sample Input 1 :
    xpix
    Sample Output :
    x3.14x
    Sample Input 2 :
    pipi
    Sample Output :
    3.143.14
    Sample Input 3 :
    pip
    Sample Output :
    3.14p
    Constraints:-
    1<=|S|<=50
*/

#include <iostream>
#include <cstring>
using namespace std;

void rightShiftArray(char input[])
{
    int size = strlen(input);

    for (int index = size - 1; index >= 0; --index)
    {
        input[index + 2] = input[index];
    }
}

void addCharacters(char input[])
{
    input[0] = '3';
    input[1] = '.';
    input[2] = '1';
    input[3] = '4';
}

void replacePi(char input[])
{
    // Write your code here
    // Base Case
    if (input[0] == '\0' || input[1] == '\0')
    {
        return;
    }

    // Calculation
    if (input[0] == 'p' && input[1] == 'i')
    {
        rightShiftArray(input);
        addCharacters(input);
        replacePi(input + 3);
    }
    else
    {
        replacePi(input + 1);
    }
}

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
