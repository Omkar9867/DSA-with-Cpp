#include <iostream>
using namespace std;

// ------------------------Pointers Approach
// void reverseArr(int arr[], int n){
//     int p1 = 0, p2 = n-1;
//     while(p1 < p2){
//         swap(arr[p1], arr[p2]);
//         p1++;
//         p2--;
//     }
// }

// ----------------------------Recursion Approach
void reverseArr(int arr[], int start, int end) { // the two pointers can be updates when calling function inside again
   if (start < end) {
      swap(arr[start], arr[end]);
      reverseArr(arr, start + 1, end - 1);
   }
}


int main(){
    int arr[] = {1,2,3,4,5};
    // reverseArr(arr, 5);
    reverseArr(arr, 0, 5-1);
    for(int i=0; i <5; i++){
        cout << arr[i] << ',';
    }

    return 0;
}

// Reverse an array

// Hint
// Given an array arr of n elements. The task is to reverse the given array. The reversal of array should be inplace.

// Examples:
// Input: n=5, arr = [1,2,3,4,5]
// Output: [5,4,3,2,1]
// Explanation: The reverse of the array [1,2,3,4,5] is [5,4,3,2,1]

// Input: n=6, arr = [1,2,1,1,5,1]
// Output: [1,5,1,1,2,1]
// Explanation: The reverse of the array [1,2,1,1,5,1] is [1,5,1,1,2,1].