#include <iostream>
#include <vector>

//------------------------------------ My approach -- Wroing understanding----

// int lowerBound(std::vector<int>& nums, int k){
//     int st = 0, ed = nums.size();
//     while(st <= ed){
//         int mid = st + (ed - st)/2;
//         if(nums[mid] == k){
//             return mid;
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
    std::vector<int> arr = {3,5,8,15,19};
    int k = 9;
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

// What is Lower Bound?
// The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

// The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.