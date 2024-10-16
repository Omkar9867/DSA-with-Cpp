#include <iostream>
using namespace std;

// //Decimal To Binary
// int decimalToBinary(int n){
//     int val = 0;
//     int units = 1;
//     while (n > 0){
//         int remainder = n % 2;
//         n /= 2;
//         val += (remainder * units);
//         units *= 10;
//     }
//     return val;
// }

//Binary to Decimal
int binaryToDecimal(int n){
    int val = 0;
    int power = 1; //As we discussed earlier split the last number will be remainder and getting all forwards number would be possible my dividing it with 10
    while(n > 0){
        int remainder = n % 10;
        n = n/10;
        val += (remainder * power);
        power *= 2;
    }
    return val;
}

int main(){
    // int binaryNum = decimalToBinary(50);
    int decimalNum = binaryToDecimal(101010);

    // cout << "Binary Number : " << binaryNum << endl;
    cout << "Decimal Number : " << decimalNum << endl;

    return 0;
}

//Normal Math is call ==> Decimal Number System because it is around 0-9 which is called 'dec'; Base-10
//But in programming computers read only 0 & 1 so it is call ==> Binary Number System; Base-2

//Various types of decimals:
//HexaDecimal --> Base-16 where Hex = 6 Dec = 10 so 16
//Octal --> Base-8 

//Conversion of Decimal to Binary

// The Decimal number should be repeated divide by 2 and then the backward reading of that number will be the binary form .
// Example: decimalNumber = 42 ===>    2  | 42  0   So the binary form of 42 is 101010.
//                                     2  | 21  1
//                                     2  | 10  0
//                                     2  |  5  1
//                                     2  |  2  0
//                                     2  |  1  1
//                                           0

//We can say (42)base10 = (101010)base2

// Steps ===> 
//Now to write this in the code, we will loop till n is grater then 0;
//Initializing 2 variable with the main value, and to update the units.
//Then we'll first extract the remainder by repeated divide with 2, and then update the n to its quotient, When updating the n = quotient, n will then come to zero to end the loop
//The logic of solution is when well multiply the remainder with its unit and add to its previous values.
// then increase the units with its 10th value. Example : tens, hundreds, thousands, .... again multiply with updated remainder and add to its value
// ---->>> Simple here looks like if : 1101 is binary, 1*1, 0*10, 1*100, 1*1000 and add them ===>> 1+0+100+1000 = 1101;

//Lastly adding the value to the main solution variable will give the answer after the loop is completed.

//Binary to Decimal is very straitforward ==> 
// Simply multiply each digit with increasing 2power and add all them