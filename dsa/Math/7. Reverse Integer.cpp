#include <iostream>
#include <climits>
using namespace std;

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

// 7. Reverse Integer
// Hint
// You are given an integer n. Return the integer formed by placing the digits of n in reverse order.

// Examples:
// Input: n = 25
// Output: 52
// Explanation: Reverse of 25 is 52.

// Input: n = 123
// Output: 321
// Explanation: Reverse of 123 is 321.

//Condition Examples:
// Example 1:
// Suppose revInt = 214748364, and the next lastDig is 8.
// revInt * 10 + 8 = 2147483640 + 8 = 2147483648, which is greater than INT_MAX (2147483647), causing an overflow.
// The condition revInt == INT_MAX / 10 && lastDig > 7 will trigger this check and return 0 to avoid the overflow.

// Example 2:
// Suppose revInt = -214748364, and the next lastDig is -9.
// revInt * 10 + (-9) = -2147483640 - 9 = -2147483649, which is less than INT_MIN (-2147483648), causing an underflow.
// The condition revInt == INT_MIN / 10 && lastDig < -8 will trigger this check and return 0 to avoid the underflow.