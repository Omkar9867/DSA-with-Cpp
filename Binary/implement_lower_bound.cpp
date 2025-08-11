#include <iostream>
#include <vector>

//------------------------------------ My approach

// int lowerBound(std::vector<int>& nums, int k){
//     int st = 0, ed = nums.size();
//     while(st <= ed){
//         int mid = st + (ed - st)/2;
//         if(nums[mid] == k){
//             return mid-1;
//         }else if(nums[mid - 1] < k && nums[mid + 1] > k){
//             return mid;
//         }else if(nums[mid] > k){
//             ed = mid - 1;
//         }else{
//             st = mid + 1;
//         }
//     }
//     return -1;
// }

// ------------------------------Optimal Approach
int lowerBound(std::vector<int>& nums, int k){
    int st = 0, ed = nums.size();
    int ans = nums.size();
    while(st <= ed){
        int mid = st + (ed - st)/2;
        if(nums[mid] >= k){
            ans = mid;
            ed = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    return ans;
}


int main(){
    std::vector<int> arr = {1, 1,3,4};
    int k = 2;
    int result = lowerBound(arr, k);
    std::cout<< "Result: " << result << std::endl;
    return 0;
}

// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

// Pre-requisite: Binary Search algorithm

// Examples

// Example 1:
// Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
// Result: 1
// Explanation: Index 1 is the smallest index such that arr[1] >= x.

// Example 2:
// Input Format: N = 5, arr[] = {3,5,8,15,19}, x = 9
// Result: 3
// Explanation: Index 3 is the smallest index such that arr[3] >= x.