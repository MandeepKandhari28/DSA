/**
 * Array Sum
    Given an array of length N, you need to find and print the sum of all elements of the array.
    Input Format :
    Line 1 : An Integer N i.e. size of array
    Line 2 : N integers which are elements of the array, separated by spaces
    Output Format :
    Sum
    Constraints :
    1 <= N <= 10^6
    Sample Input :
    3
    9 8 9
    Sample Output :
    26
*/

#include <iostream>
using namespace std;

int main()
{
    /* Read input as specified in the question.
     * Print output as specified in the question.
     */

    int size_of_Array;
    cin >> size_of_Array;

    int inputArray[1000000], sum = 0;

    for (int index = 0; index < size_of_Array; ++index)
    {
        cin >> inputArray[index];
        sum += inputArray[index];
    };

    cout << sum << endl;
}

/**
 * #include<iostream>
using namespace std;

int main(){

    int size_of_Array;
    cin >> size_of_Array;

    int inputElement, sum = 0;

    for(int index = 0; index < size_of_Array; ++index) {
        cin >> inputElement;
        sum+=inputElement;
    };

    cout << sum << endl;

}

*/