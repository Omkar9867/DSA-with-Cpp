#include <bits/stdc++.h>

//-------------------------------------Brute Force Approach--TC->O(m * n * (m + n))--------------------
void setZeroes(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    // Traverse each cell of the matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // If current cell is zero
            if (matrix[i][j] == 0) {
                // Mark all elements in this row as -1 (except existing zeros)
                for (int col = 0; col < n; col++) {
                    if (matrix[i][col] != 0)
                        matrix[i][col] = -1;
                }
                // Mark all elements in this column as -1 (except existing zeros)
                for (int row = 0; row < m; row++) {
                    if (matrix[row][j] != 0)
                        matrix[row][j] = -1;
                }
            }
        }
    }
    // Second pass: replace all -1 markers with 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1)
                matrix[i][j] = 0;
        }
    }
}

int main(){
    std::vector<std::vector<int>> arr = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(arr);
    for (auto row : arr) {
        for (auto val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

// 73. Set Matrix Zeroes

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

// Example 1:
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

// Example 2:
// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

// Constraints:
// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1
 

// Follow up:

// A straightforward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?