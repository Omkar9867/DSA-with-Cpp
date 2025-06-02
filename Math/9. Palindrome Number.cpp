#include <iostream>
using namespace std;

// ------------------------------Approach -----------

bool isPalindrome(int n){
    int dummyInt = n;
    int revInt = 0;
    while(n > 0){
        revInt = (revInt*10) + n%10;
        n = n / 10;
    }
    if(revInt == dummyInt){
        return true;
    }else{
        return false;
    }
}

int main(){
    bool result = isPalindrome(121);
    cout << "Palindrome is: " << result <<  endl;
    return 0;
}

// 9. Palindrome Number
// Hint
// You are given an integer n. You need to check whether the number is a palindrome number or not. Return true if it's a palindrome number, otherwise return false.

// A palindrome number is a number which reads the same both left to right and right to left.

// Examples:
// Input: n = 121
// Output: true
// Explanation: When read from left to right : 121.
// When read from right to left : 121.

// Input: n = 123
// Output: false
// Explanation: When read from left to right : 123.
// When read from right to left : 321.