#include <bits/stdc++.h>

class Solution{
private:

public:
//----------------------------------Optimal Approach--------------------------
//-------------------------------Expand Around Center Approach--------------------
    int countSubstrings(std::string s) {
        int n = s.size();

        int count = 0;
        auto expand = [&](int left, int right){
            while(left >= 0 && right < n && s[left] == s[right]){
                count++;
                left--;
                right++;
            }
        };
        for(int i = 0; i < n; i++){
            expand(i, i); // Odd-length palindrome: "aba"
            expand(i, i+1); // Even-length palindrome: "abba"
        }
        return count;
    }

};

int main(){
    Solution sol;
    std::string s = "abc";
    int result = sol.countSubstrings(s);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

// 647. Palindromic Substrings

// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

// Example 1:
// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Example 2:
// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 
// Constraints:
// 1 <= s.length <= 1000
// s consists of lowercase English letters.