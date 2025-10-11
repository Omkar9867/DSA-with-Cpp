#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//--------------------------BruteForce Approach O(nlogn)---------------------
// int largestElm(vector<int>& arr){
//     sort(arr.begin(), arr.end());
//     return arr[arr.size() - 1];
// }


//--------------------------Optimal Approach O(n)---------------------
// int largestElm(int arr[], int n){
//     int ans = 0;
//     for(int i=0; i<n; i++){
//         if(arr[i] > ans){
//             ans = arr[i];
//         }
//     }
//     return ans;
// }

//--------------------------My demo Approach O(n)---------------------
int largestElm(int arr[], int n){
    int ans = arr[0];
    int st = 0, ed = n-1;
    while(st <= ed){
        if(arr[st] > ans){
            ans = arr[st];
            st++;
        }else if(arr[ed] > ans){
            ans = arr[ed];
            ed--;
        }else{
            st++;
            ed--;
        }
    }
    return ans;
}


int main(){
    // vector<int> arr = {2,5,1,3,0};
    int arr[] = {2,5,1,7,0,8,9,0,3};
    int n = 9;
    // int largestElemet = largestElm(arr);
    int largestElemet = largestElm(arr, n);
    cout << "Ans: " << largestElemet << endl;
    return 0;
}