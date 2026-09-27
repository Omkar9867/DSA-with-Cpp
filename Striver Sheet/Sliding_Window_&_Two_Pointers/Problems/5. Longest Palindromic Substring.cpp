#include <bits/stdc++.h>

//----------------------------------Optimal Approach--TC->O(N^2)--SC->O(1)---------------------------
//----------------------------------Expand Around Center Approach----------------------------------
std::string longestPalindrome(std::string& s) {
    int n = s.size();
    if(n < 2){
        return s;
    }

    int start = 0, maxLen = 1;
    auto expand = [&](int left, int right){
        while(left >= 0 && right < n && s[left] == s[right]){
            left--;
            right++;
        }
        int len = right - left - 1;
        if(len > maxLen){
            maxLen = len;
            start = left + 1;
        }
    };
    for (int i = 0; i < n; i++) {
        // Odd-length palindrome: "aba"
        expand(i, i);

        // Even-length palindrome: "abba"
        expand(i, i + 1);
    }
    return s.substr(start, maxLen);
}


int main(){
    std::string s = "babad";
    std::string result = longestPalindrome(s);

    std::cout << "Result: " << result << std::endl;

    return 0;
}

// 5. Longest Palindromic Substring

// Given a string s, return the longest palindromic substring in s.

// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:
// Input: s = "cbbd"
// Output: "bb"
 
// Constraints:
// 1 <= s.length <= 1000
// s consist of only digits and English letters.