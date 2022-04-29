/**
 * Write a program to count and print the total number of characters (lowercase english alphabets only), digits (0 to 9) and white spaces (single space, tab i.e. '\t' and newline i.e. '\n') entered till '$'.
    That is, input will be a stream of characters and you need to consider all the characters which are entered till '$'.
    Print count of characters, count of digits and count of white spaces respectively (separated by space).
    Input Format :
    A stream of characters terminated by '$'
    Output Format :
    3 integers i.e. count_of_characters count_of_digits count_of_whitespaces (separated by space)
    Sample Input :
    abc def4 5$
    Sample Output :
    6 2 2
    Sample Output Explanation :
    Number of characters : 6 (a, b, c, d, e, f)
    Number of digits : 2 (4, 5)
    Number of white spaces : 2 (one space after abc and one newline after 4)
*/

/* Could use the actual characters like a, 0, \t instead os using the ascii value*/

#include<iostream>
using namespace std;

int main(){

    /* Read input as specified in the question.
	 * Print output as specified in the question.
	 */
    int count_of_characters = 0;
    int count_of_digits = 0;
    int count_of_whitespaces = 0;
    
    char inputChar;
    inputChar = cin.get();
    
    while(inputChar != '$') {
        if(inputChar  >= 97 && inputChar <= 122) {
            count_of_characters++;
        } else if(inputChar >= 48 && inputChar <= 57) {
            count_of_digits++;
        } else if(inputChar == 32 || inputChar == 9 || inputChar == 10) {
            count_of_whitespaces++;
        }
        
        inputChar = cin.get();
    }
    
    cout << count_of_characters << " " << count_of_digits << " " << count_of_whitespaces;
  
}
