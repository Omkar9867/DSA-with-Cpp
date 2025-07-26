#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> nums){
    int count = 0, count2 = 0;
    for(int i=1; i<nums.size(); i++){
        if(nums[i] == 1){
            count2++;
            if(count < count2){
                count = count2;
            }
        }else{
            count2 = 0;
        }
    }
    return count;
}

int main(){
    vector<int> arr = {1,1,0,1,1,1};
    int result = findMaxConsecutiveOnes(arr);
    cout << "Result: " << result << endl;
    return 0;
}


// 485. Max Consecutive Ones
// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// Example 1:
// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

// Example 2:
// Input: nums = [1,0,1,1,0,1]
// Output: 2

// Constraints:
// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
