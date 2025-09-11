#include <iostream>
#include <vector>

int countOccurence(std::vector<int> nums, int target){
    int n = nums.size();
    int st = 0, ed = n - 1;
    while(st <= ed){
        int mid = st + (ed - st) / 2;
        if(nums[mid] == target){
            int left = mid;
            int right = mid;
            int ans = 1;
            while(left > 0 && nums[left - 1] == target){
                ans++;
                left--;
            }
            while(right < n-1 && nums[right + 1] == target){
                ans++;
                right++;
            }
            return ans;
        }else if(nums[mid] > target){
            ed = mid - 1;
        }else{
            st = mid + 1;
        }
    }
}

int main(){
    std::vector<int> arr = {1, 1, 2, 2, 2, 2, 2, 3};
    int k = 2;
    int result = countOccurence(arr, k);
    std::cout<< "Result: " << result << std::endl;
    return 0;
}

// Count Occurrences in Sorted Array

// Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

// Examples

// Example 1:
// Input: N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
// Output: 4
// Explanation: 3 is occurring 4 times in
// the given array so it is our answer.

// Example 2:
// Input: N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
// Output: 5
// Explanation: 2 is occurring 5 times in the given array so it is our answer.