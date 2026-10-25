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
        long long oddNumCount = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] % 2 == 1){
                oddNumCount++;
            }
        }
        if(oddNumCount % 2 == 1){
            std::cout << "NO" << std::endl;
        }else{
            std::cout << "YES" << std::endl;
        }
    }
    return 0;
}

// Odd + Odd = Even ; Even + Even = Even;
// The trick is when aligning the even items randomly to boxes it will give same parity
// Examine the odd alignmenet where arg is:
// if length of odd numbers is odd then it can never be align to in such way to give same parity
// If length is even then it can be aligned to give same parity.

/*
    A. Array Coloring

    Time limit per test: 1 second
    Memory limit per test: 256 megabytes

    You are given an array consisting of n integers. Your task is to determine whether it is possible to color all its elements in two colors in such a way that the sums of the elements of both colors have the same parity and each color has at least one element colored.

    For example, if the array is [1,2,4,3,2,3,5,4], we can color it as follows: [1,2,4,3,2,3,5,4], where the sum of the blue elements is 6 and the sum of the red elements is 18.

    Input
    The first line contains an integer t (1 ≤ t ≤ 1000) — the number of test cases.

    Each test case begins with a line containing an integer n (2 ≤ n ≤ 50) — the length of the array a.

    The next line contains n integers a1, a2, …, an (1 ≤ ai ≤ 50) — the elements of the array a.

    Output
    For each test case, output "YES" (without quotes) if it is possible to color the array in two colors in such a way that the sums of the elements of both colors have the same parity and each color has at least one element colored, and "NO" otherwise.

    You can output "Yes" and "No" in any case (for example, the strings "yES", "yes", and "Yes" will be recognized as correct answers).

    Example

    Input
    7
    8
    1 2 4 3 2 3 5 4
    2
    4 7
    3
    3 9 8
    2
    1 7
    5
    5 4 3 2 1
    4
    4 3 4 5
    2
    50 48

    Output
    YES
    NO
    YES
    YES
    NO
    YES
    YES

    Note
    The first sample is described in the statement.

    In the second sample, there are only two colorings [4,7] and [4,7], but in both cases the parity of sums is different.

    In the third sample, you can color [3,9,8] and 12 and 8 are both even.
*/