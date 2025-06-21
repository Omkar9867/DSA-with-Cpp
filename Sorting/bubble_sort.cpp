#include <iostream>
using namespace std;

void sortArr(int arr[], int n){
    for(int i=0;  i<n - 1; i++){ // j will be putting the last element sorted
        for(int j=0; j<n-i-1; j++){ // j-n-1 because not to loop on last elem's as it is already sorted
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {2, 1, 5, 4, 9, 7, 10};
    int n = 7;
    cout << "Sorted ... ";
    sortArr(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}