#include <bits/stdc++.h>

class Solution {
public:
//-----------------------------Brute Force Approach--TC->O(N2^N)------------------------
    std::vector<std::string> getSubsequences(std::string s) {
        int n = s.size();

        // Total subsequences = 2^n
        int total = 1 << n;

        // Vector to store all subsequences
        std::vector<std::string> subsequences;

        for (int mask = 0; mask < total; mask++) { //Iterating (2^n -1)
            // Temp
            std::string subseq = "";

            // Check each bit position in mask
            for (int i = 0; i < n; i++) {
                // If i-th bit of mask is set, include s[i]
                if (mask & (1 << i)) {
                    subseq += s[i];
                }
            }
            subsequences.push_back(subseq);
        }
        return subsequences;
    }

//---------------------------------Optimal Solution---------------------------------------
    void helper(std::string &s, int index, std::string current, std::vector<std::string> &result) {
        // Base case: If index reaches string length, add current subsequence to result
        if (index == s.size()) {
            result.push_back(current);
            return;
        }

        // Exclude current character and recurse
        helper(s, index + 1, current, result);

        // Include current character and recurse
        current.push_back(s[index]);
        helper(s, index + 1, current, result);

        // Backtrack: remove last character before returning to previous call
        current.pop_back();
    }

    std::vector<std::string> getSubsequences(std::string s) {
        std::vector<std::string> result;  
        
        std::string current = "";    
        helper(s, 0, current, result);
        return result;
    }

};

int main() {
    Solution sol;

    std::string s = "abc";
    std::vector<std::string> subsequences = sol.getSubsequences(s);

    for (auto &subseq : subsequences) {
        std::cout << "\"" << subseq << "\"" << std::endl;
    }

    return 0;
}



// Power Set: Print all the possible subsequences of the String

// Problem Description: Given a string, find all the possible subsequences of the string.

// Examples
// Input: str = "abc"
// Output: [a, ab, abc, ac, b, bc, c]
// Explanation: Given string has 7 subsequences.

// Input: str = "aa"
// Output: [a, a, aa] 
// Explanation: Given string has 3 subsequences.