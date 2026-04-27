#include <bits/stdc++.h>

//----------------------------------Brute Force Approach--TC->O(N^2)---------------------------
// TimeLimit--- Exceeds
// int numberOfSubstrings(std::string s) {
//     int count = 0;
//     int n = s.length();

//     for (int i = 0; i < n; i++) {
//         std::vector<int> freq(3, 0);

//         for (int j = i; j < n; j++) {
//             freq[s[j] - 'a']++;

//             // Check if all three characters are present
//             if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
//                 // Add valid substring count
//                 count++;
//             }
//         }
//     }
//     return count;
// }

//----------------------------------Optimal Approach--TC->O(N)--SC->O(1)---------------------------
// !Understand properly
// int numberOfSubstrings(std::string s) {
//     // Initialize frequency map for 'a', 'b', and 'c'
//     std::vector<int> freq(3, 0);

//     int result = 0;

//     int left = 0;

//     for (int right = 0; right < s.length(); right++) {
//         freq[s[right] - 'a']++;

//         while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
//             result += (s.length() - right);

//             // Decrease frequency of character at left and move left forward
//             freq[s[left] - 'a']--;
//             left++;
//         }
//     }

//     return result;
// }

//----------------------------------More Optimal Approach--TC->O(N)--SC->O(1)---------------------------
int numberOfSubstrings(std::string s) {
    std::vector<int> lastSeen = {-1, -1, -1};

    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        lastSeen[s[i] - 'a'] = i; // To assign the index number to the position if char
        // If 3 of them have values then only increase count.
        if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
            count = count + (1 + std::min(lastSeen[0], std::min(lastSeen[1], lastSeen[2]))); // if -1 is min then (+1-1)
        }
    }
    return count;
}

int main(){
    std::string s = "abcabc";
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