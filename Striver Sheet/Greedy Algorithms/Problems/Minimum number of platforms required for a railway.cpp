#include <bits/stdc++.h>

class Solution {
private:

public:
//-----------------------Brute Force Approach----TC->O(N^2)-SC->O(1)-----------------------
    int countPlatforms(std::vector<int>& arr, std::vector<int>& dep) {
        int n = sizeof(arr) / sizeof(arr[0]);
        int ans = 1;

        for (int i = 0; i < n; i++) {

            int count = 1;

            // Check overlap with every other train
            for (int j = i + 1; j < n; j++) {

                // Check if there is overlap between train i and j
                if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                    (arr[j] >= arr[i] && arr[j] <= dep[i])) {
                    count++;
                }
            }

            ans = std::max(ans, count);
        }

        return ans;
    }


//-----------------------Better Approach----TC->O(N^2)-SC->O(N)-----------------------
    // int countPlatforms(std::vector<int>& arr, std::vector<int>& dep) {

    // }


//*-----------------------------Optimal Approach-----------------------------
//---------------------------TC->O(N)--SC->O(1)-----------------------
    // int countPlatforms(std::vector<int>& arr, std::vector<int>& dep) {

    // }

    void printResult(int num){
        std::cout << num << ": Result" << std::endl;
    }

};

int main(){
    Solution obj;
    std::vector<int> arr = {900, 945, 955, 1100, 1500, 1800};
    std::vector<int> dep = {920, 1200, 1130, 1150, 1900, 2000};
    int n = 2;   
    int result = obj.countPlatforms(arr, dep);
    
    obj.printResult(result);

    return 0;
}


// Minimum number of platforms required for a railway

// Problem Statement: We are given two arrays that represent the arrival and departure times of trains that stop at the platform. 
// We need to find the minimum number of platforms needed at the railway station so that no train has to wait.

// Examples
// Input:  N=6, 
// arr[] = {9:00, 9:45, 9:55, 11:00, 15:00, 18:00}
// dep[] = {9:20, 12:00, 11:30, 11:50, 19:00, 20:00}
// Output: 3
// Explanation: There are at-most three trains at a time. The train at 11:00 arrived but the trains which had arrived at 9:45 and 9:55 have still not departed. So, we need at least three platforms here.

// Input : N=2, 
// arr[]={10:20,12:00}
// dep[]={10:50,12:30}
// Output: 1
// Explanation : Before the arrival of the new train, the earlier train already departed. So, we don't require multiple platforms.