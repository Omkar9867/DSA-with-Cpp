#include <bits/stdc++.h>

int helper(int val, int n, std::vector<int> arr){ // An helper can be used for bound to find
    int si = 0, ei = n - 1;
    int ans = -1;

    while (si <= ei){
        int mid = (si + ei) / 2;

        if (arr[mid] <= val){
            ans = mid;    // valid candidate
            si = mid + 1; // search right for larger valid index
        }else{
            ei = mid - 1; // search left
        }
    }

    return ans + 1;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i=0; i<n; i++){
        std::cin >> arr[i];
    }
    
    int k;
    std::cin >> k;

    //---------------------TC->O(k+nlogn)-------------------
    std::sort(arr.begin(), arr.end());
    while(k--){
        int l, r;
        std::cin >> l >> r;

        // int startIdx = helper(l-1, n, arr);
        // int endIdx = helper(r, n, arr);

        auto startIdx = lower_bound(arr.begin(), arr.end(), l);
        auto endIdx = upper_bound(arr.begin(), arr.end(), r);
        int count = endIdx - startIdx;
        std::cout << count << " ";
    }

    return 0;
}

/*
    D. Fast search
    time limit per test2 seconds
    memory limit per test512 megabytes
    You are given an array a
    of n
    integers a1,a2,…,an
    .

    Your task is to response to the queries like "How many numbers' values are between l
    and r
    ?".

    Input
    The first line of the input contains n
    — the length of the array (1≤n≤105
    ).

    The second line contains n
    integers a1,a2,…,an
    (−109≤ai≤109
    ).

    The third line contains integer k
    — the number of queries (1≤k≤105
    ).

    The following k
    lines contain a pair of integers l
    r
    — query, described above (−109≤l≤r≤109
    ).

    Output
    The output must consist of k
    integers — responses for the queries.

    Example
    InputCopy
    5
    10 1 10 3 4
    4
    1 10
    2 9
    3 4
    2 2
    OutputCopy
    5 2 2 0 


*/