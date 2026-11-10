#include <bits/stdc++.h>

// Arrays to represent the possible directions a knight can move
int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1}; // Note this are the x&y quadrants generlised in arr

int main(){
    int t;
    std::cin >> t;
    while(t--){
        long long a, b;
        std::cin >> a >> b;
        
        long long x_king, y_king;
        std::cin >> x_king >> y_king;
        long long x_queen, y_queen;
        std::cin >> x_queen >> y_queen;

        //----------------------------------TC->O(nlogn)---SC->O(N)------------------------------
        std::set<std::pair<long long, long long>> king_hits , queen_hits; // Note set does not store duplicates, the minimum 4 no of moves when a == b can be adjusted
        for(int i=0; i<4; i++){
            //Here we cover 2 set for every moves so 8 quadrants are covered.
            king_hits.insert({x_king + dx[i]*a, y_king + dy[i]*b});
            king_hits.insert({x_king + dx[i]*b, y_king + dy[i]*a});

            queen_hits.insert({x_queen + dx[i]*a, y_queen + dy[i]*b});
            queen_hits.insert({x_queen + dx[i]*b, y_queen + dy[i]*a});
        }
        int ans = 0;
        for(auto position : king_hits){
            if(queen_hits.find(position) != queen_hits.end()){
                ans++;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}

// TC -> O(8*log2(8)) = O(8*3) = O(24)
// Sc -> O(8)

/*
    A. Forked!

    Time Limit: 2 seconds
    Memory Limit: 256 megabytes

    Lunchbox is done with playing chess! His queen and king just got forked again!

    In chess, a fork is when a knight attacks two pieces of higher value, commonly the king and the queen. Lunchbox knows that knights can be tricky, and in the version of chess that he is playing, knights are even trickier: instead of moving 1 tile in one direction and 2 tiles in the other, knights in Lunchbox's modified game move a tiles in one direction and b tiles in the other.

    Lunchbox is playing chess on an infinite chessboard which contains all cells (x, y) where x and y are (possibly negative) integers. Lunchbox's king and queen are placed on cells (xK, yK) and (xQ, yQ) respectively.

    Find the number of positions such that if a knight was placed on that cell, it would attack both the king and queen.

    Input

    Each test contains multiple test cases. The first line contains an integer t (1 ≤ t ≤ 1000) — the number of test cases. The description of the test cases follows.

    The first line of each test case contains two integers a and b (1 ≤ a, b ≤ 10^8) — describing the possible moves of the knight.

    The second line of each test case contains two integers xK and yK (0 ≤ xK, yK ≤ 10^8) — the position of Lunchbox's king.

    The third line of each test case contains xQ and yQ (0 ≤ xQ, yQ ≤ 10^8) — the position of Lunchbox's queen.

    It is guaranteed that Lunchbox's queen and king will occupy different cells. That is, (xK, yK) ≠ (xQ, yQ).

    Output

    For each test case, output the number of positions on an infinite chessboard such that a knight can attack both the king and the queen.

    Example

    Input
    4
    2 1
    0 0
    3 3
    1 1
    3 1
    1 3
    4 4
    0 0
    8 0
    4 2
    1 4
    3 4

    Output
    2
    1
    2
    0

    Note

    In the first test case, the knight can move 2 squares in one direction and 1 square in the other (it is essentially the same as the knight in standard chess). 
    A knight placed on (2, 1) or (1, 2) would attack both the king and queen.

    In the second test case, a knight placed on (2,2)
    would attack both the king and queen.

    In the third test case, a knight placed on (4,4)
    or (4,−4)
    would attack both the king and queen.

    In the fourth test case, there are no positions where the knight can attack both the king and the queen.
*/