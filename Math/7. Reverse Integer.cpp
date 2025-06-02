#include <iostream>
#include <climits>
using namespace std;

// ----------------------Approach O(logv10N) -------------------------

// int reverseNumber(int n){
//     int result = 0;
//     while(n > 0){
//         // int lastDig = n%10;
//         result = (result*10) + n%10;
//         n = n/10;
//     }
//     return result;
// }

// ------------------------Revised solution for leetcode---------
int reverse(int x) {
        int revInt = 0;
        while(x != 0){ //!Note here (x!=0) and not (x > 0)
            int lastDig = x%10;
            if(revInt > INT_MAX/10 || (revInt == INT_MAX/10 && lastDig > 7)){
                return 0;
            }
            if(revInt < INT_MIN/10 || (revInt == INT_MIN/10 && lastDig < -8)){
                return 0;
            }
            revInt = (revInt * 10) + lastDig;
            x = x / 10;
        }
        return revInt;
    }

int main(){
    int result = reverse(1234567);
    cout << "Result: " << result << endl;
    return 0;
}

// 7. Reverse a number
// Hint
// You are given an integer n. Return the integer formed by placing the digits of n in reverse order.

// Examples:
// Input: n = 25
// Output: 52
// Explanation: Reverse of 25 is 52.

// Input: n = 123
// Output: 321
// Explanation: Reverse of 123 is 321.