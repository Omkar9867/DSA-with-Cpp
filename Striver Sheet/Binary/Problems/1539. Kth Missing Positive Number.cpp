#include <bits/stdc++.h>

// -------------------------------------Brute Force Approach--TC->O(N)--SC->O(1)-----------------------------------O(n^2)
// int findKthPositive(std::vector<int>& arr, int k) {
//     int n = arr.size();
//     for(int i = 0; i<n; i++){
//         if(arr[i] <= k){
//             k++;
//         }else{
//             break;
//         }
//     }
//     return k;
// }
//*Key solution of brute force is, we know we have to return the kth non present value, and by iterating to all the numbers, we noticed the kth value increases it value by 1 when the number is present
//* Eg: 1,2,3,4,5,6,7 from [5, 7, 10] where k=6 ans is not 6 but seven , because when counting , the 5 took extra count because it skips due to existence


// -------------------------------------Optimal Approach--TC->O(logN)--SC->O(1)-----------------------------------
int findKthPositive(std::vector<int>& arr, int k) {
    int st = 0, ed = arr.size() - 1;
    while(st <= ed){
        int mid = st + (ed - st)/2;
        //How may are missing 
        int missing = arr[mid] - (mid+1);
        if(missing < k){
            st = mid + 1;
        }else{
            ed = mid - 1;
        }
    }   
    // arr[ed] -> We cannot do this, because finding the 2 num so the in between could be the answer may end up , have ed beyond arr. //  Basically in this cas we take low. but logic is below
    //Formula:
    // int missing = arr[ed] - (ed + 1); // Since we are in ed, find the missing number to difference with k same as the missing in loop
    // int more = (k-missing);
    // Looks like:
            // arr[ed] + (k - (arr[ed] - (ed + 1))) // - - == + for the brackets for - & -(ed + 1);
            // arr[ed] + (k - arr[ed] + ed + 1)) //* -+arr[ed] get canceld and remains -> 
    return k + ed + 1; // also said as (k + low) because ed + 1 is low logically when ed passed low 

}

//How may are missing [2,  3,  4,  7,  11]
//                     1,  2,  3,  4,  5   //* 7 - 4 is the ans that are missing
// How to find more to add is ==> k - missing i.e. 5 - 3 i.e 2 which will be added to the 7


int main(){
    std::vector<int> arr = {2,3,4,7,11};
    int d = 5;
    int result = findKthPositive(arr, d);
    std::cout<< "Result: " << result << std::endl;
    return 0;
}

// 1539. Kth Missing Positive Number

// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Return the kth positive integer that is missing from this array.

// Example 1:
// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

// Example 2:
// Input: arr = [1,2,3,4], k = 2
// Output: 6
// Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 

// Constraints:
// 1 <= arr.length <= 1000
// 1 <= arr[i] <= 1000
// 1 <= k <= 1000
// arr[i] < arr[j] for 1 <= i < j <= arr.length
 

//! Follow up:
//! Could you solve this problem in less than O(n) complexity?