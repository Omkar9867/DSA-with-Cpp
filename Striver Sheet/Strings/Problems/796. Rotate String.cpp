#include <iostream>
#include <algorithm>

// ----------------My approach
bool rotateString(std::string s, std::string goal) {
    int indexNo;
    for (int i = 0; i < goal.size(); i++){
        if(s[0] == goal[i]){
            indexNo = i;
            break;
        }
    }
    int i = 0;
    std::reverse(s.begin(), s.end());
    std::reverse(s.begin(), s.begin() + indexNo);
    std::reverse(s.begin() + indexNo, s.end());
    
    if(s == goal){
        return true;
    }else{
        return false;
    }
}

int main(){
    std::string s = "abcde";
    std::string goal = "abced";
    bool result = rotateString(s, goal);

    std::cout << "Result for RotateString: '" << result << "'" << std::endl;
    return 0;
}


// 796. Rotate String

// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.
 
// Example 1:
// Input: s = "abcde", goal = "cdeab"
// Output: true

// Example 2:
// Input: s = "abcde", goal = "abced"
// Output: false
 
// Constraints:
// 1 <= s.length, goal.length <= 100
// s and goal consist of lowercase English letters.