/**
 * Remove X
    Given a string, compute recursively a new string where all 'x' chars have been removed.
    Input format :
    String S
    Output format :
    Modified String
    Constraints :
    1 <= |S| <= 10^3
    where |S| represents the length of string S.
    Sample Input 1 :
    xaxb
    Sample Output 1:
    ab
    Sample Input 2 :
    abc
    Sample Output 2:
    abc
    Sample Input 3 :
    xx
    Sample Output 3:
*/

#include <iostream>
#include <cstring>
using namespace std;

void removeX(char input[])
{
    // Write your code here
    // Base Case
    if (input[0] == '\0')
    {
        return;
    }

    // Recursive Call
    removeX(input + 1);

    // Calculation
    int size = strlen(input);
    cout << "input length: " << size << " input[0]: " << input[0] << endl;
    if (input[0] == 'x')
    {
        for (int index = 1; index < size; ++index)
        {
            input[index - 1] = input[index];
        }
        input[size - 1] = '\0';
    }
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
