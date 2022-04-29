/**
 * Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.
    Input format :
    Integer x
    Output format :
    Terms of series (separated by space)
    Constraints :
    1 <= x <= 1,000
    Sample Input 1 :
    10
    Sample Output 1 :
    5 11 14 17 23 26 29 35 38 41
    Sample Input 2 :
    4
    Sample Output 2 :
    5 11 14 17
*/

#include<iostream>
using namespace std;

int main() {
	// Write your code here
    int x;
    cin >> x;
    
    int index = 1;
    while(x > 0) {
        
        int expression = (3 * index) + 2;

        if(expression % 4 == 0) {
            index++;
            continue;
        }
        
        cout << expression << " ";
        
        x--;
        index++;
    }
    
    
    return 0;
	
}
