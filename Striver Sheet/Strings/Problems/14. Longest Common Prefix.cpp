#include <iostream>

std::string longestCommonPrefix(std::string strs[], int n) {
    std::string result = strs[0];
    for(int i = 1; i < n; i++){
        std::string val = strs[i];
        int minLength = std::min(result.length(), val.length());
        std::string temp = "";
        for(int j = 0; j < minLength; j++){
            if(val[j] == result[j]){
                temp += result[j];
            }else{
                break; // This condition is important, as longestprefix will be true when it is in the result without skipping any letter
            }
        }
        result = temp;
    }
    return result;
}

int main(){
    std::string inputArr[] = {"cir","car"};
    // std::string inputArr[] = {"flower","flow","flight"};
    // std::string inputArr[] = {"dog","racecar","car"};
    int n = 2;
    std::string result = longestCommonPrefix(inputArr, n);

    std::cout << "Result for longest common prefix: '" << result << "'" << std::endl;
    return 0;
}

// 14. Longest Common Prefix

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""

// Explanation: There is no common prefix among the input strings.
 
// Constraints:

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lowercase English letters if it is non-empty.