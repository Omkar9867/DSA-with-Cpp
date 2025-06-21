#include <iostream>
using namespace std;

void sortArr(int arr[], int n){
    for(int i=0;  i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {2, 1, 5, 4, 9, 7};
    int n = 6;
    cout << "Sorted ... ";
    sortArr(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}