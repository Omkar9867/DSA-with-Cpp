#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i] <= pivot && i<high){
            i++;
        }
        while(arr[j] > pivot && j>low){
            j--;
        }
        if(i < j) swap(arr[i], arr[j]); //!Important condition
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex-1);
        qs(arr, pIndex+1, high);
    }
}

vector<int> quickSort(vector<int> &arr){
    qs(arr, 0, arr.size()-1);
    return arr;
}

int main(){
    vector<int> arr = {2, 1, 5, 4, 9, 7, 10};
    int n = 7;
    cout << "Sorted ... ";
    quickSort(arr);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// ----------------TC- O(nlogn)---------------
// ----------------SC- O(1)---------------

// First we'll make a recurring function that takes arr and low and high
// Then the placement of the pivot number to its correct position:
// Well make the pivot as the first elem i.e. low, then we need to make all small elem in left and big to right
// SO the conditions are like :[i=low; j-high] if the i is less then pivot increase it until someone is greater and until it reaches high-1 then pause .
// For j if it is high then pivot decrease it until someone is smaller and until it reaches low-1.  Note: for left place everything less or equal, and on right all greater
// when the both while stops swap them
// Lastly if j breaches i i.e they intersects break the main loop, and swap the pivot with the j index one --> arr[pivot] <-> arr[j]
