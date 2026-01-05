#include <bits/stdc++.h>

//--------------------------------Brute Force Approach--TC->O(N^2)--SC->O(N^2)--------------------------------
// void rotate(std::vector<std::vector<int>>& matrix) {
//     int n = matrix.size();

//     //New matrix
//     std::vector<std::vector<int>> rotatedMatrix(n, std::vector<int>(n));

//     // Traverse each element of original matrix
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             // Place the element at its new rotated position
//             rotatedMatrix[j][n - i - 1] = matrix[i][j]; //?For every iteration the jth value in other arr-matrix, so the jth postion can be the jth matrix where the value lies
//         }//!This is the algorithm to remember
//     }

//     matrix = rotatedMatrix;
// }


//--------------------------------Optimal Approach--TC->O(N^2)--SC->O(1)--------------------------------
//* Approach : 1st Transpose the matrix, swap them diagonally, 2nd reverse each col. this will give you exact 90 degree rotation result 
void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){ // transpose technique
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
    // reverse it
    for(int i = 0; i < n; i++){
        std::reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(){
    std::vector<std::vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    // std::cout << "Size: " << arr.size() << std::endl;
    rotate(arr);
    for (auto row : arr) {
        for (auto val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

// 48. Rotate Image

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

// Example 2:
// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

// Constraints:
// n == matrix.length == matrix[i].length
// 1 <= n <= 20
// -1000 <= matrix[i][j] <= 1000