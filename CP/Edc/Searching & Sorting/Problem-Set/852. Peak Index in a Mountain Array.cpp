#include <bits/stdc++.h>

class Solution {
public:
//-------------------------TC->O(logn)--------------------------
    int peakIndexInMountainArray(std::vector<int>& arr) {
        int l = 0, r = arr.size()-1;
        while(l < r){
            int mid = (l+r)/2;
            if(arr[mid] < arr[mid + 1]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return r;
    }
};

int main(){

    return 0;
}