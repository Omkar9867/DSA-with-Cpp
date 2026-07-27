#include <bits/stdc++.h>

class Solution {
public:
//------------------------------------Approach--TC->O(NlogN)--SC->O(1)---------------------------------------
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] >= intervals[i][0]) {
                res.back()[1] = std::max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }

        return res;        
    }
};

int main(){
    Solution sol;
    std::vector<std::vector<int>> intervals = {{1,3},{6,9}};
    std::vector<std::vector<int>> result = sol.merge(intervals);
    return 0;
}

// 56. Merge Intervals

// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
// and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Example 1:
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

// Example 2:
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

// Example 3:
// Input: intervals = [[4,7],[1,4]]
// Output: [[1,7]]
// Explanation: Intervals [1,4] and [4,7] are considered overlapping.
 

// Constraints:
// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104