#include <bits/stdc++.h>

//----------------------------------Brute Force Approach--TC->O(N^2)---------------------------
int characterReplacement(std::string& s, int k) {
    int maxLength = 0;
    
    for (int i = 0; i < s.length(); i++) {
        
        std::vector<int> freq(26, 0);
        
        // Track max frequency character in the current substring
        int maxFreq = 0;
        
        for (int j = i; j < s.length(); j++) {
            
            freq[s[j] - 'A']++;
            
            maxFreq = std::max(maxFreq, freq[s[j] - 'A']);
            
            // Calculate total length of current substring
            int windowLength = j - i + 1;
            
            int replace = windowLength - maxFreq;
            
            if (replace <= k) {
                maxLength = std::max(maxLength, windowLength);
            }
        }
    }
    
    return maxLength;
}

//----------------------------------Optimal Approach--TC->O(N)--SC->O(N)---------------------------
// int characterReplacement(std::string& s, int k) {

// }

//----------------------------------Optimal Approach2--TC->O(N)--SC->O(N)---------------------------
int characterReplacement(std::string& s, int k) {
    
}

int main(){
    std::string s = "ABAB";
    int k = 3;
    int result = characterReplacement(s, k);

    std::cout << "Result: " << result << std::endl;

    return 0;
}


// 424. Longest Repeating Character Replacement

// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character.
// You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// Example 1:
// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.

// Example 2:
// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.
 
// Constraints:
// 1 <= s.length <= 105
// s consists of only uppercase English letters.
// 0 <= k <= s.length
