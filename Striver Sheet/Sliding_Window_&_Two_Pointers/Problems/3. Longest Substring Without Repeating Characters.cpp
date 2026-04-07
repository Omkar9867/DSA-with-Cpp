#include <bits/stdc++.h>

//----------------------------------Brute Force Approach--TC->O(N^2)---------------------------
// int lengthOfLongestSubstring(std::string s) {
    //     int n = s.size(); 
    //     int maxLen = 0;    
    
    //     for (int i = 0; i < n; i++) {
        
//         // Hash to track characters in the current substring window
//         // Assuming extended ASCII characters
//         std::vector<int> hash(256, 0);  
        
//         for (int j = i; j < n; j++) {
    
//             /* If s[j] is already in the current substring window*/
//             if (hash[s[j]] == 1) break;  

//             /* Update the hash to mark s[j] as present in the current window*/
//             hash[s[j]] = 1;

//             /* Calculate the length of the current substring*/
//             int len = j - i + 1;

//             maxLen = std::max(maxLen, len);
//         }
//     }
//     return maxLen; 
// }

//----------------------------------Optimal Approach--TC->O(N)--SC->O(N)---------------------------
int lengthOfLongestSubstring(std::string s) {
    int n = s.size();

    int HashLen = 256; 
    int hash[HashLen]; 
    
    // Initialize hash table with -1 (indicating no occurrence)
    for (int i = 0; i < HashLen; ++i) {
        hash[i] = -1;
    }

    int l = 0, r = 0, maxLen = 0;
    while (r < n) { // Move right pointer to next position

        /* If current character s[r] is already in the substring*/
        if (hash[s[r]] != -1) {
            // Move left pointer to the right of the last occurrence of s[r]
            l = std::max(hash[s[r]] + 1, l);
        }
        int len = r - l + 1;
        
        // Update maximum length found so far
        maxLen = std::max(len, maxLen);
        
        // Store the index of the current character in the hash table
        hash[s[r]] = r;

        r++;
    }
    return maxLen;
}

int main(){
    std::string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);

    std::cout << "Result: " << result << std::endl;

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