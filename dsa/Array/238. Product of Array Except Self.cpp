#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// //-----------------------------------BruteForce Approach --> O(n^2) -----------------------------------
// vector<int>productExceptSelf(vector<int>& nums){
//     int n = nums.size();
//     vector<int> ans(n, 1);
//     for(int i=0; i<n; i++){
//         // int product = 1; no need of product variable direct calulate in ans[i]^th index
//         for(int j=0; j<n; j++){
//             if(i != j){
//                 ans[i] *= nums[j];
//             }
//         }
//     }
//     return ans;
// }

// //-----------------------------Optimal Approach -->O(n) -->SpaceComplexity-->O(1)-------------------
//Approach here is to calculate prefix , suffix and then multiplying both
//Here 3 loop will be run with O(3n) ==> which will result O(n) 
vector<int>productExceptSelf(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n, 1);
    // vector<int> pre(n, 1);
    // vector<int> suff(n, 1);
    // for(int i=1; i<n; i++){ //calulate prefix ==> simply prefix of current index would be (index of previous prefix) * (index of previous arr)
    //     pre[i] = pre[i-1]*nums[i-1];
    // }

    // for(int i=n-2; i>=0; i--){ //calulate suffex ==> simply suffex of current index would be (index of next suffex) * (index of next arr)
    //     suff[i] = suff[i+1]*nums[i+1]; //Note to write the reverse arr correctly
    // }

    // for(int i=0; i<n; i++){ //Multiply prefix and suffix
    //     ans[i] = pre[i]*suff[i];
    // }

    // for(int i=0; i<n; i++){ 
    //     ans[i] = pre[i]*suff[i];
    // }
    // ----------------***------------***-----------------
    //For Space complexity since rather than storing and multiplying the suff and pre will directly multiply in the loop
    // ----------------***------------***-----------------
    for(int i=1; i<n; i++){ 
        ans[i] = ans[i-1]*nums[i-1]; //rather than storing in pre directly calculate in ans arr
    }
    int suffix = 1;
    for(int i=n-2; i>=0; i--){ 
        suffix *= nums[i+1]; //for suffix now since my ans has already val so well initialize the suffix with one and then the multiplication will multiply in ans
        ans[i] *= suffix;  // Technically want to multiply with the suffix val of my nums
    }

    return ans;
}

int main() {
    vector<int>num = {1,2,3,4};
    vector<int>ans = productExceptSelf(num);
    for(int i=0; i<ans.size(); i++){
    cout << ans[i] << ", ";
    }
    cout << endl;
    return 0;
}

// // Question :
// 238. Product of Array Except Self
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation. 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 

// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.