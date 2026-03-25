#include <bits/stdc++.h>

//---------------------------------------Bruteforce->TC->O(N^2)--SC->O(1)------------------------
// Time limit exceed
// int trap(std::vector<int>& height) {
//     int totalWater = 0;
//     int n = height.size();

//     for(int i = 0; i < n; i++){
//         int maxLeft = 0, maxRight = 0;
//         for(int j = 0; j <= i; j++){
//             if(height[j] > maxLeft){
//                 maxLeft = height[j];
//             }
//         }
//         for(int j = i; j < n; j++){
//             if(height[j] > maxRight){
//                 maxRight = height[j];
//             }
//         }

//         totalWater += std::min(maxLeft, maxRight) - height[i];
//     }
//     return totalWater;
// }

//--------------------------------Approach--TC->O(N)--SC->O(1)-----------------------
// the two points will keep on incr and decr , by storing the max of individual in var
int trap(std::vector<int>& height) {
    int maxLeft = 0, maxRight = 0;
    int totalWater = 0;
    int n = height.size();
    int left = 0;
    int right = n - 1;

    while(left <= right){
        if(height[left] <= height[right]){
            if(height[left] >= maxLeft){
                maxLeft = height[left]; //Since this is the spike in height, the water will not be filled
            }else{
                totalWater += maxLeft - height[left];
            }
            left++;
        }else{
            if(height[right] >= maxRight){
                maxRight = height[right]; //Since this is the spike in height, the water will not be filled
            }else{
                totalWater += maxRight - height[right];
            }
            right--;
        }
    }
    return totalWater;
}

int main(){
    std::vector<int> nums = {4,2,0,3,2,5};
    int result = trap(nums);
    std::cout << result << std::endl;
    
    return 0;
}

// 42. Trapping Rain Water
//! Hard

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Example 1:
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
// In this case, 6 units of rain water (blue section) are being trapped.

// Example 2:
// Input: height = [4,2,0,3,2,5]
// Output: 9
 
// Constraints:
// n == height.length
// 1 <= n <= 2 * 104
// 0 <= height[i] <= 105