#include <iostream>
using namespace std;

bool checkIsSorted(int arr[], int n){
    int count = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i-1]){
            count ++;
        }
    }
    // If there was one descent, check if the last element is smaller than the first one
    if (count == 1 && arr[n-1] > arr[0]) return false;
    return count <= 1;
}

int main(){
    int arr[] = {2,1,3,4};
    // int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = 4;
    const char* boolList[] = {"False", "True"};
    bool isSorted = checkIsSorted(arr, n);
    cout << "Arr sorted is " << boolList[isSorted] << endl;
    return 0;
    return 0;
}

// 1752. Check if Array Is Sorted and Rotated

// Hint
// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
// There may be duplicates in the original array.
// Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

// Example 1:
// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].

// Example 2:
// Input: nums = [2,1,3,4]
// Output: false
// Explanation: There is no sorted array once rotated that can make nums.

// Example 3:
// Input: nums = [1,2,3]
// Output: true
// Explanation: [1,2,3] is the original sorted array.

// You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.

// Constraints:
// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100