#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>&nums){
    int ans = 0; //use only constant extra space --> condition satisfied
    for(int val: nums){ //linear runtime complexity --> condition satisfied cause used on loop only
        ans = ans ^ val; 
    }
    return ans;
}

int main(){
    //Way of writing:
    vector<int>nums = {4, 1, 1};
    cout << "Uniquie Value: " << singleNumber(nums) << endl;
    return 0;
}


// ----------------x----------------------
// 136. Single Number
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

//Since the given question says to implement solution in linear runtime, i.e. only in one loop we should be able to complete it.
//Logic for it is to use the Bitwise operator xor '^'; As we know that n^n = 0 and n^0 =n . So by xoring all the values it give the remained unique value becuase n^0 = n and since all rest were repeated so n^n=0;