#include <bits/stdc++.h>

int main(){
    int t;
    std::cin >> t;
    while(t--){
        long long n; // Length of arr
        std::cin >> n;
        std::vector<long long> arr(n);
        for(int i=0; i<n; i++){
            std::cin >> arr[i];
        }
        //--------------------TC->O(N)---SC->O(N)--------------------
        long long operations = INT_MAX;
        for(int i=0; i<n-1; i++){
            if(arr[i] <= arr[i + 1]){
                long long diff = arr[i+1] - arr[i];
                operations = std::min(operations , diff/2 + 1); // diff/2 + 1 is the formula if 1 is increasing and other is decreasing.
            }else{ // already unsorted
                operations = 0;
            }
        }
        std::cout << operations << std::endl;
    }
    return 0;
}

/*
    A. Desorting

    Time limit per test: 1 second
    Memory limit per test: 256 megabytes

    Call an array a of length n sorted if a1 ≤ a2 ≤ … ≤ an−1 ≤ an.

    Ntarsis has an array a of length n.

    He is allowed to perform one type of operation on it (zero or more times):

    Choose an index i (1 ≤ i ≤ n−1).
    Add 1 to a1, a2, …, ai.
    Subtract 1 from ai+1, ai+2, …, an.

    The values of a can be negative after an operation.

    Determine the minimum operations needed to make a not sorted.

    Input
    Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 100). The description of the test cases follows.

    The first line of each test case contains a single integer n (2 ≤ n ≤ 500) — the length of the array a.

    The next line contains n integers a1, a2, …, an (1 ≤ ai ≤ 10^9) — the values of array a.

    It is guaranteed that the sum of n across all test cases does not exceed 500.

    Output
    Output the minimum number of operations needed to make the array not sorted.

    Example

    Input
    4
    2
    1 1
    4
    1 8 10 13
    3
    1 3 2
    3
    1 9 14

    Output
    1
    2
    0
    3

    Note
    In the first case, we can perform 1 operation to make the array not sorted:

    Pick i = 1. The array a then becomes [2,0], which is not sorted.

    In the second case, we can perform 2 operations to make the array not sorted:

    Pick i = 3. The array a then becomes [2,9,11,12].

    Pick i = 3. The array a then becomes [3,10,12,11].

    It can be proven that 1 and 2 operations are the minimal numbers of operations in the first and second test cases, respectively.

    In the third case, the array is already not sorted, so we perform 0 operations.
*/