#include <iostream>

bool isIsomorphic(std::string s, std::string t) {
    int n = s.size();
    int m1[256] = {0}, m2[256] = {0}; //For storing the array of of characted of s and t
    for(int i = 0; i< n; i++){
        if(m1[s[i]] != m2[t[i]]){
            return false;
        }
        m1[s[i]] = i+1;
        m2[t[i]] = i+1;
    }
    return true;
}

int main(){
    std::string s = "egg";
    std::string t = "add";
    bool result = isIsomorphic(s, t);

    std::cout << "Result for IsIsomorphic: '" << result << "'" << std::endl;
    return 0;
}


// 205. Isomorphic Strings

// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. 
// No two characters may map to the same character, but a character may map to itself.

 

// Example 1:
// Input: s = "egg", t = "add"
// Output: true
// Explanation:
// The strings s and t can be made identical by:
// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.

// Example 2:
// Input: s = "foo", t = "bar"
// Output: false
// Explanation:
// The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

// Example 3:
// Input: s = "paper", t = "title"
// Output: true


// Constraints:

// 1 <= s.length <= 5 * 104
// t.length == s.length
// s and t consist of any valid ascii character.


// 🧮 Example 1: "egg" vs "add"
// i	s[i]	t[i]	m1[s[i]]	m2[t[i]]	Equal?	Action
// 0	'e' 	'a' 	    0          0	    ✅ yes	m1['e']=1, m2['a']=1
// 1	'g' 	'd' 	    0          0	    ✅ yes	m1['g']=2, m2['d']=2
// 2	'g' 	'd' 	    2          2	    ✅ yes	m1['g']=3, m2['d']=3

// No mismatches → returns true.

// 🧮 Example 2: "foo" vs "bar"
// i	s[i]	t[i]	m1[s[i]]	m2[t[i]]	Equal?	Action
// 0	'f' 	'b' 	    0          0	    ✅ yes	m1['f']=1, m2['b']=1
// 1	'o' 	'a' 	    0          0	    ✅ yes	m1['o']=2, m2['a']=2
// 2	'o' 	'r' 	    2          0	    ❌ no	return false