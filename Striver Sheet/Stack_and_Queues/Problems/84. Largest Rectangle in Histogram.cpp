#include <bits/stdc++.h>

//---------------------------Brute Force Approach-TC->O(N^2)-------------------------
// int largestRectangleArea(std::vector<int>& heights) {
//     int maxArea = 0;  // Variable to store maximum area found
//     int n = heights.size();
//     for (int i = 0; i < n; i++) {
//         int minHeight = INT_MAX;

//         // Inner loop to set the ending index of the subarray
//         for (int j = i; j < n; j++) {
//             // Update minimum height in the current window
//             minHeight = std::min(minHeight, heights[j]);

//             // Calculate area = height * width(how many times)
//             int width = j - i + 1;
//             int area = minHeight * width;

//             // Update maxArea if this area is larger
//             maxArea = std::max(maxArea, area);
//         }
//     }

//     return maxArea;
// }

//---------------------------Optimised Approach 1-TC->O(N)-------------------------
// calculate NSR & NSL -> Subnract them to get the distance of subarray i.e. width
// Multiply that width with the num
// Compare with max and update
//! Need valid span (boundaries), Here you need adjusted indices → to compute width directly
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
        ans[i] = !st.empty() ? st.top() - 1 : n - 1; // Note to keep (n-1) as last index in else case
        st.push(i);
    }
    return ans;
}
std::vector<int> findPSEE(std::vector<int> &arr) {
    int n = arr.size();
    std::vector<int> ans(n);
    
    std::stack<int> st;
    
    // Traverse on the array straight
    for(int i=0; i < n; i++) {
        int currEle = arr[i];
        while(!st.empty() && arr[st.top()] > arr[i]){ //  Pop the elem until notEmpty and top is not the grater element
            st.pop();
        }
        ans[i] = !st.empty() ? st.top() + 1 : 0; // Note that to return before the boundary
        st.push(i);
    }
    return ans;
}
int largestRectangleArea(std::vector<int>& heights) {
    std::vector<int> nse = findNSE(heights);
        
    std::vector<int> psee = findPSEE(heights);
    int maxArea = INT_MIN;
    for(int i = 0; i < heights.size(); i++){
        int width = nse[i] - psee[i] + 1;
        int maxVal = heights[i] * width;
        maxArea = std::max(maxArea, maxVal);
    }
    return maxArea;
}

int main(){
    std::vector<int> heights = {2,1,5,6,2,3};
    int result = largestRectangleArea(heights);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

// 84. Largest Rectangle in Histogram
// Hard

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

// Example 2:
// Input: heights = [2,4]
// Output: 4

// Constraints:
// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104