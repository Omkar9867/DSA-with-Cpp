#include <iostream>
using namespace std;


// WAF to reverse an Integer
int reverseInt(int n){
    int reverse = 0;
    while (n > 0) { //Logic here is to revers the order first extract the last digit, update the n , and to add those in reverse , forst multiply by 10
        int digit = n % 10;
        n = n / 10;
        reverse = reverse*10 + digit;
    }
    return reverse;
}
int main() {
    int a = 8, b=4;
    unsigned int x = -10;

    // cout << sizeof(12345) << endl;
    cout << reverseInt(123456) << endl;
    return 0;
}

//Bitwise Operators
// Bitwise & --> AND
// Bitwise | --> OR
// Bitwise ^ --> XOR

//Bitwise << --> Left Shift Operator
//Bitwise >> --> Right Shift Operator

//How to calculate ===>
// If & then 1&1 = 1 rest all are zero
//If | then 0&0 = 0 rest all are one
//If ^ then 0^0 = 0 , 1^1 = 0, 0^1 = 1, 1^0 = 1
// << shift the binary numbers to left side and the empty space is filled with zero creating whole a another value. Generally the value is the double of the result value i.e. a * 2power(b)
// >> sift the binary numbers to right side and since no space left on right side the number gets eliminate and leftover number is the main value. i.e. a/2power(b)

// Then we already know how to calculate the binary number to get the Decimal by multiply each with 2power and add them
//Example: 0100+1000 == 1100 each will be 8+4+0+0 = 12

//Operator Precedence
// Priority of the operation that will first operate eg: ++, -- then *, / etc.
// But if wrapped in parenthesis then that operation will operate first.

//Scope
//Variables that are defined inside ==> if()else(), functions() loops(), etc. or any block of code {..}. is called Local Scope
//Variables that we want to access any where around the code is called ==>Global Scope


//Data Type Modifiers [Change the meaning of exist data type]
//Generally our data type stores a amount of space eg: int x; stores 4bytes i.e. 32bits .
//So data modifies can increase or decrease the size of the data type
//Modifiers Types :::>
//long --> increases 4 bytes
//short --> decreases 2 bytes
//long long
//signed --> Generally all int are signed cause they store +ve and -ve numbers
//unsigned --> It is used to specifically store +ve in cases, and as -ve are not allowed so we can store more range of data inside the variable.