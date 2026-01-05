#include <bits/stdc++.h>


//----------------------------------------Approach--TC->O(m × n)--------------------------------------------
std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> result;
    int top = 0;
    int right = matrix[0].size() - 1;
    int left = 0;
    int bottom = matrix.size() - 1;

    //!note the while purpose is , first to go straight then reverse the order also
    while(top <= bottom && left <= right){
        // For colums to push and row i.e. top to move ahead
        for(int i = left; i <= right; i++){
            result.push_back(matrix[top][i]);
        }
        top++;
        // For rows to push from backwards and columns i.e. right to move behind
        for(int i = top; i <= bottom; i++){
            result.push_back(matrix[i][right]);
        }
        right--;
        
        // Check if there are rows remaining
        if(top <= bottom){
            // Traverse from right to left on the bottom row
            for(int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--; // Move bottom boundary up //! Because top cannot move ahead , due to we need the symetric result 
        }
        // Check if there are columns remaining
        if(left <= right){
            // Traverse from top to bottom from the left column
            for(int i = bottom; i >=top; i--){
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return result;
}

int main(){
    std::vector<std::vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    // int result = maxSubArray(arr);
    // std::cout << "Result: " << result << std::endl;
    std::vector<int> result = spiralOrder(arr);
    for(int i = 0; i<result.size(); i++){
        std::cout << result[i] << ", ";
    }

    return 0;
}

// 54. Spiral Matrix

// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100