#include <iostream>
#include <climits>
using namespace std;

// ----------------------BruteForce Approach O(n)-----------------
// int secondLargestElement(int arr[], int n){
//     int large = arr[0];
//     int second_large = INT_MIN;
//     for(int i = 0; i < n; i++){
//         large = max(large, arr[i]);
//     }
//     cout << "Large " << large << endl;
//     for(int i = 0; i < n; i++){
//         if(arr[i] > second_large && arr[i] != large){
//             second_large = arr[i];
//         }
//     }
//     return second_large;
// }

// --------------------- Optimal Approach O(N), Single-pass solution --------------
int secondLargestElement(int arr[], int n){
    int large = INT_MIN;
    int second_large = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > large){
            second_large = large;
            large = arr[i];
        }else if(arr[i] > second_large && arr[i] != large){
            second_large = arr[i];
        }
    }
    return second_large;
}


int main(){ 
    int arr[] = {8, 8, 7, 6, 5};
    int n = 5;
    int ans = secondLargestElement(arr, n);
    cout << "Ans: " << ans << endl;
    return 0;
}


//Find Second Smallest and Second Largest Element in an array