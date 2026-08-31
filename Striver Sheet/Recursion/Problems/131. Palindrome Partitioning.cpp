#include <bits/stdc++.h>

class Solution{
private:
    
    bool isPalindrome(std::string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void backtrack(int idx, std::string s, std::vector<std::string> &path, std::vector<std::vector<std::string>> &result){
        if(idx == s.length()){
            result.push_back(path);
            return;
        }
        for(int i = idx; i<s.length(); i++){
            if (isPalindrome(s, idx, i)) {
                path.push_back(s.substr(idx, i - idx + 1));
                backtrack(i + 1, s, path, result); // Since to start to recurse after the found plaindrome i.e i+1 for the next set
                path.pop_back();
            }
        }
    }

public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> path;
        backtrack(0, s, path, result);
        return result;
    }

};


int main() {
    Solution sol;
    std::string s = "aab";
    std::vector<std::vector<std::string>> ans = sol.partition(s);
    for (auto &vec : ans) {
        for (auto &str : vec)
            std::cout << str << " ";
        std::cout << std::endl;
    }
    return 0;
}

// 131. Palindrome Partitioning

// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// Example 1:
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

// Example 2:
// Input: s = "a"
// Output: [["a"]]
 
// Constraints:
// 1 <= s.length <= 16
// s contains only lowercase English letters.