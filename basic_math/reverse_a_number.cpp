#include <iostream>
using namespace std;

// ----------------------Approach O(logv10N) -------------------------

int reverseNumber(int n){
    int result = 0;
    while(n > 0){
        // int lastDig = n%10;
        result = (result*10) + n%10;
        n = n/10;
    }
    return result;
}

int main(){
    int result = reverseNumber(1234567);
    cout << "Result: " << result << endl;
    return 0;
}

// Reverse a number
// Hint
// You are given an integer n. Return the integer formed by placing the digits of n in reverse order.

// Examples:
// Input: n = 25
// Output: 52
// Explanation: Reverse of 25 is 52.

// Input: n = 123
// Output: 321
// Explanation: Reverse of 123 is 321.