#include <bits/stdc++.h>

//---------------------------------Brute Force Approach --TC->O(N^2)------------------------------
// long long subArrayRanges(std::vector<int>& nums) {
//     int n = nums.size();

//     long long sum = 0;
    
//     for(int i=0; i < n; i++) {
//         int smallest = nums[i];
//         int largest = nums[i];
        
//         /* Nested loop to get all subarrays starting from index i */
//         for(int j=i; j < n; j++) {
//             smallest = std::min(smallest, nums[j]);
//             largest = std::max(largest, nums[j]);
            
//             // Update the sum simply
//             sum += (largest - smallest);
//         }
//     }
//     return sum;
// }

//---------------------------------Brute Force Approach --TC->O(N2)--SC->O(N)------------------------------
 /* next smaller elements */
std::vector<int> findNSE(std::vector<int> &arr) {
    int n = arr.size();
    std::vector<int> ans(n);
    
    std::stack<int> st;
    
    // Start traversing from the back
    for(int i = n - 1; i >= 0; i--) {
        int currEle = arr[i];
        while(!st.empty() && arr[st.top()] >= arr[i]){ // Pop the elem until notEmpty and top is not the smaller element
            st.pop();
        }
        ans[i] = !st.empty() ? st.top() : n; // Note to keep n as last index in else case
        st.push(i);
    }
    return ans;
}

/* previous smaller or equal elements */
std::vector<int> findPSEE(std::vector<int> &arr) { //! Remember why previous small and "equal" elem. if arr = [1, 1]
    int n = arr.size();
    std::vector<int> ans(n);
    
    std::stack<int> st;
    
    // Traverse on the array straight
    for(int i=0; i < n; i++) {
        int currEle = arr[i];
        while(!st.empty() && arr[st.top()] > arr[i]){ //  Pop the elem until notEmpty and top is not the grater element
            st.pop();
        }
        ans[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }
    return ans;
}

/* next greater elements */
std::vector<int> findNGE(std::vector<int> &arr) {
    int n = arr.size();
    std::vector<int> ans(n);
    
    std::stack<int> st;
    
    // Start traversing from the back
    for(int i = n - 1; i >= 0; i--) {
        int currEle = arr[i];

        while(!st.empty() && arr[st.top()] <= currEle){
            st.pop();
        }
        ans[i] = !st.empty() ? st.top() : n;
        st.push(i);
    }
    return ans;
}

/* previous greater or equal elements */
std::vector<int> findPGEE(std::vector<int> &arr) {
    int n = arr.size();
    std::vector<int> ans(n);
    std::stack<int> st;
    
    for(int i=0; i < n; i++) {
        int currEle = arr[i];
        
        while(!st.empty() && arr[st.top()] < currEle){
            st.pop();
        }
        ans[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }
    return ans;
}

/* Function to find the sum of the 
minimum value in each subarray */
long long sumSubarrayMins(std::vector<int> &arr) {

    std::vector<int> nse = findNSE(arr);    
    std::vector<int> psee = findPSEE(arr);
    
    int n = arr.size();
    long long sum = 0;
    
    // Traverse on the array
    for(int i=0; i < n; i++) {
        int left = i - psee[i];
        int right = nse[i] - i;

        long long freq = left*right*1LL;

        long long val = (freq*arr[i]*1LL);

        sum += val;
    }
    return sum;
}

/* Function to find the sum of the 
maximum value in each subarray */
long long sumSubarrayMaxs(std::vector<int> &arr) {
    
    std::vector<int> nge = findNGE(arr);    
    std::vector<int> pgee = findPGEE(arr);

    int n = arr.size();

    long long sum = 0;
    
    // Traverse on the array
    for(int i=0; i < n; i++) {

        int left = i - pgee[i];
        int right = nge[i] - i;
        
        /* Count of subarrays where 
        current element is minimum */
        long long freq = left*right*1LL;
        
        // Contribution due to current element 
        long long val = (freq*arr[i]*1LL);
        
        // Updating the sum
        sum += val;
    }
    return sum;
}

long long subArrayRanges(std::vector<int>& nums) {
    return ( sumSubarrayMaxs(nums) - sumSubarrayMins(nums) );
}

int main(){
    std::vector<int> nums = {1,2,3};
    long long result = subArrayRanges(nums);
    std::cout << result << std::endl;
    
    return 0;
}


// 2104. Sum of Subarray Ranges

// You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
// Return the sum of all subarray ranges of nums.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:
// Input: nums = [1,2,3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0 
// [2], range = 2 - 2 = 0
// [3], range = 3 - 3 = 0
// [1,2], range = 2 - 1 = 1
// [2,3], range = 3 - 2 = 1
// [1,2,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

// Example 2:
// Input: nums = [1,3,3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0
// [3], range = 3 - 3 = 0
// [3], range = 3 - 3 = 0
// [1,3], range = 3 - 1 = 2
// [3,3], range = 3 - 3 = 0
// [1,3,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.

// Example 3:
// Input: nums = [4,-2,-3,4,1]
// Output: 59
// Explanation: The sum of all subarray ranges of nums is 59.
 
// Constraints:
// 1 <= nums.length <= 1000
// -109 <= nums[i] <= 109
 
//! Follow-up: Could you find a solution with O(n) time complexity?
