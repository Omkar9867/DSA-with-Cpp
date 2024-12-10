#include <iostream>
#include <vector>
using namespace std;

// //My Approach by learning
// int binary_search(vector<int>sortedArr, int target){
//     int st = 0, ed = sortedArr.size() -1;
//     while(st <= ed) {
//         int mid = (st + ed) /2;
//         if(sortedArr[mid] > target){
//             ed = mid - 1;
//         }else if(sortedArr[mid] < target){
//             st = mid+1;
//         }else{
//             return mid;
//         }
//     }
//     return  -1;
// }

// --------------------------------------------TC - O(logn) ------------------------------------

// int binary_search(vector<int>sortedArr, int target){
//     int st = 0, ed = sortedArr.size() -1;
//     while(st <= ed) {
//         int mid = st + (ed - st) /2;
//         if(sortedArr[mid] > target){
//             ed = mid - 1; //1st Half
//         }else if(sortedArr[mid] < target){
//             st = mid+1; //2nd Half
//         }else{
//             return mid;
//         }
//     }
//     return  -1;
// }

// ------------------------------------Recurssion-Approach-----TC  - O(1) -----------------------------
int recBinarySearch(vector<int> arr, int tar, int st, int ed){
    if(st<=ed){
        int mid = st + (ed-st) /2;
        if(arr[mid] > tar){ //1st Half
            return recBinarySearch(arr, tar, st, mid-1);
        }else if (arr[mid] < tar){ //2nd Half
            return recBinarySearch(arr, tar, mid+1, ed);
        }else{
            return mid;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {-1, 0, 3, 4, 5, 9, 12};
    int target = 3;
    int value = recBinarySearch(arr, target, 0, arr.size()-1);

    cout << "Index value of Target : " << value << endl;
    return 0;
}


//Basically the search alorithm is to search a target in given array or string.
//Binary search is over the Linear Search Algorithm which means it is more enhanced/optimised then Linear-Search.
//There is a specific demand to use the Binary Search and i.e. sort(); which means it can be applied to a sorted array only.

//Note:
//int mid = (st + ed) /2;  
//Formula of calculating mid value the worst case scenario of the st and ed 'int' value could be INT_MAX , and adding the
//max int value can lead to overflow.
//SOlution: ALternate fomula:
//mid = st + (end-st)/2 ---> Here it result the same but approach is first subracting the max_int then dividing and eventually adding.

// how did the time complexity is O(logn)?
// ---> At every operation our array size get half i.e n/2 ==> n/4 ==> n/8
// which can also state as : n/2^1 ==> n/2^2 ==> n/2^3 ------Till 1 i.e k
// So n/2^k wil require to get 1; where can also be written as:
// n/2^k   ==   n=2^k   ==  log2n = k where base (2) is ignored.