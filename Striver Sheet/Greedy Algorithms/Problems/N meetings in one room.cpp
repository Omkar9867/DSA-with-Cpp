#include <bits/stdc++.h>

class Solution {
public:
//---------------------------Approach--TC->O(NlogN)-SC->O(N)-----------------------
// Sort meetings by end time so that the ones that finish earliest are considered first.

    std::vector<int> maxMeetings(std::vector<int>& start, std::vector<int>& end) {
        // Store meetings as (end_time, start_time, original_index)
        std::vector<std::tuple<int, int, int>> meetings;
        for (int i = 0; i < start.size(); i++) {
            meetings.push_back({end[i], start[i], i + 1}); 
           
        }

        // Sort by end time
        sort(meetings.begin(), meetings.end());

        std::vector<int> result; // To store meeting indices
        int lastEnd = -1;

        // Traverse sorted meetings
        for (auto& m : meetings) {
            int e = std::get<0>(m);
            int s = std::get<1>(m);
            int idx = std::get<2>(m);

            if (s > lastEnd) {
                result.push_back(idx); 
                lastEnd = e; 
            }
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
    std::vector<int> start = {1,3,0,5,8,5};
    std::vector<int> end = {2,4,5,7,9,9};
    std::vector<int> result = obj.maxMeetings(start, end);
    
    obj.printResult(result);

    return 0;
}

// N meetings in one room

// Problem Statement: There is one meeting room in a firm. You are given two arrays, 
// start and end each of size N. For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i] will denote the ending time of the ith meeting. 
// Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a particular time. Print the order in which these meetings will be performed.

// Examples
// 1.
// Input: N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}
// Output: [1, 2, 4, 5]
// Explanation: These meeting can be conducted in the room.

// 2.
// Input: N = 2, start[] = {1,5}, end[] = {7,8}
// Output: [1]
// Explanation: Any one out of the two meeting can take place.