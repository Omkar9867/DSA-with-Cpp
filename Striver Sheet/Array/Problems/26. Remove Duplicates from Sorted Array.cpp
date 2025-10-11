#include <iostream>
#include <vector>
#include <set>
using namespace std;

// -------------------------------------BruteForce Approach TC->O(n*logn)+O(n)-----SC->O(n)------------------

// int removeDuplicates(vector<int>& nums){
//     set <int> set;
//     int n = nums.size();
//     for(int i = 0; i < n; i++){
//         set.insert(nums[i]);
//     }
//     int k = set.size();
//     int j = 0;
//     for(int x: set){
//         nums[j++] = x;
//     }
//     return k;
// }

// ------------------------------- Optimal Approach TC-->O(n)------SC-->O(1)----------------------

int removeDuplicates(vector<int>& nums){
    int n = nums.size();
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (nums[i] != nums[j]) {
        i++;
        nums[i] = nums[j];
        }
    }
    return i + 1;
}

int main(){
    vector<int> arr = {1,1,2,2,2,3,3};
    int numOfDuplicates = removeDuplicates(arr);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ,";
    }
    cout << endl;
    cout << "No. of Duplicates: " << numOfDuplicates << endl;
    return 0;
}
//*basically keep the loop moving ahead until same when different from the i just assign the current element to the next position of i, 

// 26. Remove Duplicates from Sorted Array

// Hint
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
// The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. 
// The remaining elements of nums are not important as well as the size of nums.
// Return k.

// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length

// int k = removeDuplicates(nums); // Calls your implementation

// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

 

// Example 1:
// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Example 2:
// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).
 
// Constraints:
// 1 <= nums.length <= 3 * 104
// -100 <= nums[i] <= 100
// nums is sorted in non-decreasing order.