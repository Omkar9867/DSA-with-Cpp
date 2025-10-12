#include <iostream>

std::string reverseWords(std::string s) {
    int n = s.size();
    std::string temp;
    std::string result;
    int balance = 0;
    int left = 0, right = n - 1;
    while(left <= right){
        if(s[left] != ' '){
            temp += s[left];
            balance = 0;
        }else if(s[left] == ' '){
            if(balance == 0){
                if(result != ""){
                    result = temp + ' ' + result;
                }else{
                    result = temp; // if the first one is space the result won't have the space as it was empty
                }
                temp = "";
                balance++;
            }
        }
        left++;
    }

    if(temp != ""){  // if the last one is space this condition will not come
        std::cout << "Temp : " << temp<< std::endl;
        if(result != ""){
            result = temp + ' ' + result;
        }else{
            result = temp;
        }
    }
    return result;
}

int main(){
    std::string inputArr = " a good   example  ";
    std::string result = reverseWords(inputArr);

    std::cout << "Result after words reversed: '" << result << "'" << std::endl;
    return 0;
}


// 151. Reverse Words in a String

// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. 
// The returned string should only have a single space separating the words. Do not include any extra spaces.

// Example 1:
// Input: s = "the sky is blue"
// Output: "blue is sky the"

// Example 2:
// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.

// Example 3:
// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

// Constraints:

// 1 <= s.length <= 104
// s contains English letters (upper-case and lower-case), digits, and spaces ' '.
// There is at least one word in s.

//! Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

 
