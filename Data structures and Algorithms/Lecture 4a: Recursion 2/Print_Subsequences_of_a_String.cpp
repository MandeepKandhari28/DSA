/**
 * Print_Subsequences_of_a_String.cpp
 */

#include <iostream>
using namespace std;

void subsequence(string input, string output)
{
    // Base Case
    if (input.empty())
    {
        cout << output << endl;
        return;
    }

    // Recursive call
    subsequence(input.substr(1), output);
    subsequence(input.substr(1), output + input[0]);
}

int main()
{

    string input;
    cin >> input;

    string output = "";

    subsequence(input, output);

    return 0;
}
