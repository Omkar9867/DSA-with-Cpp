#include <bits/stdc++.h>


class Solution {
public:
    //------------------------------Approach--TC->O(NlogN + N)--SC->(1)----------------------
    float calculateAverageWaitTime(std::vector<int>& jobs) {
        int n = jobs.size();

        std::sort(jobs.begin(), jobs.end());

        //cumulative waiting time
        float waitTime = 0;  
        int totalTime = 0;

        for (int i = 0; i < n; i++) {
            waitTime += totalTime;  // Add current total time to waiting time
            totalTime += jobs[i];   // Execute current job
        }

        // Return the average
        return waitTime / n;
    }
};

int main() {
    std::vector<int> jobs = {4, 3, 7, 1, 2};

    Solution sol;
    float ans = sol.calculateAverageWaitTime(jobs);

    std::cout << "Average waiting time: " << ans << std::endl;
    return 0;
}


// Shortest Job First (or SJF) CPU Scheduling

// Problem Statement: Given a list of job durations representing the time it takes to complete each job. 
// Implement the Shortest Job First algorithm to find the average waiting time for these jobs.

// Examples

// Example 1:
// Input:jobs = [3, 1, 4, 2, 5]
// Output: 4           
// Explanation:  
// The first job that will be executed is of duration 1 and the waiting time for it will be 0.
// After the first job, the next shortest job with a duration of 2 will be executed with a waiting time of 1.
// Following the completion of the first two jobs, the next shortest job with a duration of 3 will be executed with a waiting time of 3 (1 + 2).
// Then, the job with a duration of 4 will be executed with a waiting time of 6 (1 + 2 + 3).
// Finally, the job with the longest duration of 5 will be executed with a waiting time of 10 (1 + 2 + 3 + 4). Hence, the average waiting time is calculated as (0 + 1 + 3 + 6 + 10) / 5 = 20 / 5 = 4.


// Example 2:
// Input: jobs = [4, 3, 7, 1, 2]
// Output: 4
// Explanation: The first job that will be executed is of duration 1, and the waiting time for it will be 0.       
// After the first job, the next shortest job with a duration of 2 will be executed with a waiting time of 1.
// Following the completion of the first two jobs, the next shortest job with a duration of 3 will be executed with a waiting time of 3 (1 + 2).
// Then, the job with a duration of 4 will be executed with a waiting time of 6 (1 + 2 + 3).
// Finally, the job with the longest duration of 7 will be executed with a waiting time of 10 (1 + 2 + 3 + 4).
// Hence, the average waiting time is calculated as (0 + 1 + 3 + 6 + 10) / 5 = 20 / 5 = 4.
