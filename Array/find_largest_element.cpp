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
int largestElm(int arr[], int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > ans){
            ans = arr[i];
        }
    }
    return ans;
}


int main(){
    // vector<int> arr = {2,5,1,3,0};
    int arr[] = {2,5,1,3,0};
    int n = 5;
    // int largestElemet = largestElm(arr);
    int largestElemet = largestElm(arr, n);
    cout << "Ans: " << largestElemet << endl;
    return 0;
}