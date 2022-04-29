/**
 * Given an integer N, print all the prime numbers that lie in the range 2 to N (both inclusive).
    Print the prime numbers in different lines.
    Input Format :
    Integer N
    Output Format :
    Prime numbers in different lines
    Constraints :
    1 <= N <= 100
    Sample Input 1:
    9
    Sample Output 1:
    2
    3
    5
    7
    Sample Input 2:
    20
    Sample Output 2:
    2
    3
    5
    7
    11
    13
    17
    19
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){

    /* Read input as specified in the question.
	 * Print output as specified in the question.
	 */
    
    int number;
    cin >> number;
    
    int i = 2;
    while (i <= number) {
        int j = 2;
        bool isPrime = true;
        while(j <= round(i / 2.0)) {
            if(i % j == 0) {
                j++;
                isPrime = false;
                break;
            }

            j++;
        }
        
        if(isPrime) {
            cout << i << endl;
        }

        i++;
    }
  
}
