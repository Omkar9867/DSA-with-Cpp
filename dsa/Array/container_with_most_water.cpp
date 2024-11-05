#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//------------------------------------//Brute Force Approach -----> O(n^2)//-----------------------------
   ///Constraints here was n <= 10^5; and since our code is taking n^2 i.e. 10^5^2 ==> 10^10 viz not applicable to 10^8 which it gwenerally need to take
// int maxWidth(vector<int>arr){
//     int maxVal = 0;
//     for(int i=0; i<arr.size(); i++){
//         for(int j=i+1; j<arr.size(); j++){  //Logic here is calculate the area by the width and height i.e. w*h
//             int w = j - i;
//             int h = min(arr[j] , arr[i]);
//             maxVal = max(maxVal, w*h);
//         }
//     }
//     return maxVal;
// }
//---Will need O(nlogn) or O(n)---

//-----------------------------------//Optimal Approach ---> O(n)//--------------------------------------
  ///Here we'll use 2 pointer approach and logic would be which ever's height is small that would be ++ or --. because changing the index from bigger height will be no use as will not increase the width it will be same
int maxWidth(vector<int>arr){
    int st = 0, ed = arr.size()-1;
    int maxVal = 0;
    while(st < ed){
        int w = ed - st; //Note: width is calculating the index not the value
        int h = min(arr[st], arr[ed]);
        if(arr[st] < arr[ed]){
            st++;
        }else{
            ed--;
        }
        maxVal = max(maxVal, w*h);
    }
    return maxVal;
}

int main(){
    vector<int>height = {1,8,6,2,5,4,8,3,7};
    cout << "Max Width : " << maxWidth(height) << endl;
    return 0;
}




// //Question
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container. 

// Example 1:

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1

// Constraints:

// n == height.length
// 2 <= n <= 105
// 0 <= height[i] <= 104