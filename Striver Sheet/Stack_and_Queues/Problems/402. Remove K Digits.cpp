#include <bits/stdc++.h>

//--------------------------------------Approach--------------------------
std::string removeKdigits(std::string num, int k) {
    std::stack<char> st;
    int count = 0;
    for(int i = 0; i < num.size(); i++){
        while(!st.empty() && k > 0 && st.top() > num[i]) { // Not everytime will top > digit
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    //! remove remaining digits from end
    while(k > 0 && !st.empty()){
        st.pop();
        k--;
    }

    if(st.empty()) return "0"; // edge case

    num = "";
    while(!st.empty()){
        num.push_back(st.top());
        st.pop();
    }
    // trim zeros from start
    while(num.size() > 0 && num.back() == '0'){
        num.pop_back();
    }
    std::reverse(num.begin(), num.end());
    if(num.empty()) return "0"; //! important case
    return num;
}

int main(){
    std::string num = "10200";
    int k = 1;

    std::string result = removeKdigits(num, k);
    std::cout << "Result: " << result << std::endl;

    return 0;
}


// 402. Remove K Digits

// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

// Example 1:
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

// Example 2:
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

// Example 3:
// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 
// Constraints:
// 1 <= k <= num.length <= 105
// num consists of only digits.
// num does not have any leading zeros except for the zero itself.