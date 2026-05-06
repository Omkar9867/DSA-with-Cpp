#include <bits/stdc++.h>

//------------------------------------Brute Force --TC->O(K^2)-------------------------------------
// int maxScore(std::vector<int>& cardPoints, int k) {
//     int n = cardPoints.size();
//     int maxSum = 0;

//     for (int i = 0; i <= k; i++) {
//         int tempSum = 0;

//         // Sum of i cards from the front
//         for (int j = 0; j < i; j++) {
//             tempSum += cardPoints[j];
//         }

//         // Sum of (k - i) cards from the back
//         for (int j = 0; j < k - i; j++) {
//             tempSum += cardPoints[n - 1 - j];
//         }
//         maxSum = std::max(maxSum, tempSum);
//     }

//     return maxSum;
// }

//------------------------------------Optimal Approach --TC->O(K)-------------------------------------
int maxScore(std::vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int total = 0;

    for (int i = 0; i < k; ++i) {
        total += cardPoints[i];
    }

    int maxPoints = total;

    for (int i = 0; i < k; ++i) {
        // Subtract card from front
        total -= cardPoints[k - 1 - i];

        // Add card from back
        total += cardPoints[n - 1 - i];

        // Update max score if needed
        maxPoints = std::max(maxPoints, total);
    }
    
    return maxPoints;
}

int main(){
    std::vector<int> nums = {1,2,3,4,5,6,1};
    int k = 3;

    int result = maxScore(nums, k);
    std::cout << "Result: " << std::endl;
    
    return 0;
}

// 1423. Maximum Points You Can Obtain from Cards

// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

// Example 1:
// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
// Output: 12
// Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

// Example 2:
// Input: cardPoints = [2,2,2], k = 2
// Output: 4
// Explanation: Regardless of which two cards you take, your score will always be 4.

// Example 3:
// Input: cardPoints = [9,7,7,9,7,7,9], k = 7
// Output: 55
// Explanation: You have to take all the cards. Your score is the sum of points of all cards.
 
// Constraints:
// 1 <= cardPoints.length <= 105
// 1 <= cardPoints[i] <= 104
// 1 <= k <= cardPoints.length