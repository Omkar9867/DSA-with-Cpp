#include <iostream>
#include <cmath>
using namespace std;

// ----------------------------------- Approach

// bool isPrime(int n){
//     int k = sqrt(n);
//     for (int i = 2; i <= k; i++){
//         if(n % i == 0){
//             return false;
//         }
//     }
//     return true;
// }

// -------------------------------Optimal

bool isPrime(int n){
    if (n <= 1) return false; // Edge case for numbers <= 1
    if (n == 2) return true; // 2 is prime
    if (n % 2 == 0) return false; //?Important:  Any other even number is not prime
    int k = sqrt(n);
    for (int i = 3; i <= k; i+2){ // The reasom we check %2 so we can increment +2 after 3 to iterate only odd numbers
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    bool result = isPrime(8);
    cout << "Result : " << result << endl;

    return 0;
}

// Check for Prime Number
// Hint
// You are given an integer n. You need to check if the number is prime or not. Return true if it is a prime number, otherwise return false.

// A prime number is a number which has no divisors except 1 and itself.

// Examples:

// Input: n = 5
// Output: true
// Explanation: The only divisors of 5 are 1 and 5 , So the number 5 is prime.

// Input: n = 8
// Output: false
// Explanation: The divisors of 8 are 1, 2, 4, 8, thus it is not a prime number.