#include <bits/stdc++.h>

int main(){
    int t;
    std::cin >> t;
    while(t--){
        long long n;
        std::cin >> n;
        std::vector<long long> arr(n);
        for(int i=0; i<n; i++){
            std::cin >> arr[i];
        }
        //-------------------------TC->O(N)----------------------
        int max_count = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                count++;
            }else{
                count = 0;
            }
            max_count = std::max(max_count, count);
        }
        std::cout << max_count << std::endl; 
    }
    return 0;
}

/*
    B. Blank Space

    Time limit per test: 1 second
    Memory limit per test: 256 megabytes

    You are given a binary array a of n elements, a binary array is an array consisting only of 0s and 1s.

    A blank space is a segment of consecutive elements consisting of only 0s.

    Your task is to find the length of the longest blank space.

    Input
    The first line contains a single integer t (1 ≤ t ≤ 1000) — the number of test cases.

    The first line of each test case contains a single integer n (1 ≤ n ≤ 100) — the length of the array.

    The second line of each test case contains n space-separated integers a1, a2, …, an (0 ≤ ai ≤ 1) — the elements of the array.

    Output
    For each test case, output a single integer — the length of the longest blank space.

    Example

    Input
    5
    5
    1 0 0 1 0
    4
    0 1 1 1
    1
    0
    3
    1 1 1
    9
    1 0 0 0 1 0 0 0 1

    Output
    2
    1
    1
    0
    3
*/