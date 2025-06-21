#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=0;  i<n; i++){
        int j = i;
        while(j>0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp; 
            j--;
        }
    }
}

int main(){
    int arr[] = {2, 1, 5, 4, 9, 7, 10};
    int n = 7;
    cout << "Sorted ... ";
    insertionSort(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}