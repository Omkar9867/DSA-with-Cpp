#include <bits/stdc++.h>

class Solution {
public:
//--------------------------------Brute Force Approach-TC->O(N^2)------------------------
//We are aiming to assign a rank to each element in the array based on how many unique elements are smaller than it. 
//For each element, we iterate through the rest of the array, collect all smaller elements, and count the number of distinct ones.
    // std::vector<int> arrayRankTransform(std::vector<int>& arr) {
    //     std::vector<int> rankArr;

    //     for (int i = 0; i < arr.size(); i++) {
    //         std::unordered_set<int> smaller; // Store unique elem

    //         for (int j = 0; j < arr.size(); j++) {
    //             if (arr[j] < arr[i]) {
    //                 // Add to set if element is smaller
    //                 smaller.insert(arr[j]);
    //             }
    //         }

    //         // Rank is number of unique smaller elements + 1
    //         int rank = smaller.size() + 1;

    //         // Store the rank
    //         rankArr.push_back(rank);
    //     }

    //     return rankArr;
    // }

//---------------------------Better Approach--TC->O(NlogN)-SC->O(N)-----------------------
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        std::vector<int> sortedArr = arr;

        sort(sortedArr.begin(), sortedArr.end());

        // Create a map to store rank of each unique number
        std::unordered_map<int, int> rankMap;

        int rank = 0;

        for (int num : sortedArr) {
            // If this number is not already assigned a rank
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }
        
        std::vector<int> result;
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }

        return result;
    }

    void printResult(std::vector<int> nums){
        for(auto num : nums){
            std::cout << num << ", " << std::endl;
        }
    }

};

int main(){
    Solution obj;
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    std::vector<int> result = obj.arrayRankTransform(nums);
    
    obj.printResult(result);

    return 0;
}


// 1331. Rank Transform of an Array

// Given an array of integers arr, replace each element with its rank.
// The rank represents how large the element is. The rank has the following rules:
// Rank is an integer starting from 1.
// The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
// Rank should be as small as possible.
 
// Example 1:
// Input: arr = [40,10,20,30]
// Output: [4,1,2,3]
// Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.

// Example 2:
// Input: arr = [100,100,100]
// Output: [1,1,1]
// Explanation: Same elements share the same rank.

// Example 3:
// Input: arr = [37,12,28,9,100,56,80,5,12]
// Output: [5,3,4,2,8,6,7,1,3]
 
// Constraints:
// 0 <= arr.length <= 105
// -109 <= arr[i] <= 109