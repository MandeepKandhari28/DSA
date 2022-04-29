/**
 * Print Keypad Combinations Code
    Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
    Note : The order of strings are not important. Just print different strings in new lines.
    Input Format :
    Integer n
    Output Format :
    All possible strings in different lines
    Constraints :
    1 <= n <= 10^6
    Sample Input:
    23
    Sample Output:
    ad
    ae
    af
    bd
    be
    bf
    cd
    ce
    cf
*/

#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

string keypadLettersArray[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printKeypad(int num, string output)
{
    // Base Case
    if (num == 0 || num == 1)
    {
        cout << output << endl;
    }

    string keypadLetters = keypadLettersArray[num % 10];
    int letterSize = keypadLetters.size();

    for (int index = 0; index < letterSize; ++index)
    {
        printKeypad(num / 10, keypadLetters[index] + output);
    }
}

void printKeypad(int num)
{
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    printKeypad(num, "");
}

int main()
{
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
