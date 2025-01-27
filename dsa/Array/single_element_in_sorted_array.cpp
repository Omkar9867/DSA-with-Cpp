#include <iostream>
#include <vector>
using namespace std;

// int singleNonDuplicate(vector<int>& nums) {
//     int st = 0, ed = nums.size() - 1;
//     while(st <= ed){
//         int mid = st + (ed - st) / 2;
//         if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]){
//             return nums[mid];
//         }
//         else{
//             if(nums[mid] == nums[mid -1]){
//                 //We add or subract 1 element with mid is to see the count excluding the same number of the mid
//                 if((mid - 1) % 2 == 0){
//                     st = mid + 1;
//                 }else{
//                     ed = mid - 1;
//                 }
//             }else{
//                 if((mid + 1) % 2 == 0){  //(ed-(mid+1) % 2)
//                     ed = mid - 1;
//                 }else{
//                     st = mid + 1;
//                 }
//             }
//         }
//     }
//     return -1;
// }

// Updated approach with SC O(1)

// Check whether the L&R sides are odd or even length by mid % 2 depends on mid if even or odd.
// Also will handle if the mid is in the start i.e. 0 or end i.e. end-1
int singleNonDuplicate(vector<int> &nums){
    int n = nums.size();
    if (n == 1)
        return nums[0]; // return the 1st index only
    int st = 0, ed = n - 1;
    while (st <= ed){
        int mid = st + (ed - st) / 2;

        if (mid == 0 && nums[0] != nums[1]) return nums[mid]; // if the mid is first index
        if (mid == n - 1 && nums[n - 1] != nums[n - 2]) return nums[mid]; // if the mid is last index

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return nums[mid]; // main condition

        if (mid % 2 == 0){ // Even case
            if (nums[mid - 1] == nums[mid]){ // if match with L side then it will become odd length so to search in left side else right side
                ed = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        else { // Odd case
            if (nums[mid - 1] == nums[mid]){ // if match with L side then it will become even length so to search in right side else left side
                st = mid + 1;
            }else{
                ed = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> num = {3, 3, 7, 7, 10, 10, 11, 12, 12};
    int number = singleNonDuplicate(num);
    cout << "The single number is: " << number << endl;

    return 0;
}

//  Single Element in a Sorted Array
// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.
// Your solution must run in O(log n) time and O(1) space.

// Example 1:
// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2

// Example 2:
// Input: nums = [3,3,7,7,10,11,11]
// Output: 10

// Constraints:
// 1 <= nums.length <= 105
// 0 <= nums[i] <= 105

// Since it is a sorted array we'll first think of solving it using binary approach. Also the TC is O(logn).

// Logic here is that we have to see that if the middle number is same from the left side then excluding it the total number counts are even or not
// If it is odd then we'll know that ans is in left side. Because since everyone are in pairs there has to be odd between the count
// Same goes for right side