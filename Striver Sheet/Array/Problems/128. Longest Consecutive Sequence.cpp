#include <bits/stdc++.h>

// ------------------------------------Better Approach--TC->O(nlogn)--SC->O(1)---------------------------
// int longestConsecutive(std::vector<int>& nums) {
//     if(nums.size() == 0) return 0;
//     std::sort(nums.begin(), nums.end());
//     int cnt = 0, maxCnt = 1;
//     int lastSmaller = INT_MIN;
//     for(int i = 0; i < nums.size(); i++){
//         if(nums[i] - 1 == lastSmaller){ // 1. If the number - 1 == previous , so the sequence is ready 
//             cnt++;
//             lastSmaller = nums[i];
//         }else if(nums[i] != lastSmaller){ // 2. if the current number is not same , means no sequence, Incase of same, count will not add sequence will continue
//             cnt = 1; 
//             lastSmaller = nums[i];
//         }
//         maxCnt = std::max(cnt, maxCnt);
//     }
//     return maxCnt;
// }

// ------------------------------------Optimal Approach--TC->O(N)--SC->O(N)---------------------------
int longestConsecutive(std::vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;

    int maxCnt = 1;
    std::unordered_set<int> st;
    for(int i = 0; i < n; i++){
        st.insert(nums[i]);
    }
    // Traverse the set to find the longest sequence
    for(auto it : st){
        if(st.find(it - 1) == st.end()){ // if the value sequence is not found. It is starting num of sequence
            int cnt = 1;
            int x = it; // Starting element of the sequence
            while(st.find(x+1) != st.end()){
                x++;
                cnt ++;
            }
            maxCnt = std::max(maxCnt, cnt);
        }// sequence count condition will not run until some connection is found
    }
    return maxCnt;
}

// Think like, i want to run a sequence when the num - 1 is not found, and when it is found, i will try to count the sequence. if the sequence break some count may or may not be stored , thats the main answer we want



int main(){
    std::vector<int> arr = {0,3,7,2,5,8,4,6,0,1};
    int result = longestConsecutive(arr);

    std::cout << "Longest consecutive sequence length : " << result << " ";

    return 0;
}

// 128. Longest Consecutive Sequence

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

//! You must write an algorithm that runs in O(n) time.

// Example 1:
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

// Example 2:
// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9

// Example 3:
// Input: nums = [1,0,1,2]
// Output: 3
 
// Constraints:
// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109