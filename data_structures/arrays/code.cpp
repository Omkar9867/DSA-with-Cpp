#include <iostream>
#include <climits>
using namespace std;

// int linearSearch(int arr[], int size, int target){ //Note never find length of an array in function where array is reference.
//     for(int i = 0; i < size; i++){
//         if(arr[i] == target){
//             return i;
//         }
//     }
//     return -1;
// }

// void reverseArr(int arr[], int size){
//     int start = 0 , end = size - 1;
//     while(start < end){ //Logic here is start will be starting point and end ending point , swap it till start=end or start>end i.e start>=end
//         swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }
// }

// Print Unique values
int uniqueVal(int arr[], int val[], int size, int &uniquecount){
    uniquecount = 0;  //Initialize with first index for val array so the unique value will place in 1st place.
    for(int i=0; i<size; i++){
      bool isUnique = true; //Assuming first element is unique
        for(int j=0; j<size; j++){
            if(i != j && (arr[i] == arr[j])){ // Just to update if unique , and if not then break and change to next one index
                isUnique = false;
                break;
            }
        }
        if(isUnique){  //here we come out of the innerloop where isUnique didnot changed and now the arry index which it was itirrating is unique so we fill it in val
            val[uniquecount] = arr[i];
            uniquecount++;
        }
    }
}

int main(){
    // int marks[5] = {99, 88, 77, 66, 55};
    // double price[] = {106.99, 98.03, 54.43};
    // int marksSize = sizeof(marks)/sizeof(int);
    // for(int i=0; i < marksSize; i++){
    //     cout << marks[i] << " ";
    // }

    //Find the smallest & largest number in an array
    int nums[] = {5, 15, 18, 15, 7, 8, 7, 8};
    int size = sizeof(nums)/sizeof(int);
    int smallest = INT_MAX ; //Inbuild variable that present the infinite value of an int for initializing
    int largest = INT_MIN ;
    int smallestIdx = 0;
    int largestIdx = 0;
    // for(int i=0; i<size; i++){
    //     // if(nums[i] < smallest){
    //     //     smallest = nums[i];
    //     // }
    //     //The shorter way to write this is buildin min , max function ==>
    //     smallest = min(nums[i], smallest);
    //     largest = max(nums[i], largest);
        
    // }
    // //Smallest and Largest index
    //  for(int i=0; i<size; i++){
    //     if(nums[i] < smallest){
    //         smallest = nums[i];
    //         smallestIdx = i;
    //     }else if(nums[i] > largest){
    //         largest = nums[i];
    //         largestIdx = i;
    //     }
    //     // smallest = min(nums[i], smallest);
    //     // largest = max(nums[i], largest);
        
    // }
    // cout << "Smallest Number is: "<< smallest << endl;
    // cout << "Largest Number is: "<< largest << endl;
    // cout << "Smallest Index is: "<< smallestIdx << endl;
    // cout << "Largest Index is: "<< largestIdx << endl;

    //Linear Search
    // int target = 24;
    // // int searchIdx = linearSearch(nums, size, target);
    // for(int i=0; i<size; i++){ // Before Reverse
    //     cout << nums[i] << " ";
    // }
    //  cout << endl;

    // //Reverse ARRAY
    // reverseArr(nums, size);
    // for(int i=0; i<size; i++){ //Since after the above function is called now array has been updated according to pass-by-reference
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    int val[size];
    int uniqueCount;
    uniqueVal(nums, val, size, uniqueCount);
    for(int i=0; i<uniqueCount; i++){
      cout << val[i] << " ";
    }
    cout << endl;
    return 0;
}

// Arrays:
// . same data type
// . contiguous in memory --> means every block will take 4 bytes of memory eg: if starts 100 , 2nd: 104, 108, ....
// . linear

//When initializing with a size of array will create that sizr in memory even if we initiaize with less value, and if not size initialize than the number of values will be its size

//Pass by Reference :
//pass by value was the value called in another function which makes copy of the variable in first function, so changing in second would not effect first
//Reference are of address , so if the array is called in the function and then modified it in the function it will change the modificaition into the address resulting change in actual array

//Linear Search : 
//One type of algorithm. It is a method of search that checks value through index.

//Reverse an Array:
//Well use 2pointer approach, it means taking 2 values and logically approach on them