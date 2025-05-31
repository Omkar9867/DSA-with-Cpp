#include <iostream>
using namespace std;

// ---------------------------------BruteForce Approach O(N)---------------------

// int GDP(int n1,int n2){
//     int gdc = 1;
//     for(int i = 1; i <= min(n1, n2); i++ ){
//         if(n1%i == 0 && n2%i == 0){
//             gdc = i;
//         }
//     }
//     return gdc;
// }

// ---------------------------------Better Approach O(N)---------------
// Count reverse so you could get the bigger number beforehand
// int GDP(int n1,int n2){
//     for(int i = min(n1, n2); i>0; i--){
//         if(n1%i == 0 && n2%i == 0){
//             return i;
//         }
//     }
//     return 1;
// }

// ---The Euclidean Algorithm
// --------------------------------Optimal Approach O(logn)--------------
int GDP(int n1,int n2){
    while(n1 > 0 && n2 > 0){
        if(n1 > n2){
            n1 = (n1%n2);// Can be also written as n1 = (n1-n2); but logically a%b 
        }else{
            n2 = (n2%n1);
        }
    }
    if(n1 == 0){
        return n2;
    }else{
        return n1;
    }
}



int main(){
    int result = GDP(20, 15);
    cout << "Result: " << result << endl;
    return 0;
}


// GCD of Two Numbers
// Hint
// You are given two integers n1 and n2. You need find the Greatest Common Divisor (GCD) of the two given numbers. Return the GCD of the two numbers.

// The Greatest Common Divisor (GCD) of two integers is the largest positive integer that divides both of the integers.

// Examples:
// Input: n1 = 4, n2 = 6
// Output: 2
// Explanation: Divisors of n1 = 1, 2, 4, Divisors of n2 = 1, 2, 3, 6
// Greatest Common divisor = 2.

// Input: n1 = 9, n2 = 8
// Output: 1
// Explanation: Divisors of n1 = 1, 3, 9 Divisors of n2 = 1, 2, 4, 8.
// Greatest Common divisor = 1.


//?Optimal Solution Explanation
// The Euclidean Algorithm is a method for finding the greatest common divisor of two numbers. 
// It operates on the principle that the GCD of two numbers remains the same even if the smaller number is subtracted from the larger number.

// To find the GCD of n1 and n2 where n1 > n2:
//!Formula : gdc(a, b) = gcd((a-b), b) where a > b

// Repeatedly subtract the smaller number from the larger number until one of them becomes 0.
// Once one of them becomes 0, the other number is the GCD of the original numbers.
// Eg, n1 = 20, n2 = 15:

// gcd(20, 15) = gcd(20-15, 15) = gcd(5, 15)  // Also similar as a%b i.e. subracting 'a' (b times) So formula: gdc(a%b, b)

// gcd(5, 15) = gcd(15-5, 5) = gcd(10, 5)

// gcd(10, 5) = gcd(10-5, 5) = gcd(5, 5)

// gcd(5, 5) = gcd(5-5, 5) = gcd(0, 5)

// Hence, return 5 as the gcd.

