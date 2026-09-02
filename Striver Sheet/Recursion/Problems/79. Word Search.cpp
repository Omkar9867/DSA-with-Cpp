#include <bits/stdc++.h>

class Solution {
private:
//!Undertand Carefully
    bool dfs(std::vector<std::vector<char>>& board, std::string& word, int i, int j, int idx) {
        if (idx == word.size()) return true; // If all char match -> true

        // Check boundaries and character match
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx]) {
            return false;
        }

        char temp = board[i][j]; // Store curr char as visited
        board[i][j] = '#';

        // Explore all four directions
        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                     dfs(board, word, i - 1, j, idx + 1) ||
                     dfs(board, word, i, j + 1, idx + 1) ||
                     dfs(board, word, i, j - 1, idx + 1);

        board[i][j] = temp;

        return found;
    }

public:
//----------------------------------Approach--TC->O(m * n * 4^L)--SC->O(L)------------------------------
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int rows = board.size(); // No. of rows
        int cols = board[0].size(); // No. of cols
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0)) { // Start DFS if first letter matches
                    return true;
                }
            }
        }
        // If no path found, return false
        return false;
    }
};

int main(){
    Solution sol;
    std::vector<std::vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    std::cout << "Result1 : " << sol.exist(board, "ABCCED") << std::endl; // true
    std::cout << "Result2 : " << sol.exist(board, "SEE") << std::endl;    // true
    std::cout << "Result3 : " << sol.exist(board, "ABCB") << std::endl;   // false
    return 0;
};


// 79. Word Search

// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
// The same letter cell may not be used more than once.

// Example 1:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true

// Example 2:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true

// Example 3:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 
// Constraints:
// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.
 
//* Follow up: Could you use search pruning to make your solution faster with a larger board?