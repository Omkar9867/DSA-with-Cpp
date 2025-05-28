#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// --------------------Brute Force Approach O(N)---------------

// vector<int> allDivisors(int n){
//     vector<int> divisors = {};
//     for(int i=1; i<=n; i++){
//         if(n%i == 0){
//             divisors.push_back(i);
//         }
//     }
//     return divisors;
// }

// ----------------------Optimal Approach  O(sqrt(N))--------------
vector<int> allDivisors(int n){
    vector<int> divisors = {};
    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            divisors.push_back(i);
            if(n/i != i){
                divisors.push_back(n/i);
            }
        }
    }
    return divisors;
}


int main(){
    vector<int> result = allDivisors(36);
    cout << "[";
    for(int i=0; i<result.size(); i++ ){
        cout << result[i] << ",";
    }
    cout << "]";

    return 0;
}



// Problem Statement: Given an integer N, return all divisors of N.
// A divisor of an integer N is a positive integer that divides N without leaving a remainder. In other words, if N is divisible by another integer without any remainder, then that integer is considered a divisor of N.

// Examples
//                 Example 1:
//                 Input:N = 36
               
//                 Output:[1, 2, 3, 4, 6, 9, 12, 18, 36]
                
//                 Explanation: The divisors of 36 are 1, 2, 3, 4, 6, 9, 12, 18, 36.
                                        
//                 Example 2:
//                 Input:N =12                
                
//                 Output: [1, 2, 3, 4, 6, 12]
                
//                 Explanation: The divisors of 12 are 1, 2, 3, 4, 6, 12.   


//?Optimal Approach Explanation:
// if d is a divisor of n then n/d is also a divisor of n.
//Example:  1 x 36    // Here you can see the pattern that it reverse the number after second half . I mean:
//          2 x 18    // first half is i % n but second half is n / i 
//          3 x 12    // 36/2 = 18; 36/3 = 12; 36/4 = 9 and soo on.
//          4 x 9
//          6 x 6
//          9 x 4
//          12 x 3
//          18 x 2
//          36 x 1