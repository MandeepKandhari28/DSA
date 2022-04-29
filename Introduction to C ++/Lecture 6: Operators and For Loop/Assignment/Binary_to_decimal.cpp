/**
 * Given a binary number as an integer N, convert it into decimal and print.
    Input format :
    An integer N in the Binary Format
    Output format :
    Corresponding Decimal number (as integer)
    Constraints :
    0 <= N <= 10^9
    Sample Input 1 :
    1100
    Sample Output 1 :
    12
    Sample Input 2 :
    111
    Sample Output 2 :
    7
*/

#include<iostream>
#include<math.h>
using namespace std;

int main() {
	// Write your code here
    int number;
    cin >> number;
    
    int reverseNumber = 0;
    int power = 0;
    
    while(number > 0) {
        int unitNumber = number % 10;

        if(unitNumber == 1) {
         reverseNumber += pow(2, power);
        }

        power++;
        number/=10;
    }
    
    cout << reverseNumber;
    
    return 0;
	
}
