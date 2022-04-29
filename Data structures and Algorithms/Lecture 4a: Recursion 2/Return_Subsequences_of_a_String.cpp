/**
 * @file Return_Subsequences_of_a_String.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-03-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <cmath>
using namespace std;

int subsequenceOfString(string input, string output[])
{
    // Base Case
    if (input.empty())
    {
        output[0] = " ";
        return 1;
    }

    // Recursive Call
    int subsequenceSize = subsequenceOfString(input.substr(1), output);

    // Calculation Step
    for (int index = 0; index < subsequenceSize; ++index)
    {
        output[index + subsequenceSize] = input[0] + output[index];
    }

    return 2 * subsequenceSize;
}

int main()
{
    string input;
    cin >> input;

    int size = pow(2, input.size());

    string *output = new string[size];

    int outputSize = subsequenceOfString(input, output);

    for (int index = 0; index < outputSize; ++index)
    {
        cout << output[index] << endl;
    }

    cout << endl;

    return 0;
}
