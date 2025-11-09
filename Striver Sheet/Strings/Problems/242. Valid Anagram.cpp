#include <iostream>
#include <algorithm>


// bool isAnagram(std::string s, std::string t) {
//     int n1 = s.length(), n2 = t.length();
//     if(n1 != n2){
//         return false;
//     }
//     int m1[256] = {0}, m2[256] = {0};
//     // insert all the s characters in an array
//     for(int i = 0; i<n1; i++){
//         m1[s[i]] += 1;
//     }
//     // insert all the t characters and simultaneously compare
//     for(int i = 0; i<n2; i++){
//         m2[t[i]] += 1;
//     }
//     for(int i = 0; i<n2; i++){
//         std::cout << m1[t[i]] << " ==> " << m2[t[i]] << std::endl;
//         if(m1[t[i]] != m2[t[i]]){
//             return false;
//         }
//     }
//     return true;
// }

// -----------------------------For Space complexity O(1)----------------------------
bool isAnagram(std::string s, std::string t) {
    int n1 = s.length(), n2 = t.length();
    if(n1 != n2){
        return false;
    }
    // int freq[26] = {0}; //! Out of bond error
    int freq[256] = {0};
    // insert all the s characters in an array
    for(int i = 0; i<n1; i++){
        freq[s[i] - 'A']++ ;
    }
    // insert all the t characters and simultaneously compare
    for(int i = 0; i<n2; i++){
        freq[t[i] - 'A']--;
    }
    // Since we iterate through each letter and it should nullify i.e. 0 to each character after 2nd loop , if not then one ch left and not anagram
    for(int i = 0; i< 26; i++){
        if(freq[i] != 0){
            return false;
        }
    }
    return true;
}

int main(){
    std::string s = "anagram";
    std::string t = "nagaram";
    bool result = isAnagram(s, t);

    std::cout << "Result for IsAnagram: '" << result << "'" << std::endl;
    return 0;
}

// 242. Valid Anagram
// An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.
 