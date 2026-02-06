#include <bits/stdc++.h>

// double calculatePw(double x, double temp){
//     if(temp <= 1) return x;
//     if(temp % 2 == 0){
//         return calculatePw(x*x, temp /2);
//     }
//     return x *calculatePw(x*x, temp /2);
// }

// double myPow(double x, int n) {
//     long long balanceFrom = n;
//     if(n < 0){
//         x = 1/x;
//         balanceFrom = -balanceFrom;
//     }
//     return calculatePw(x, balanceFrom);
// }

//!This will still give error so binary exponential is required
double myPow(double x, int n) {
    long binaryForm = n;
    if(n<0){
        x = 1/x;
        binaryForm = -binaryForm;
    }
    double ans = 1;
    while(binaryForm > 0){
        if(binaryForm % 2 == 1){
            ans *= x;
        }
        x*= x;
        binaryForm /= 2;
    }
    return ans;
}


int main(){
    
    std::cout << "Pow  = " << myPow(2.00000, -2) << std::endl;

    return 0;
}


// 50. Pow(x, n)

// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Example 1:
// Input: x = 2.00000, n = 10
// Output: 1024.00000

// Example 2:
// Input: x = 2.10000, n = 3
// Output: 9.26100

// Example 3:
// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 
// Constraints:
// -100.0 < x < 100.0
//! -231 <= n <= 231-1
// n is an integer.
// Either x is not zero or n > 0.
//! -10^4 <= xn <= 10^4