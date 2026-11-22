#include <bits/stdc++.h>

class Solution
{
public:
//-----------------------------TC->O(logn)-----------------------------
    int countFreq(std::vector<int> &arr, int target)
    {
        auto lb = lower_bound(arr.begin(), arr.end(), target);
        auto ub = upper_bound(arr.begin(), arr.end(), target);
        
        return ub - lb;
    }
};

/*
    Count Occurrences in Sorted
    Difficulty: MediumAccuracy: 59.34%Submissions: 440K+Points: 4Average Time: 20m
    Given a sorted array arr[] and a number target, find the number of occurrences of target in given array. 

    Examples:

    Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
    Output: 4
    Explanation: target = 2 occurs 4 times in the given array so the output is 4.
    Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
    Output: 0
    Explanation: target = 4 is not present in the given array so the output is 0.
    Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
    Output: 3
    Explanation: target = 12 occurs 3 times in the given array so the output is 3.
    Constraints:

    1 ≤ arr.size(), arr[i], target ≤ 106

*/