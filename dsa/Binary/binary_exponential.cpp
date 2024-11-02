#include <iostream>
using namespace std;

//binary exponential
//Since looping through an element and resulting would take a 0(n) time complex wich is not valid becuase n < 2^31 and a code take 10^8 operations to complete which is less
//So we will loop through its binary form and multiply it with squaring x in next step

double myPow(double x, int n) { //we can also write power cases that we already know
    if(n == 0) return 1.0; // x^0 == 1
    if(x == 0) return 0.0; // 0^anything = 0
    if(x == 1) return 1.0; // 1^anything = 1
    if(x == -1 && n%2 == 0) return 1.0; // x = -1 and power is even then 1  eg: -1^4 = 1
    if(x == -1 && n%2 != 0) return -1.0; //x = -1 and power is odd then 1   eg: -1^5 = -1
    
    long binaryForm = n;
    //Here is the modification of the code ==> Since if my n could be negative than we have to convert it into positive first:
    if(n<0){
        x = 1/x; // if x^-n i.e. 2^-3 then it can be written as 1/2^3.
        binaryForm = -binaryForm; //since we made the x as 1/x so the power also needs to be converted.
    }
    double ans = 1;
    while(binaryForm > 0){
        if(binaryForm % 2 == 1){
            ans*= x;
        }
        x*=x;
        binaryForm /= 2;
    }
    return ans;
}


int main(){
    
    cout << "Pow  = " << myPow(2.00000, -2) << endl;

    return 0;
}

//Question:
// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

// Constraints:

// -100.0 < x < 100.0
// -2^31 <= n <= 2^31-1
// n is an integer.
// Either x is not zero or n > 0.
// -104 <= x^n <= 104