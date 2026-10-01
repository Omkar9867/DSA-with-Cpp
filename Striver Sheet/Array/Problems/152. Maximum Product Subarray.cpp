#include <bits/stdc++.h>

// ---------------------------------------Optimal Approach--TC->O(N)--SC->O(1)---------------------------------
//----------------------------------------prefix/suffix product approach--------------------------------------- // Because of negative number
int maxProduct(std::vector<int>& nums) {
    int n = nums.size();
    int ans = nums[0];

    int left , right = 1;
    for(int i = 0; i < n; i++){
        if(left == 0){ //Prefix product
            left = 1;
        }
        left *= nums[i];
        ans = std::max(ans, left);

        if(right == 0){//Suffix product
            right = 1;
        }
        right *= nums[n - 1 - i];
        ans = std::max(ans, right);
    }
    return ans;
}

int main(){
    std::vector<int> arr = {2,3,-2,4};
    int result = maxProduct(arr);
    std::cout << "Result: " << result << std::endl;
    return 0;
}



// 152. Maximum Product Subarray

// Given an integer array nums, find a subarray that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.
// Note that the product of an array with a single element is the value of that element.

// ​​​​​​​Example 1:
// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Example 2:
// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 
// Constraints:
// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10
// The product of any subarray of nums is guaranteed to fit in a 32-bit integer.