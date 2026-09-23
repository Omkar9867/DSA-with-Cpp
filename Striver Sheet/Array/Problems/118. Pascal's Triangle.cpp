#include <bits/stdc++.h>

class Solution {
private:
    // Returns one value from Pascal's Triangle.
    int valueAt(int row, int col) {
        // Boundary values are always 1.
        if (col == 0 || col == row) {
            return 1;
        }

        // Add the two values directly above the current cell.
        return valueAt(row - 1, col - 1) + valueAt(row - 1, col);
    }

public:
    // -----------------------------Brute Force---TC->O(2^n)--SC->O(N)---------------------------------
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle;

        // Build every requested row from top to bottom.
        for (int row = 0; row < numRows; row++) {
            std::vector<int> current;

            // Compute every cell in this row independently.
            for (int col = 0; col <= row; col++) {
                current.push_back(valueAt(row, col));
            }

            triangle.push_back(current);
        }

        return triangle;
    }

    //------------------------------Optimal Solution---TC->O(N^2)--SC->O(N)---------------------------
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle;

        for (int row = 0; row < numRows; row++) {
            std::vector<int> current(row+1, 1);

            for (int col = 1; col < row; col++) {
                current[col] = triangle[row-1][col-1] + triangle[row-1][col];
            }

            triangle.push_back(current);
        }

        return triangle;
    }
};

// Prints a triangle in list form.
void printTriangle(const std::vector<std::vector<int>>& triangle) {
    std::cout << "[";

    int rowCount = triangle.size();

    // Print each row in order.
    for (int row = 0; row < rowCount; row++) {
        std::cout << "[";

        int colCount = triangle[row].size();

        // Print every value in the current row.
        for (int col = 0; col < colCount; col++) {
            std::cout << triangle[row][col];

            // Add a separator between values in the same row.
            if (col + 1 < colCount) {
                std::cout << ", ";
            }
        }

        std::cout << "]";

        // Add a separator between completed rows.
        if (row + 1 < rowCount) {
            std::cout << ", ";
        }
    }

    std::cout << "]\n";
}

int main(){

    return 0;
}


// 118. Pascal's Triangle

// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Example 2:

// Input: numRows = 1
// Output: [[1]]
 

// Constraints:

// 1 <= numRows <= 30
 