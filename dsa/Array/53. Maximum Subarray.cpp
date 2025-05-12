#include <iostream>
#include <climits>
using namespace std;

int main(){
    // //Brute Force Approach ----> 0(n)2
    // int n = 7;
    // int arr[7] = {3,-4,5,4,-1,7,-8};
    // int maxSum = INT_MIN;
    // for(int st=0; st<n; st++){
    //     int currSum = 0;
    //     for(int ed=st; ed<n; ed++){//Logic here is if we have a sum of the st and end , then on next iteration we must only add the new end with previous currSum.
    //         currSum += arr[ed];
    //         maxSum = max(currSum, maxSum);
    //     }
    // }

    //Optimal Approach ---> Kadane's Approach ----->0(n) i.e Linear Time Complexity
    int n = 7;
    int arr[7] = {3,-4,5,4,-1,7,-8};
    int maxSum = INT_MIN;
    int currSum = 0;
    for(int i=0; i<n; i++){
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if(currSum < 0){  //So here the if condition is placed after the maxSum is because if all elements will be -ve then the max sum will also be negative so to get the main val first then to reset it is places after fetching msxSum
            currSum = 0;
        }
    }

    cout << "Max Sum :" << maxSum << endl;
    return 0;
}

// Question:
// 33. Maximum Subarray Sum ==> 
// Kadane approach says if the currSum number get less than 0 then reset it to 0 because anyhow the max sum will never result if the sum is negative
//if condition is placed after the maxSum is because if all elements will be -ve then the max sum will also be negative so to get the main val first then to reset it is places after fetching msxSum
//These cases are called edge cases or corner cases which is different then usual