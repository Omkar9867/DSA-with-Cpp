#include <iostream>
using namespace std;

// --------------------------- Formula Approach-----------------
// int NnumbersSum(int n){
//     int result = n * (n + 1)/2;   // formula n*(n+1)/2
//     return result;
// }

// --------------------------- recurssion Approach ------------
int NnumbersSum(int n){
    if(n < 1){
        return 0;
    }
    return n + NnumbersSum(n - 1);
}

int main(){
    int result = NnumbersSum(4);
    cout << "Result: " << result << endl;

    return 0;
}

// Sum of First N Numbers
// Hint
// Given an integer N, return the sum of first N natural numbers. Try to solve this using recursion.

// Examples:
// Input : N = 4
// Output : 10
// Explanation : first four natural numbers are 1, 2, 3, 4.
// Sum is 1 + 2 + 3 + 4 => 10.

// Input : N = 2
// Output : 3
// Explanation : first two natural numbers are 1, 2.
// Sum is 1 + 2 => 3.