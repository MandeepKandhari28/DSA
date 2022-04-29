/**
 * Fibonacci Number
    Given a number N, figure out if it is a member of fibonacci series or not. Return true if the number is member of fibonacci series else false.
    Fibonacci Series is defined by the recurrence
        F(n) = F(n-1) + F(n-2)
    where F(0) = 0 and F(1) = 1


    Input Format :
    Integer N
    Output Format :
    true or false
    Constraints :
    0 <= n <= 10^4
    Sample Input 1 :
    5
    Sample Output 1 :
    true
    Sample Input 2 :
    14
    Sample Output 2 :
    false
*/

#include <iostream>
using namespace std;

bool checkMember(int n)
{
    if (n == 0)
    {
        return true;
    }

    int previousNumber = 1, currentNumber = 1;

    while (currentNumber <= n)
    {
        if (currentNumber == n)
        {
            return true;
        }

        int temp = 0;
        temp = currentNumber;
        currentNumber += previousNumber;
        previousNumber = temp;
    }

    return false;
}

int main()
{

    int number;
    cin >> number;
    if (checkMember(number))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
