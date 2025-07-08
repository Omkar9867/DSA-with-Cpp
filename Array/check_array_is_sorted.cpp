#include <iostream>
using namespace std;

// ---------------------------------Brute-Force-Approach O(n)---------------
bool isSortedArr(int arr[], int n){
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    int arr[] = {2,5,1,7,0,8,9,0,3};
    // int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = 9;
    const char* boolList[] = {"False", "True"};
    bool isSorted = isSortedArr(arr, n);
    cout << "Arr sorted is " << boolList[isSorted] << endl;
    return 0;
}