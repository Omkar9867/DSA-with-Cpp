#include <bits/stdc++.h>

int main(){
        long long n;
        std::cin >> n;
        n*=2;
        std::vector<int> arr(n);
        for(int i=0; i<n; i++){
            std::cin >> arr[i];
        }
        //-----------------------------TC->O(NlogN)----------------------
        std::sort(arr.begin(), arr.end());
        int first_n = 0, last_n = 0;
        for(int i = 0; i<n/2; i++){
            first_n += arr[i];
        }
        for(int i = n/2; i<n; i++){
            last_n += arr[i];
        }

        if(first_n == last_n){ // If equal means no possible re-arrangment i.e. all are equal
            std::cout << -1 << std::endl;
        }else{
            for(auto elem : arr){
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    return 0;
}

// The intuition is to place the arr insuch way that take smallest elem put it in left side and largest to the right greedyly for n times
// The core idea is if we sort the arr the sum of the 2 parts will not be equal
// And if both parts of elements are eqal in sorted arr, it means it will always be same numbers and it results  '-1'

/*
    A. Ehab Fails to Be Thanos
    time limit per test1 second
    memory limit per test256 megabytes
    You're given an array a
    of length 2n
    . Is it possible to reorder it in such way so that the sum of the first n
    elements isn't equal to the sum of the last n
    elements?

    Input
    The first line contains an integer n
    (1≤n≤1000
    ), where 2n
    is the number of elements in the array a
    .

    The second line contains 2n
    space-separated integers a1
    , a2
    , …
    , a2n
    (1≤ai≤106
    ) — the elements of the array a
    .

    Output
    If there's no solution, print "-1" (without quotes). Otherwise, print a single line containing 2n
    space-separated integers. They must form a reordering of a
    . You are allowed to not change the order.

    Examples
    InputCopy
    3
    1 2 2 1 3 1
    OutputCopy
    2 1 3 1 1 2
    InputCopy
    1
    1 1
    OutputCopy
    -1
    Note
    In the first example, the first n
    elements have sum 2+1+3=6
    while the last n
    elements have sum 1+1+2=4
    . The sums aren't equal.

    In the second example, there's no solution.
*/