#include <bits/stdc++.h>

class Solution{
private:
    const int score[10][10] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,2,2,2,2,2,2,2,2,1},
        {1,2,3,3,3,3,3,3,2,1},
        {1,2,3,4,4,4,4,3,2,1},
        {1,2,3,4,5,5,4,3,2,1},
        {1,2,3,4,5,5,4,3,2,1},
        {1,2,3,4,4,4,4,3,2,1},
        {1,2,3,3,3,3,3,3,2,1},
        {1,2,2,2,2,2,2,2,2,1},
        {1,1,1,1,1,1,1,1,1,1}
    };
public:
//-----------------------------TC->O(N^2)--SC->O(1)----------------------------
    int target(std::vector<std::vector<char>> a){
        int total_score = 0;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (a[i][j] == 'X'){
                    total_score += score[i][j];
                }
            }
        }
        return total_score;
    }

//-----------------------TC->O(N^2)--SC->O(1)-------------------------
// without extra const pattern.
    int target(std::vector<std::vector<char>> a){
        int total_score = 0;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (a[i][j] == 'X'){
                    total_score += 1+std::min({i, j, 9-i, 9-j});
                }
            }
        }
        return total_score;
    }
};

int main(){
    Solution sol;
   std::vector<std::vector<char>> s = {
    {'X','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','X','.','.'},
    {'.','.','.','.','.','X','.','.','.','.'},
    {'.','.','.','.','.','.','X','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','X'},
    {'.','.','X','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.','X'}
    };
    int result = sol.target(s);
    return 0;
}

/*
    C. Target Practice

    Time limit per test: 1 second
    Memory limit per test: 256 megabytes

    A target is made out of five "rings" as shown. Each ring has a different point value: the outermost ring — 1 point, the next ring — 2 points, ..., the center ring — 5 points.

    https://espresso.codeforces.com/440826fc807f4a298e765d2288c50226f4ffa740.png

    Vlad fired several arrows at the target. Help him determine how many points he got.

    Input
    The input consists of multiple test cases. The first line of the input contains a single integer t (1 ≤ t ≤ 1000) — the number of test cases.

    Each test case consists of 10 lines, each containing 10 characters. Each character in the grid is either X (representing an arrow) or . (representing no arrow).

    Output
    For each test case, output a single integer — the total number of points of the arrows.

    Example

    Input
    4
    X.........
    ..........
    .......X..
    .....X....
    ......X...
    ..........
    .........X
    ..X.......
    ..........
    .........X
    ..........
    ..........
    ..........
    ..........
    ..........
    ..........
    ..........
    ..........
    ..........
    ..........
    ..........
    ..........
    ..........
    ..........
    ....X.....
    ..........
    ..........
    ..........
    ..........
    ..........
    XXXXXXXXXX
    XXXXXXXXXX
    XXXXXXXXXX
    XXXXXXXXXX
    XXXXXXXXXX
    XXXXXXXXXX
    XXXXXXXXXX
    XXXXXXXXXX
    XXXXXXXXXX
    XXXXXXXXXX

    Output
    17
    0
    5
    220

    Note
    In the first test case, there are three arrows on the outer ring worth 1 point each, two arrows on the ring worth 3 points each, and two arrows on the ring worth 4 points each. The total score is 17.

    In the second test case, there aren't any arrows, so the score is 0.
*/