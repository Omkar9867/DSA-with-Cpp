#include <bits/stdc++.h>

int main(){
    int t;
    std::cin >> t;
    while(t--){
        long long n;
        std::cin >> n;
        long long a[n];
        for(int i=0; i<n; i++){
            std::cin >> a[i];
        }
        //--------------------------------TC->O(1)--SC->O(1)-----------------------
        if(n%2==0){
            // 1 output the no of ops
            std::cout << 2 << std::endl;
            // 2 output the range 
            std::cout << 1 << " " << n << std::endl;
            std::cout << 1 << " " << n << std::endl;
        }else{
            // 1 output the no of ops
            std::cout << 4<< std::endl;
            // 2 output the range 
            std::cout << 1 << " " << n-1 << std::endl;
            std::cout << 1 << " " << n-1 << std::endl;
            std::cout << n-1 << " " << n << std::endl;
            std::cout << n-1 << " " << n << std::endl;
        }
    } 
    return 0;
}

// The simple sol is : when we do xor for the same number it results 0;
// So basically running xor twice for the arr and replacing the xor sum 'val' will give 0 for even case (since 2 same num will give 0)
// For odd n case workaround is for n-1 & n i.e. the leftover ones to do it twice

/*
    A. Make It Zero

    Time Limit: 1 second
    Memory Limit: 256 megabytes

    During Zhongkao examination, Reycloer met an interesting problem, but he cannot come up with a solution immediately. Time is running out! Please help him.

    Initially, you are given an array a consisting of n ≥ 2 integers, and you want to change all elements in it to 0.

    In one operation, you select two indices l and r (1 ≤ l ≤ r ≤ n) and do the following:

    - Let s = a[l] ⊕ a[l+1] ⊕ ... ⊕ a[r], where ⊕ denotes the bitwise XOR operation.
    - Then, for all l ≤ i ≤ r, replace a[i] with s.

    You can use the operation above in any order at most 8 times in total.

    Find a sequence of operations, such that after performing the operations in order, all elements in a are equal to 0. It can be proven that the solution always exists.

    Input

    The first line of input contains a single integer t (1 ≤ t ≤ 500) — the number of test cases. The description of test cases follows.

    The first line of each test case contains a single integer n (2 ≤ n ≤ 100) — the length of the array a.

    The second line of each test case contains n integers a1, a2, ..., an (0 ≤ ai ≤ 100) — the elements of the array a.

    Output

    For each test case, in the first line output a single integer k (0 ≤ k ≤ 8) — the number of operations you use.

    Then print k lines, in the i-th line output two integers li and ri (1 ≤ li ≤ ri ≤ n) representing that you select li and ri in the i-th operation.

    Note that you do not have to minimize k. If there are multiple solutions, you may output any of them.

    Example

    Input
    6
    4
    1 2 3 0
    8
    3 1 4 1 5 9 2 6
    6
    1 5 4 1 4 7
    5
    0 0 0 0 0
    7
    1 1 9 9 0 1 8
    3
    100 100 0

    Output
    1
    1 4
    2
    4 7
    1 8
    6
    1 2
    3 4
    5 6
    1 3
    4 6
    1 6
    0
    4
    1 2
    6 7
    3 4
    6 7
    1
    1 2

    Note

    In the first test case, since 1 ⊕ 2 ⊕ 3 ⊕ 0 = 0, after performing the operation on segment [1, 4], all the elements in the array are equal to 0.

    In the second test case, after the first operation, the array becomes equal to [3, 1, 4, 15, 15, 15, 15, 6], after the second operation, the array becomes equal to [0, 0, 0, 0, 0, 0, 0, 0].

    In the third test case:

    Operation | a before | a after
    1 | [1, 5, 4, 1, 4, 7] | [4, 4, 4, 1, 4, 7]
    2 | [4, 4, 5, 5, 4, 7] | [4, 4, 5, 5, 4, 7]
    3 | [4, 4, 5, 5, 4, 7] | [4, 4, 5, 5, 3, 3]
    4 | [4, 4, 5, 5, 3, 3] | [5, 5, 5, 5, 3, 3]
    5 | [5, 5, 5, 5, 3, 3] | [5, 5, 5, 5, 5, 5]
    6 | [5, 5, 5, 5, 5, 5] | [0, 0, 0, 0, 0, 0]

    In the fourth test case, the initial array contains only 0, so we do not need to perform any operations with it.
*/