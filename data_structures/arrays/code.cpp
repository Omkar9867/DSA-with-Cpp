#include <iostream>
#include <climits>
using namespace std;

int main(){
    // int marks[5] = {99, 88, 77, 66, 55};
    // double price[] = {106.99, 98.03, 54.43};
    // int marksSize = sizeof(marks)/sizeof(int);
    // for(int i=0; i < marksSize; i++){
    //     cout << marks[i] << " ";
    // }

    //Find the smallest number in an array
    int nums[] = {5, 15, 22, 1, -15, -24};
    int size = sizeof(nums)/sizeof(int);
    int smallest = INT_MAX ; 
    for(int i=0; i<size; i++){
        if(nums[i] < smallest){
            smallest = nums[i];
        }
    }
    cout << "Smallest Number is: "<< smallest << endl;

    // cout << sizeof(marks) << endl;
    // cout << sizeof(price) << endl;
    return 0;
}

// Arrays:
// . same data type
// . contiguous in memory --> means every block will take 4 bytes of memory eg: if starts 100 , 2nd: 104, 108, ....
// . linear

//When initializing with a size of array will create that sizr in memory even if we initiaize with less value, and if not size initialize than the number of values will be its size
