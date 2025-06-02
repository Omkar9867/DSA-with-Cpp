#include <iostream>
using namespace std;

// ----------------------------------- Approach O(logv10N)---------------------------

int countDigit(int n){
    int counter = 0;
    while(n > 0){
        counter++;
        //Remove the last digit by dividing by 10
        n = n/10;
    }
    return counter;
}


int main(){
    int result = countDigit(123456);
    cout << "Number of digits: " << result << endl;

    return 0;
}

// Count all Digits of a Number

// Hint
// You are given an integer n. You need to return the number of digits in the number.
// The number will have no leading zeroes, except when the number is 0 itself.

// Examples:
// Input: n = 4
// Output: 1
// Explanation: There is only 1 digit in 4.

// Input: n = 14
// Output: 2
// Explanation: There are 2 digits in 14.

//!Always remember: %10 gives last digit number, whereas /10 removes the last digit of number