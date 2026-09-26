#include <bits/stdc++.h>

class Solution {
public:
    //------------------------------Optimal Solution---TC->O(K^2)--SC->O(K)---------------------------
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> result(rowIndex+1, 1); //Pascal's Triangle row 4 has 5 numbers:

        for (int row = 1; row < rowIndex; row++) {
            for (int col = row; col > 0; col--) { // The key is iterating col backwards, so previous values aren't overwritten before they're used.
                result[col] = result[col] + result[col-1];  // Note result is updated every row loop 
            }
        }

        return result;
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


// 119. Pascal's Triangle II

// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Example 1:
// Input: rowIndex = 3
// Output: [1,3,3,1]

// Example 2:
// Input: rowIndex = 0
// Output: [1]

// Example 3:
// Input: rowIndex = 1
// Output: [1,1]
 
// Constraints:
// 0 <= rowIndex <= 33
 
//! Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?