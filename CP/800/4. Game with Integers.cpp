#include <bits/stdc++.h>

class Solution{
public:
//-----------------------------TC->O(1)--SC->O(1)----------------------------
    std::string gameInt(int n){
        if(n % 3 == 0){
            return "Second";
        }else{
            return "First";
        }
    }

};

int main(){
    Solution sol;
    int n = 1;
    std::string result = sol.gameInt(n);
    return 0;
}

/*
    A. Game with Integers

    Time limit per test: 1 second
    Memory limit per test: 256 megabytes

    Vanya and Vova are playing a game. Players are given an integer x. On their turn, the player can add y to the current integer or subtract y. The players take turns; Vanya starts. If after Vanya's move the integer is divisible by z, then he wins. If k moves have passed and Vanya has not won, then Vova wins.

    Write a program that, based on the integer x, determines who will win if both players play optimally.

    Input
    The first line contains the integer t (1 ≤ t ≤ 100) — the number of test cases.

    The single line of each test case contains the integer x (1 ≤ x ≤ 10^9).

    Output
    For each test case, print "First" without quotes if Vanya wins, and "Second" without quotes if Vova wins.

    Example

    Input
    6
    1
    3
    5
    100
    999
    1000

    Output
    First
    Second
    First
    First
    Second
    First
*/