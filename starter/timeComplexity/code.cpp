#include <iostream>
#include <vector>
using namespace std;

    // Factorial    ------------------> 
    // int factorial(int n) { ----------> O(n) Even space complexity is same , because the stack depth is appx to n.
    //     if(n == 0){
    //         return 1;
    //     }

    //    return n*factorial(n -1);
    // }

    // Fibonacci    ------------------> O(2^n)
    int fibonacci(int n){
        if(n == 1 || n == 0){
            return n;
        }

        return fibonacci(n-1) + fibonacci(n-2);
    }

int main(){
    // //Print Prime Number ------> O(root(n)) becuase i is running i2=n i.e. i=root(n)
    // int n = 7;
    // for(int i=2; i*i<=n; i++){
    //     if(n%i == 0){
    //         cout << "Non Prime";
    //         break;
    //     }
    //     cout << "Prime Number";
    // }


    // cout << factorial(3); 
    cout << fibonacci(6); 
    cout << endl;
    return 0;
}

//Time Complexities(
// 1. Constant --> O(1) || O(k) which is parrallel to x axis and is the most complex time.
// 2. Linear --> O(n) loop runs same time as the n , so x=y .
// 3. --> O(n^2) || O(n^3) generally on 2 || 3 nested loop  , the complexity of n running is double
// 4. ---> O(logn) second best time complexity , generally if in any algo we encounter situation where the arr or val is decreasing to half to find solution0 .
// 5. ---> O(nlogn)
// 6. ---> O(n^2)
// 7. Exponential --->O(2^n) seen in bruteforce recurssion ==this starts to make worst time complexity
// 8. O(n!)

// TC = total calls * workeDone in each call
// since in tree the split results 2^0 2^1 2^2 2^3 for n=4; So it means ==> 2^n-1
//Sum = a(r^n-1)/(r-1) where a is starting value r, common difference. n total number 
// 2^0* 2^n-1/2-1 ==> 2^n-1

//Fibonacci
//Recurrence solution :  TC(n) = T(n-1)+ T(n-1) + O(k) ===> O(2^n) 
//How? ==> TC = total number of calls * WD in each call

//Practical usage
// Generally 1 second takes to run 10^8 opreation, So if it takes moew time TLE occurs --> Time limit Exceeds
// So optimise more code
// How to calculate?------------
//If the code tells n<= 10^5 so can we do O(n^2) operation i.e 2 loops ---> so (10^5)^2 => 10^10 which is more than time limit so we could not and try to optimise

//Generall constrants:
// n>10^8 ==> O(logn) || O(k)
// n<=10^8 ==> O(n) but not worst than this
// n<=10^6 ==> O(logn) not worst than this --and generally logn is realted where sorting is used , so think for that way
// n<=10^4 ==> O(n^2)
// n<=10^500 ==> O(n^3)
// n<=10^25 ==> O(2^n) --> what if this type of question will have recurssion brute force?
// n<=10^12 ==> O(n!)

