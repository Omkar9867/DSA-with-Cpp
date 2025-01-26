#include <iostream>
#include <vector>
using namespace std;

//==> Since the task is to solve in O(logn) then bruteforce approach is no use now.

// ---------------------------------------------O(logn)----------------------------------
 int peakIndexInMountainArray(vector<int>& arr) {
        // int st = 0, ed = arr.size()-1; //Since the value cannot be start or end of the index so our starting point will be the next of the first index and same for end
        int st = 1, ed = arr.size()-2;
        while(st <= ed){
            int mid = st+(ed-st) / 2;
            if(arr[mid] > arr[mid -1] && arr[mid] > arr[mid +1]){
                return mid;
            }else{
                if(arr[mid] < arr[mid -1]){
                    ed = mid - 1;
                }else{
                    st = mid + 1;
                }
            }
        }
        return -1;
    }

int main(){
    vector<int>mountainArr = {0,10,5,2};
    int value = peakIndexInMountainArray(mountainArr);
    // cout << "Peak Mountain value is: " << value << endl;
    cout << "Peak Mountain index is: " << value << endl;
    return 0;
}



// Peak Index in a Mountain Array

// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
// Return the index of the peak element.
// Your task is to solve it in O(log(n)) time complexity.

// Example 1:
// Input: arr = [0,1,0]
// Output: 1

// Example 2:
// Input: arr = [0,2,1,0]
// Output: 1

// Example 3:
// Input: arr = [0,10,5,2]
// Output: 1

// Constraints:
// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// arr is guaranteed to be a mountain array.


//By the given question we know that sorted is included as it is mountain and peak will be greater from previous in asc order, and greater from after in desc order 
//Since sorted we'll use binary approach!