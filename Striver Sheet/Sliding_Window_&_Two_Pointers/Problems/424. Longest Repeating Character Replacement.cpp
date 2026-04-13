#include <bits/stdc++.h>

//----------------------------------Brute Force Approach--TC->O(N^2)---------------------------
// int characterReplacement(std::string& s, int k) {
//     int maxLength = 0;
    
//     for (int i = 0; i < s.length(); i++) {
        
//         std::vector<int> freq(26, 0);
        
//         // Track max frequency character in the current substring
//         int maxFreq = 0;
        
//         for (int j = i; j < s.length(); j++) {
            
//             freq[s[j] - 'A']++;
            
//             maxFreq = std::max(maxFreq, freq[s[j] - 'A']);
            
//             // Calculate total length of current substring
//             int windowLength = j - i + 1;
            
//             int replace = windowLength - maxFreq; // We subtract to see the difference of the different char and 
            
//             if (replace <= k) {
//                 maxLength = std::max(maxLength, windowLength);
//             }
//         }
//     }
    
//     return maxLength;
// }

//----------------------------------Optimal Approach--TC->O(N)--SC->O(1)---------------------------
int characterReplacement(std::string& s, int k) {
    std::vector<int> freq(26, 0);
    int l = 0, maxFreq = 0, maxLen = 0;
    for (int r = 0; r < s.size(); r++) {
        freq[s[r] - 'A']++;
        maxFreq = std::max(maxFreq, freq[s[r] - 'A']);

        while(((r - l + 1) - maxFreq) > k) {
            freq[s[l] - 'A']--;
            l++;
        }

        maxLen = std::max(maxLen, r - l + 1);
    }
    return maxLen;
}

//----------------------------------Optimal Approach2--TC->O(N)--SC->O(1)---------------------------
// int characterReplacement(std::string& s, int k) {
    // std::vector<int> freq(26, 0);
    // int l = 0, maxFreq = 0, maxLen = 0;
    // for (int r = 0; r < s.size(); r++) {
    //     freq[s[r] - 'A']++;
    //     maxFreq = std::max(maxFreq, freq[s[r] - 'A']);

    //     if (((r - l + 1) - maxFreq) > k) {
    //         freq[s[l] - 'A']--;
    //         l++;
    //     }

    //     maxLen = std::max(maxLen, r - l + 1);
    // }
    // return maxLen;
// }

int main(){
    std::string s = "AABABBA";
    int k = 1;
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
