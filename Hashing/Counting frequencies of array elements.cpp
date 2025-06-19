#include <iostream>
#include <unordered_map>
using namespace std;

void Frequency(int arr[], int n){
    unordered_map<int, int> map;
    for(int i=0; i<n; i++){
        map[arr[i]]++;

    }
    for(auto x: map)
        cout << x.first << "-->" << x.second << endl;
}

int main(){

    int arr[] = {1, 2, 1, 4, 2, 3, 3};
    Frequency(arr, 7);

    return 0;
}