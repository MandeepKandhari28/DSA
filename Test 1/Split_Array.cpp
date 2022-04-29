/**
 * Split Array
    Given an integer array A of size N, check if the input array can be splitted in two parts such that -
    - Sum of both parts is equal
    - All elements in the input, which are divisible by 5 should be in same group.
    - All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
    - Elements which are neither divisible by 5 nor by 3, can be put in any group.
    Groups can be made with any set of elements, i.e. elements need not to be continuous. And you need to consider each and every element of input array in some group.
    Return true, if array can be split according to the above rules, else return false.
    Note : You will get marks only if all the test cases are passed.
    Input Format :
    Line 1 : Integer N (size of array)
    Line 2 : Array A elements (separated by space)
    Output Format :
    true or false
    Constraints :
    1 <= N <= 50
    Sample Input 1 :
    2
    1 2
    Sample Output 1 :
    false
    Sample Input 2 :
    3
    1 4 3
    Sample Output 2 :
    true
*/

#include <iostream>
using namespace std;

bool splitArray(int *input, int size)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int totalSum = 0;
    for (int index = 0; index < size; ++index)
    {
        totalSum += input[index];
    }

    if (totalSum % 2 != 0)
    {
        return false;
    }

    int sum_in_array = totalSum / 2;

    int sum1 = sum_in_array, sum2 = sum_in_array;

    for (int index = 0; index < size; ++index)
    {
        if (input[index] % 5 == 0)
        {
            // output1[index1++] = input[index];
            sum1 -= input[index];
        }
        else if (input[index] % 3 == 0)
        {
            // output2[index2++] = input[index];
            sum2 -= input[index];
        }
        else
        {
            if (sum1 >= input[index])
            {
                sum1 -= input[index];
            }
            else
            {
                sum2 -= input[index];
            }
        }
    }

    cout << "sum1: " << sum1 << " sum2: " << sum2 << endl;

    return sum1 == 0 && sum2 == 0;
}

int main()
{

    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    if (splitArray(input, size))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
