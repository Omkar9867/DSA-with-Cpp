#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// -----------------------------------Loop Approach----------------------
// bool isPalindrome(string s){  // By two pointers approach we iterate only half of the 'n'
//     int st = 0, ed = s.length() - 1;
//     while(st < ed){
//         if(!isalnum(s[st])){  //is alpha numeric --> returns false if special charater
//             st++;
//         }else if(!isalnum(s[ed])){
//             ed--;
//         }else if(tolower(s[st]) != tolower(s[ed])){
//             return false;
//         }else{
//             st++;
//             ed--;
//         }
//     }
//     return true;
// }

//-----------------------------------Recursive Approach------------------------- //Note this approach doesnot support special charaters
bool isPalindrome(int i, string s){ // have a i to iterate from start
    // Iterate only till half of the string means all the elements 
    // are compared
    if(i >= s.length()/2){
        return true;
    }
    // condition to know if its not a palindrome
    if(tolower(s[i]) != tolower(s[s.length()-i-1])){
        return false;
    }
    return isPalindrome(i+1, s);
}

int main(){
    // bool result = isPalindrome("race a car");
    bool result = isPalindrome(0,"madam");
    cout << "Result : " << result << endl;
    
    return 0;
}



// 125. Valid Palindrome

// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward.
//  Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
 
// Constraints:
// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.