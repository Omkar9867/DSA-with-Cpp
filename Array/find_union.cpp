#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//-----------------------------Brute Force O(nlogn)-------------------
// vector<int> unionArr(vector<int> arr1, vector<int> arr2){
//     vector<int> tempArr;
//     tempArr.resize(arr1.size()+arr2.size());
//     merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), tempArr.begin());
//     int j = 0;
//     for(int i = 1; i<tempArr.size(); i++){
//         if(tempArr[i] != tempArr[j]){
//             j++;
//             tempArr[j] = tempArr[i];
//         }
//     }
//     return tempArr;
// }


//-----------------------------Better Approach-O(nlogn)-----------------------
// vector<int> unionArr(vector<int> arr1, vector<int> arr2){
//     vector<int> tempArr;
//     map<int, int> freq;
//     for(int i = 0; i<arr1.size(); i++){
//         freq[arr1[i]]++;
//     }
//     for(int i = 0; i<arr2.size(); i++){
//         freq[arr2[i]]++;
//     }
//     for(auto & it: freq){
//         tempArr.push_back(it.first);
//     }
//     return tempArr;
// }

//-----------------------------Optimal Approach-O(n)-----------------------
vector<int> unionArr(vector<int> arr1, vector<int> arr2){
    vector<int> tempArr;
    int i = 0, j = 0;

    // loop until i exceeds arr1 and j exceeds arr2
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] <= arr2[j]){
            if(tempArr.size() == 0 || tempArr.back() != arr1[i])
                tempArr.push_back(arr1[i]);
                i++;
        }else{
            if(tempArr.size() == 0 ||tempArr.back() != arr2[j])
                tempArr.push_back(arr2[j]);
                j++;
        }
    }
    while(i < arr1.size()){ // IF any element left in arr1 
        if(tempArr.back() != arr1[i])
            tempArr.push_back(arr1[i]);
            i++;
    }
    while(j < arr2.size()){ // IF any element left in arr2
        if(tempArr.back() != arr2[j])
            tempArr.push_back(arr2[j]);
            j++;
    }
    return tempArr;
}

int main(){
    vector<int> arr1 = {1,2,3,4,5,6};  
    vector<int> arr2 = {2,3,4,4,5};

    vector<int> result = unionArr(arr1, arr2);
    for(int i = 0; i<result.size(); i++){
        cout << result[i] << ", ";
    }
    return 0;
}

// Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.
// The union of two arrays can be defined as the common and distinct elements in the two arrays.NOTE: Elements in the union should be in ascending order.

// Examples

// Example 1:
// Input:
// n = 5,m = 5.
// arr1[] = {1,2,3,4,5}  
// arr2[] = {2,3,4,4,5}
// Output:
//  {1,2,3,4,5}

// Explanation: 
// Common Elements in arr1 and arr2  are:  2,3,4,5
// Distnict Elements in arr1 are : 1
// Distnict Elemennts in arr2 are : No distinct elements.
// Union of arr1 and arr2 is {1,2,3,4,5} 

// Example 2:
// Input:
// n = 10,m = 7.
// arr1[] = {1,2,3,4,5,6,7,8,9,10}
// arr2[] = {2,3,4,4,5,11,12}
// Output: {1,2,3,4,5,6,7,8,9,10,11,12}
// Explanation: 
// Common Elements in arr1 and arr2  are:  2,3,4,5
// Distnict Elements in arr1 are : 1,6,7,8,9,10
// Distnict Elemennts in arr2 are : 11,12
// Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12} 