#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isArmstrong(int n){
    int k = to_string(n).length();
    int num = n;
    int sum = 0;
    while(n > 0){
        int lastDig = n%10;
        sum += pow(lastDig, k);
        n /= 10;
    }
    if(sum == num){
        cout << "Sum :" << sum << endl;
        return true;
    }else{
        cout << "Sum :" << sum << endl;
        return false;
    }
}

int main(){
    bool result = isArmstrong(153);
    cout << "Result: " << result << endl;
    return 0;
}

// 1134. Armstrong Number
// Check if the Number is Armstrong
// Hint
// You are given an integer n. You need to check whether it is an armstrong number or not. Return true if it is an armstrong number, otherwise return false.

// An armstrong number is a number which is equal to the sum of the digits of the number, raised to the power of the number of digits.

// Examples:
// Input: n = 153
// Output: true
// Explanation: Number of digits : 3.
// 1 ^ 3 + 5 ^ 3 + 3 ^ 3 = 1 + 125 + 27 = 153.
// Therefore, it is an Armstrong number.

// Input: n = 12
// Output: false
// Explanation: Number of digits : 2.
// 1 ^ 2 + 2 ^ 2 = 1 + 4 = 5.
// Therefore, it is not an Armstrong number.