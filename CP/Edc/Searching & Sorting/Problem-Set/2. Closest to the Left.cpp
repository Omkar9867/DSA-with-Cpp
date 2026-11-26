#include <bits/stdc++.h>

//-------------------------My Solution-----------------------
int main(){
    int t;
    // std::cin >> t;
    // while(t--){
        long long n , k;
        std::cin >> n >> k;
        std::vector<int> arr(n);
        std::vector<int> k_arr(n);
        for(int i=0; i<n; i++){
            std::cin >> arr[i];
        }
        for(int i=0; i<k; i++){
            std::cin >> k_arr[i];
        }
        //-----------------------------TC->O(klogN)--SC->O(K+N)--------------------
        std::vector<int> results(k);
        for(int i = 0; i<k; i++){
            // int low = 0, high = n-1;
            // int mid = low + (high - low)/2;
            // while(low <= high){

            // }
            auto lb = lower_bound(arr.begin(), arr.end(), k_arr[i]);
            results.push_back(lb - arr.begin());
        }
        for(auto result: results){
            std::cout << result << std::endl;
        }
    // }

    return 0;
}

/*
    B. Closest to the Left
    time limit per test2 seconds
    memory limit per test512 megabytes
    Given an array of n
    numbers, sorted in non-decreasing order, and k
    queries. For each query, print the maximum index of an array element not greater than the given one.

    Input
    The first line of the input contains integers n
    and k
    (0<n,k≤105
    ), the length of the array and the number of queries. The second line contains n
    elements of the array, sorted in non-decreasing order. The third line contains k
    queries. All array elements and queries are integers, each of which does not exceed 2⋅109
    in absolute value.

    Output
    For each of the k
    queries, print the maximum index of an array element not greater than the given one. If there are none, print 0.

    Example
    InputCopy
    5 5
    3 3 5 8 9
    2 4 8 1 10
    OutputCopy
    0
    2
    4
    0
    5
*/