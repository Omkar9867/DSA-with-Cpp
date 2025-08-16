#include <iostream>
#include <vector>

//-----------------------------------------------My Approach-----------------------------
// std::vector<int> findFloorAndCeil(std::vector<int> nums, int x){
//     int n = nums.size()-1;
//     int st = 0, ed = n;
//     std::vector<int> result(2);
//     while(st <= ed){
//         int mid = st + (ed - st) / 2;
//         if(nums[mid] > x){
//             result.clear();
//             result.push_back(nums[mid - 1]);
//             result.push_back(nums[mid]);
//             ed = mid - 1;
//         }else if(nums[mid] < x){
//             result.clear();
//             result.push_back(nums[mid]);
//             result.push_back(nums[mid + 1]);
//             st = mid + 1;
//         }else{
//             result.clear();
//             result.push_back(nums[mid]);
//             result.push_back(nums[mid]);
//             break;
//         }
//     }
//     return result;
// }

// ------------------------- Better code placement---------------
std::vector<int> findFloorAndCeil(std::vector<int> nums, int x){
    int n = nums.size()-1;
    int st = 0, ed = n;
    int floor = -1, ceil = -1; 
    // find floor
    while(st <= ed){
        int mid = st + (ed - st) / 2;
        if(nums[mid] > x){
            ed = mid - 1;
        }else if(nums[mid] < x){
            floor = nums[mid];
            st = mid + 1;
        }else{
            floor = ceil = nums[mid];
            return {floor, ceil};
        }
    }
    // find ceil // first reset st and ed
    st = 0, ed = n;
    while(st <= ed){
        int mid = st + (ed - st) / 2;
        if(nums[mid] > x){
            ceil = nums[mid];
            ed = mid - 1;
        }else if(nums[mid] < x){
            st = mid + 1;
        }else{
            floor = ceil = nums[mid];
            return {floor, ceil};
        }
    }
    
    return {floor, ceil};
}

int main(){
    std::vector<int> arr = {3, 4, 4, 7, 8, 10};
    int k = 5;
    std::vector<int> result = findFloorAndCeil(arr, k);
    for(int i=0; i<result.size(); i++){
        std::cout << result[i] << " " ; 
    }
    return 0;
}

// Problem Statement: You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
// The floor of x is the largest element in the array which is smaller than or equal to x.
// The ceiling of x is the smallest element in the array greater than or equal to x.

// Example 1:
// Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
// Result: 4 7
// Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

// Example 2:
// Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
// Result: 8 8
// Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
