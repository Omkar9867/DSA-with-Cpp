#include <iostream>
#include <vector>
using namespace std;

//My Approach by learning
int binary_search(vector<int>sortedArr, int target){
    int st = 0, ed = sortedArr.size() -1;
    while(st <= ed) {
        int mid = (st + ed) /2;
        if(sortedArr[mid] > target){
            ed = mid - 1;
        }else if(sortedArr[mid] < target){
            st = mid+1;
        }else{
            return mid;
        }
    }
    return  -1;
}

int main(){
    vector<int> arr = {-1, 0, 3, 4, 5, 9, 12};
    int target = 9;
    int value = binary_search(arr, target);

    cout << "Index value of Target : " << value << endl;
    return 0;
}


//Basically the search alorithm is to search a target in given array or string.
//Binary search is over the Linear Search Algorithm which means it is more enhanced/optimised then Linear-Search.
//There is a specific demand to use the Binary Search and i.e. sort(); which means it can be applied to a sorted array only.