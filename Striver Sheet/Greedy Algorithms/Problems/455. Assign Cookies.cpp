#include <bits/stdc++.h>

class Solution {
private:
//!understand well
    int helper(int studentIndex, int cookieIndex, std::vector<int>& student, std::vector<int>& cookie, std::vector<std::vector<int>>& memo) {
        // Base case: if we reach end of either list
        if (studentIndex >= student.size() || cookieIndex >= cookie.size())
            return 0;

        if (memo[studentIndex][cookieIndex] != -1)
            return memo[studentIndex][cookieIndex];

        int result = 0;

        // If the cookie satisfies the student's greed
        if (cookie[cookieIndex] >= student[studentIndex]) {
            // Option 1: assign this cookie and move to next student and cookie
            result = std::max(result, 1 + helper(studentIndex + 1, cookieIndex + 1, student, cookie, memo));
        }

        // Option 2: skip this cookie and try the next one for the same student
        result = std::max(result, helper(studentIndex, cookieIndex + 1, student, cookie, memo));

        // Store the result in memo table
        return memo[studentIndex][cookieIndex] = result;
    }

public:
//*-----------------------------Memoization-----------------------------
//---------------------------TC->O(n*m)-SC->O(n*m)-----------------------
    // int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    //     std::sort(g.begin(), g.end());
    //     std::sort(s.begin(), s.end());

    //     // Initialize DP table with -1
    //     std::vector<std::vector<int>> memo(g.size(), std::vector<int>(s.size(), -1));

    //     // Start recursion from index 0 for both arrays
    //     return helper(0, 0, g, s, memo);
    // }

    // void printResult(int num){
    //     std::cout << num << ": Result" << std::endl;
    // }

//*-----------------------------Tabulation-----------------------------
//---------------------------TC->O(n*m)-SC->O(n*m)-----------------------
    // int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    //     int n = g.size();
    //     int m = s.size();

    //     // Sort both arrays to prepare for DP
    //     std::sort(g.begin(), g.end());
    //     std::sort(s.begin(), s.end());

    //     // Create a 2D DP table
    //     std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    //     // Fill DP table from bottom up
    //     for (int i = n - 1; i >= 0; --i) {
    //         for (int j = m - 1; j >= 0; --j) {
    //             // Skip current s
    //             int skip = dp[i][j + 1];

    //             // Take current s if it satisfies g's greed
    //             int take = 0;
    //             if (s[j] >= g[i]) {
    //                 take = 1 + dp[i + 1][j + 1];
    //             }

    //             // Take the best of both choices
    //             dp[i][j] = std::max(skip, take);
    //         }
    //     }

    //     return dp[0][0];
    // }


//*-----------------------------Optimal Approach-----------------------------
//---------------------------TC->O(n*logn + m*logm)--SC->O(1)-----------------------
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        int gIdx = 0; 
        int sIdx = 0;  

        // Try to assign cookies until any one list is fully processed
        while (gIdx < g.size() && sIdx < s.size()) {
            // If the cookie satisfies the student's greed
            if (s[sIdx] >= g[gIdx]) {
                gIdx++; 
            }
            // Move to next cookie in both cases
            sIdx++; 
        }

        // Number of students satisfied is equal to gIdx
        return gIdx;
    }

    void printResult(int num){
        std::cout << num << ": Result" << std::endl;
    }

};

int main(){
    Solution obj;
    std::vector<int> g = {'A','A','A','B','B','B'};
    std::vector<int> s = {'A','A','A','B','B','B'};
    int n = 2;   
    int result = obj.findContentChildren(g, s);
    
    obj.printResult(result);

    return 0;
}

// 455. Assign Cookies

// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j].
// If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. 
// Your goal is to maximize the number of your content children and output the maximum number.

// Example 1:
// Input: g = [1,2,3], s = [1,1]
// Output: 1
// Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
// And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
// You need to output 1.

// Example 2:
// Input: g = [1,2], s = [1,2,3]
// Output: 2
// Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
// You have 3 cookies and their sizes are big enough to gratify all of the children, 
// You need to output 2.
 

// Constraints:
// 1 <= g.length <= 3 * 104
// 0 <= s.length <= 3 * 104
// 1 <= g[i], s[j] <= 231 - 1
 
// !Note: This question is the same as 2410: Maximum Matching of Players With Trainers.

