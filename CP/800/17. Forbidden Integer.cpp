#include <bits/stdc++.h>

int main(){
    int t;
    std::cin >> t;
    while (t--){
        long long n, k, x;
        std::cin >> n >> k >> x;
        
        //-------------------------------TC->O(N)--SC->O(1)----------------------
        if (x != 1){ // We can print all the 1's
            std::cout << "YES" << std::endl;
            std::cout << n << std::endl;
            for (int i = 1; i <= n; i++){
                std::cout << 1 << " ";
            }
            std::cout << std::endl;
        }else{
            if(k == 1 || (k == 2 && n % 2 == 1)){ // if k and x both are 1 or k is 2 but n is odd
                std::cout << "NO" << std::endl; 
            }else{
                std::cout << "YES" << std::endl;
                if (n % 2 == 0){ // Since even all 2's can work
                    std::cout << n / 2 << std::endl;
                    for (int i = 1; i <= n / 2; i++){ // Output n/2 number of 2s
                        std::cout << 2 << " ";
                    }
                    std::cout << std::endl;
                }else{ // Here if odd there will be definite one 3 and other 2's
                    std::cout << (n - 3) / 2 + 1 << std::endl;
                    for (int i = 1; i <= (n - 3) / 2; i++){ // Output (n-3)/2 number of 2s
                        std::cout << 2 << " ";
                    }
                    std::cout << 3 << std::endl; //One extra 3 after all 2's for odd
                }
            }
        }
    }
    return 0;
}

/*
    A. Forbidden Integer

    Time limit per test: 2 seconds
    Memory limit per test: 256 megabytes

    You are given an integer n, which you want to obtain. You have an unlimited supply of every integer from 1 to k, except integer x (there are no integer x at all).

    You are allowed to take an arbitrary amount of each of these integers (possibly, zero). Can you make the sum of taken integers equal to n?

    If there are multiple answers, print any of them.

    Input
    The first line contains a single integer t (1 ≤ t ≤ 100) — the number of test cases.

    The only line of each testcase contains three integers n, k, and x (1 ≤ x ≤ k ≤ n ≤ 100).

    Output
    For each test case, in the first line, print "YES" or "NO" — whether you can take an arbitrary amount of each integer from 1 to k, except integer x, so that their sum is equal to n.

    If you can, the second line should contain a single integer m — the total amount of taken integers. The third line should contain m integers — each of them from 1 to k, not equal to x, and their sum is n.

    If there are multiple answers, print any of them.

    Example

    Input
    5
    10 3 2
    5 2 1
    4 2 1
    7 7 3
    6 1 1

    Output
    YES
    6
    3 1 1 1 1 3
    NO
    YES
    2
    2 2
    YES
    1
    7
    NO

    Note
    Another possible answer for the first testcase is [1,1,1,1,3,3]. Note that you don't have to minimize the amount of taken integers. There also exist other answers.

    In the second testcase, you only have an unlimited supply of integer 2. There is no way to get sum 5 using only them.

    In the fifth testcase, there are no integers available at all, so you can't get any positive sum.
*/