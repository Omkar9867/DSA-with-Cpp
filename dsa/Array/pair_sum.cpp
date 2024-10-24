#include <iostream>
#include <vector>
using namespace std;

// //Brute Force Approach  ---> 0(n)2
// vector<int>pairSum(vector<int>arr, int target){
//     vector<int>num;
//     for(int i = 0; i<arr.size(); i++){
//         for(int j=i+1; j<arr.size(); j++){
//             if(arr[i]+arr[j] == target){
//                 num.push_back(arr[i]);
//                 num.push_back(arr[j]);
//                 return num;     // Since we retrun one pair , we'll return from here
//             }
//         }
//     }
//     return num;
// }

//Optimal Approach  ---> o(n)
vector<int>pairSum(vector<int>arr, int target){ 
    vector<int>val;
    int i=0, j=arr.size()-1;
    while(i < j){
        int pairSum = arr[i]+arr[j];
        if(pairSum > target){
            j--;
        }else if(pairSum < target){
            i++;
        }else{
            val.push_back(arr[i]);
            val.push_back(arr[j]);
            return val;
        }
    }
}

int main(){
    vector<int>nums = {1, 2, 3, 4, 5};
    int target = 9;
    vector<int>val = pairSum(nums, target);

    cout << val[0] << ", " << val[1] << endl;

    return 0;
}

//Question
//Return pair in sorted array with target sum

//Here we forgot that array is sorted, so logic can be done using 2 pointer,
// when the calulated sum > target ==> end-- //Because since its sorted we then have to take smaller num
// when the calculated sum < target ==> start++ //Because sinve its sorted we then have to take bigger num