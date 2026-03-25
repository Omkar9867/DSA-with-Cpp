#include <bits/stdc++.h>

//----------Bruteforce->to loop j inside i and coditionally replace number --------------------


//--------------------------------Approach--TC->O(2N)--SC->O(N)-----------------------
// Note to have desc stack
std::vector<int> nextSmallerElements(std::vector<int>& nums) {
    std::stack<int> st;
    std::vector<int>ans(nums.size());
    int n = nums.size();
    for (int i = n-1; i >= 0; i--) {
      int curr = nums[i];
      while(!st.empty() && st.top() >= curr){
        st.pop();
      }
      if(!st.empty()){
        ans[i] = st.top();
      }else{
        ans[i] = -1;
      }
      st.push(curr);
    }
    return ans;
}

int main(){
    std::vector<int> nums1 = {4, 8, 5, 2, 25};
    std::vector<int> result = nextSmallerElements(nums1);
    for(int i = 0; i < result.size(); i++){
        std::cout << result[i] << ", ";
    }
    std::cout << std::endl;
    return 0;
}

// Next Smaller Element

// Problem Statement: Given an array of integers arr, your task is to find the Next Smaller Element (NSE) for every element in the array.
// The Next Smaller Element for an element x is defined as the first element to the right of x that is smaller than x.
// If there is no smaller element to the right, then the NSE is -1.

// Examples
// Example 1:
// Input:
//  arr = [4, 8, 5, 2, 25]
// Output:
//  [2, 5, 2, -1, -1]
// Explanation:

// - For 4, the next smaller element is 2.
// - For 8, the next smaller element is 5.
// - For 5, the next smaller element is 2.
// - For 2, there is no smaller element to its right → -1.
// - For 25, no smaller element exists → -1.

// Example 2:
// Input:
//  arr = [10, 9, 8, 7]
// Output:
//  [9, 8, 7, -1]
// Explanation:

// Each element’s next right neighbor is smaller.
// Each element’s next right neighbor is smaller.