#include <bits/stdc++.h>

class Solution {
public:

//---------------------------Approach--TC->O(NlogN)-SC->O(N)-----------------------
//!Understand Properly
    int leastInterval(std::vector<char>& tasks, int n) {
        // Step 1: Count frequency of each task
        std::unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }

        // Step 2: Use max heap to always pick task with highest frequency
        std::priority_queue<int> maxHeap;
        for (auto& entry : freq) {
            maxHeap.push(entry.second);
        }

        int time = 0;

        // Step 3: Process tasks in cycles of size (n + 1)
        while (!maxHeap.empty()) {
            // Store tasks executed in this cycle
            std::vector<int> temp;

            // Set number of tasks allowed in this cycle
            int cycle = n + 1;

            // Counter to track how many tasks we run in this cycle
            int i = 0;

            // Keep running tasks until cycle ends or heap gets empty
            while (i < cycle && !maxHeap.empty()) {

                // Get the most frequent remaining task
                int cnt = maxHeap.top();
                maxHeap.pop();

                // Reduce its count as we’re running it once
                cnt--;

                // If the task still has pending frequency, store it for later
                if (cnt > 0) {
                    temp.push_back(cnt);
                }

                // Count 1 unit of time for this task
                time++;

                // Move to next slot in the cycle
                i++;
            }

            // Step 4: Push leftover tasks of this cycle back into the heap
            for (int val : temp) {
                maxHeap.push(val);
            }

            // Step 5: If heap is empty, no need to count idle time
            if (maxHeap.empty()) break;

            // Step 6: Add idle time to complete the cycle (if any slots were left)
            time += (cycle - i);
        }

        // Return the total time needed
        return time;
    }

    void printResult(int num){
        std::cout << num << ": Result" << std::endl;
    }

};

int main(){
    Solution obj;
    std::vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;   
    int result = obj.leastInterval(tasks, n);
    
    obj.printResult(result);

    return 0;
}

// 621. Task Scheduler

// You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. 
// Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

// Return the minimum number of CPU intervals required to complete all tasks.

// Example 1:
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
// After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. 
// By the 4th interval, you can do A again as 2 intervals have passed.

// Example 2:
// Input: tasks = ["A","C","A","B","D","B"], n = 1
// Output: 6
// Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
// With a cooling interval of 1, you can repeat a task after just one other task.

// Example 3:
// Input: tasks = ["A","A","A", "B","B","B"], n = 3
// Output: 10
// Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B
// There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

// Constraints:
// 1 <= tasks.length <= 104
// tasks[i] is an uppercase English letter.
// 0 <= n <= 100