#include <iostream>
using namespace std;

// int printFunc(){
//     cout << "Hello World" << endl;
//     return 3;
// }

// //Calculate sum of 2 numbers
// int sumFunc(int a, int b){ //can also do  double type.
//     return a + b;
// }

// //min of 2 numbers
// int minNum(int a, int b) {
//     if(a<b){
//         return a;
//     }else{
//         return b;
//     }
// }

// //Calculate sum of 1 to n
// int sumNFunc(int n){
//     int sum = 0;
//     for(int i=1; i<=n; i++){
//       sum += i;  
//     }
//     return sum;
// }

// //Calculate n factorial
int factorialFunc(int n){
    int fact = 1;   //Initialize with 1
    for(int i=1; i<=n; i++){
      fact *= i;  
    }
    return fact;
}

// //Calculate sum of digits of number
// int sumDigFunc(int n){   //Logic here is to first split the number and then sum, but splitting the number would be done by ==> n%10 till it becomes 0, which gives logic that every number dividing by 10 gives last digit as its remainder
//   int digitSum = 0;
//   while(n > 0){
//     int lastDigit = n % 10;
//     n = n /10;  //Simple Logic here is when divide by 10 gives the first remaining numbers. Meaning ===> n%10 give remainder; whereas n/10 gives quotient
//     digitSum += lastDigit;
//   }
//   return digitSum;
// }

//Calculate nCr binomial coefficient for n & r
//Formula is ===> n! / (r!(n-r)!)
int nCr(int n, int r){ //Since we have made the factorial function we can use them to get the n and r ! and divide them
  int fac_n = factorialFunc(n);
  int fac_r = factorialFunc(r);
  int fac_nmr = factorialFunc(n-r);

  return fac_n / (fac_r*fac_nmr);
}

int main(){
    // int val = printFunc();
    // int sum = sumFunc(1, 0);
    // int min = minNum(12, 12);
    // int sumTillN = sumNFunc(7);
    // int factorialN = factorialFunc(4);
    // int digitSum = sumDigFunc(597);
    int binomialCoeff = nCr(8, 2);
    cout << "Digits Sum : " << binomialCoeff << endl;
    cout << "Finish" << endl;
    return 0;
}


//When function is made, inside the parathesis eg: int minNum(int a, int b) ==>  it is called Parameters
//When function is called, inside the parathesis eg: int minNum(1, 2) ==> it is called Arguments

//Basic knowledge ==> whenever trying to make sum function initialize with 0 eg: int sum = 0, but for factorial initialize with 1 i.e. int fac = 1

//Function in Memory:
//2 types of memory:
// 1. Stack  ==> used for static allocation 
// 2. Heap   ==> used for dynamic allocation
// For now all function are stored in our stack memory, basically our stack keeps on adding the functions inside him called by main() --> that func() --> another func()
//so when the functions are executed step by step the stack gets empty finally calling main(); and fully empty

//Pass by value
//Copy of an argument is passed into the function. Eg:
//fucn(a, b) x=1, y=3 func(x, y) ==> Now the x and y values make copy in memory and passed to parameters Because : 'a' and 'b' have different address from 'x' and 'y'

//Pass by referenc
//It is opposite of the pass by value , generally the args and parameters both will have the same addreess plus values.