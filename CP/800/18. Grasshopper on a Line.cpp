#include <bits/stdc++.h>

int main(){
    int t;
    std::cin >> t;
    while (t--){
        long long x, k;
        std::cin >> x >> k;
        
        //-------------------------------TC->O(1)--SC->O(1)----------------------
        if(x % k != 0){
            std::cout << 1 << std::endl;
            std::cout << x << std::endl;
        }else{
            std::cout << 2 << std::endl;
            std::cout << x - 1 << " " << 1 << std::endl;
        }
    }
    return 0;
}

//Arg is either 1 or 2 moves are required depend on the x divisibility with k
//Since any consecutive no is not divisible by k due to k > 2 condition

/*
    A. Grasshopper on a Line

    Time limit per test: 2 seconds
    Memory limit per test: 256 megabytes

    You are given two integers x and k. Grasshopper starts in a point 0 on an OX axis. In one move, it can jump some integer distance, that is not divisible by k, to the left or to the right.

    What's the smallest number of moves it takes the grasshopper to reach point x? What are these moves? If there are multiple answers, print any of them.

    Input
    The first line contains a single integer t (1 ≤ t ≤ 1000) — the number of testcases.

    The only line of each testcase contains two integers x and k (1 ≤ x ≤ 10^9; 2 ≤ k ≤ 10^9) — the endpoint and the constraint on the jumps, respectively.

    Output
    For each testcase, in the first line, print a single integer n — the smallest number of moves it takes the grasshopper to reach point x.

    In the second line, print n integers, each of them not divisible by k. A positive integer would mean jumping to the right, a negative integer would mean jumping to the left. The endpoint after the jumps should be exactly x.

    Each jump distance should be from 1 to 10^9. It can be shown that, for any solution with the smallest number of jumps, there exists a solution with the same number of jumps such that each jump is from 1 to 10^9.

    It can be shown that the answer always exists under the given constraints. If there are multiple answers, print any of them.

    Example

    Input
    3
    10 2
    10 3
    3 4

    Output
    2
    7 3
    1
    10
    1
    3
*/