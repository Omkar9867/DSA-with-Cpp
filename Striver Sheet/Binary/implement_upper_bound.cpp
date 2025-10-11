#include <iostream>
#include <vector>

// ------------------------------------My Approach
int upperBound(std::vector<int>& nums, int x){
    int n = nums.size();
    int st = 0, ed = n;
    int ans = n;
    while(st<=ed){
        int mid = st + (ed - st)/2;
        if(nums[mid] < x){
            st = mid + 1;
        }else if(nums[mid] == x){
            ans = mid+1;
            return ans;
        }else{
            ans = mid;
            ed = mid -1;
        }
    }
    return ans;
}

int main(){
    std::vector<int> arr = {1,2,2,3};
    int k = 2;
    int result = upperBound(arr, k);
    std::cout<< "Result: " << result << std::endl;
    return 0;
}

// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.

// Pre-requisite: Binary Search algorithm

// Examples

// Example 1:
// Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
// Result: 3
// Explanation: Index 3 is the smallest index such that arr[3] > x.

// Example 2:
// Input Format: N = 6, arr[] = {3,5,8,9,15,19}, x = 9
// Result: 4
// Explanation: Index 4 is the smallest index such that arr[4] > x.

// What is Upper Bound?
// The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.

// The upper bound is the smallest index, ind, where arr[ind] > x.

// But if any such index is not found, the upper bound algorithm returns n i.e. size of the given array. 
// The main difference between the lower and upper bound is in the condition. 
// For the lower bound the condition was arr[ind] >= x and here, in the case of the upper bound, it is arr[ind] > x.