#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Brute force Approach ---> 0(n)2
// int majorElem(vector<int>arr){
//     int n = arr.size();
//     int count = 1;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i] == arr[j]){
//                 count++;
//             }
//         }
//         if(count > n/2 ){
//             return arr[i];
//         }
//     }
// }

// //Optimise Approach ---> 0(nlogn)
// int majorElem(vector<int>arr){
//    sort(arr.begin(), arr.end());//First well sort the array in ascending order
//    int n = arr.size();
//    int ans = arr[0];
//    int freq = 1;
//    for(int i=1; i<n; i++){
//     if(arr[i] == arr[i-1]){ //Then loop throught the array and see if the nex number is different to reset the frequency
//         freq++;
//     }else{
//         freq = 1;
//         ans = arr[i];
//     }
//     if(freq > n/2){
//         return ans; //see if the repeatition is bigger than n/2 and return that value only of that loop
//     }
//    }
//    return ans;
// }

//More Optimise Approch ==> Moore's Algorithm  ---> 0(n)
int majorElem(vector<int>arr){ //Logic here is to loop once and if the element is same increase the frequency else decrease it so that max increse or decrease will be in i and that in ans
    int n = arr.size(); //This logic refers to voting that in the end whoever repeats more will win even ++ or -- and have the ans as [i]
    int freq = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        if(freq == 0){
            ans = arr[i];
        }
        if(ans == arr[i]){
            freq++;
        }else{
            freq--;
        }
    }
    return ans;
}

int main(){
    vector<int>nums = {3,2,3};
    int val = majorElem(nums);
    cout << "Major Element: " << val << endl;
    return 0;
}

// Question
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
//It means that more that half of the size of arr the number repeats.
//Additional step if the question says it not have majority element then return 0
// count = 0;
// for(val: arr){
//     if(val == ans){
//         count++;    //So we will get the ans total repetation in the arr
//     }
//     if(count > n/2){
//         return ans;
//     }else{
//         return -1;
//     }
// }