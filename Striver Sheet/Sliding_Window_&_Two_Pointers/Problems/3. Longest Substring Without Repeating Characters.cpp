#include <bits/stdc++.h>

//----------------------------------Brute Force Approach--TC->O(N^2)---------------------------
int lengthOfLongestSubstring(std::string s) {
    int n = s.size(); 
    int maxLen = 0;    
    
    for (int i = 0; i < n; i++) {
        
        // Hash to track characters in the current substring window
        // Assuming extended ASCII characters
        std::vector<int> hash(256, 0);  
        
        for (int j = i; j < n; j++) {
            
            /* If s[j] is already in the current substring window*/
            if (hash[s[j]] == 1) break;  
            
            /* Update the hash to mark s[j] as present in the current window*/
            hash[s[j]] = 1;
            
            /* Calculate the length of the current substring*/
            int len = j - i + 1;
            
            maxLen = std::max(maxLen, len);
        }
    }
    return maxLen; 
}

int main(){

    return 0;
}

// 3. Longest Substring Without Repeating Characters

// Given a string s, find the length of the longest substring without duplicate characters.

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
// Constraints:
// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.