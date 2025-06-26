#include <iostream>
#include <vector>
using namespace std;

// ======================================== O(n)============================

void recursiveBubbleSort(vector<int> &arr, int n){
    if (n == 1) return;
    int didSwap = 0;  // reason for did-swap is the arr is already  sorted so no need to further recurse
    for(int j = 0; j < n-1; j++){
        if(arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            didSwap = 1;
        }
    }
    if(didSwap == 0) return;
    recursiveBubbleSort(arr, n-1);
}


int main(){
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    int n = arr.size();
    cout << "Sorted ... ";
    recursiveBubbleSort(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// IN recursive bubble_sort rather than iterating the outer loop, call the parent function again and again and reduce n 
// so actual, it is like the outerLoop which was looping reverse will now be taken care by the fucntion itself by reducing n to 1