#include <bits/stdc++.h>

//----------------------------------Brute Force Approach--TC->O(N^2)---------------------------
// TimeLimit--- Exceeds
int numberOfSubstrings(std::string s) {
    int count = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        std::vector<int> freq(3, 0);

        for (int j = i; j < n; j++) {
            freq[s[j] - 'a']++;

            // Check if all three characters are present
            if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                // Add valid substring count
                count++;
            }
        }
    }
    return count;
}

//----------------------------------Optimal Approach--TC->2(N)--SC->O(1)---------------------------
// int numberOfSubstrings(std::vector<int>& nums) {

// }

int main(){
    std::string s = "";
    int result = numberOfSubstrings(s);

    std::cout << "Result: " << result << std::endl;

    return 0;
}


// 1358. Number of Substrings Containing All Three Characters

// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

// Example 1:
// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

// Example 2:
// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

// Example 3:
// Input: s = "abc"
// Output: 1
 
// Constraints:
// 3 <= s.length <= 5 x 10^4
// s only consists of a, b or c characters.