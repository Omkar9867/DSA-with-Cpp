#include <bits/stdc++.h>

//----------Bruteforce->to loop j inside i and coditionally replace number plus finid by "%"


//--------------------------------Approach--TC->O(2N)--SC->O(N)-----------------------
// Note to have desc stack
std::vector<int> nextGreaterElements(std::vector<int>& nums) {
    std::stack<int> st;
    std::vector<int>ans(nums.size());
    int n = nums.size();
    for (int i = 2*n - 1; i >= 0; i--) {
        //Getting the actual index
        int idx = i%n;

        //This will get curr elem
        int curr = nums[idx];
        while(!st.empty() && st.top() <= curr){
            st.pop();
        }
        // if(st.empty()){
        //     ans[idx] = -1;
        // }else{
        //     ans[idx] = st.top();
        // }

        if (i < n){ // One write the answers when the imaginary arr is completed and iterating normal arr
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
        }
        st.push(curr);
    }
    return ans;
}

int main(){
    std::vector<int> nums1 = {4,1,2};
    std::vector<int> result = nextGreaterElements(nums1);
    for(int i = 0; i < result.size(); i++){
        std::cout << result[i] << std::endl;
    }
    return 0;
}

// 503. Next Greater Element II

// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. 
// If it doesn't exist, return -1 for this number.


// Example 1:

// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.

// Example 2:
// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]
 
// Constraints:
// 1 <= nums.length <= 104
// -109 <= nums[i] <= 109