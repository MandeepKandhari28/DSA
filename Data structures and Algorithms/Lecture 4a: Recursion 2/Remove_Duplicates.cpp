/**
 * Remove Duplicates
 *
 */

#include <iostream>
using namespace std;

void leftShiftArrayByOne(char *input)
{
    int index = 1;
    for (; input[index] != '\0'; ++index)
    {
        input[index - 1] = input[index];
    }

    input[index - 1] = '\0';
}

void removeConsecutiveDuplicates(char *input)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Change in the given string itself.
     * No need to return or print anything
     * Taking input and printing output is handled automatically.
     */

    // Base Case
    if (input[0] == '\0' || input[1] == '\0')
    {
        return;
    }

    // calculation + Recursive call
    if (input[0] == input[1])
    {
        leftShiftArrayByOne(input);
        removeConsecutiveDuplicates(input);
    }
    else
    {
        removeConsecutiveDuplicates(input + 1);
    }
}

int main()
{
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}