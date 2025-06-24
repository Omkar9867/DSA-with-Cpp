#include <iostream>
#include <vector>
using namespace std;
                                                           //  l        m   r        h
void merge(vector <int> &arr, int low, int mid, int high){ // [1, 2, 3, 5] [1, 2, 6, 8]
    vector<int> temp;
    // [low...mid]
    // [mid+2...high]
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
           temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid ){ // If still elements int he left arr
        temp.push_back(arr[left]);
        left++;
    } 
    while(right<=high){ // If still elements int he right arr
        temp.push_back(arr[right]);
        right++;
    }

    // add temp to arr
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}

void mS(vector <int> &arr, int low, int high){
    if(low == high) return;
    int mid = (low + high)/2;
    mS(arr, low, mid);
    mS(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr, int n){
    mS(arr, 0, n-1);
}


int main(){
    vector<int> arr = {5, 4, 4, 1, 1,};
    int n = arr.size();
    cout << "Sorted ... ";
    mergeSort(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}