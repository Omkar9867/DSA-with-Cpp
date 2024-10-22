#include <iostream>
#include <vector>
using namespace std;

// //Linear Search using vector
// int linearSearch(vector<int>arr, int target){
//     for(int i=0; i<arr.size(); i++){
//         if(arr[i] == target){
//             return i;
//         }
//     }
//     return -1;
// }

//Reverse code
vector<int>reverseArr(vector<int>&arr){
    int start = 0, end = arr.size()-1;
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    return arr;
}

int main(){
    vector<int> vec;  //0
    vec.push_back(20);
    vec.push_back(22);
    vec.pop_back();
    vector<int> arr = {1, 2, 3};
    int target = 3;
    // vector<int> vec (3, 0);
    // vector<char> vec = {'a', 'b', 'c', 'd'};

    // for(int val: arr){ //This is a forEach loop, where i is not a index , but it is the stored as value of that index. And the iderator type will be the same as the array
    //     cout << val << endl;
    // }
    // cout << vec.size() << endl;
    // cout << "Targetted value in in index: " << linearSearch(arr, target) << endl;
    arr = reverseArr(arr);
    for (int num: arr){
        cout << num;
    }
    cout << endl;
     for(int val: arr){ //This is a forEach loop, where i is not a index , but it is the stored as value of that index. And the iderator type will be the same as the array
        cout << val;
    }
    cout << endl;
    return 0;
}

//Vectors:
//It is dynamic in nature , which means its size can be changed
//STL: Standard Template Library --> include as library

//Vector Functions ==>
// .size --> size of the array,
// .push_back --> adds an element at last index of the array,
// .pop_back --> removes an element of last index of the array,
// .front --> print the first value
// .back --> print the last value
// .at --> accessing value of a particular index. alternate method of writing val[i] ==> val.at(i)

//Static and Dynamic Allocation of memory:
// Static is on compile-time -> meaning when create an array[], it will in memory make the spaces according to the compiler.
// Dynamic is on run-tim ->  When in vection operates the function then dynamically on runtime it updates the array size etc. on memory
// Thats why array have fixed size and vectors can be changable

//Stack allocation is on stack memory imagine like : |__|
//                                                   |__|   
//Dynamic allocation is on heap memort imagined in circular way.

//When we push an element in an array, and if the size is incapable, then it doubles the size of the present array and inserts the single value.
//So even though we inserted one value , but when size increased it doubles it and the leftovers are empty until it is filled again later.