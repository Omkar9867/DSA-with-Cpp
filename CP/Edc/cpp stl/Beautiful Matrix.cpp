#include <bits/stdc++.h>

// A 5x5 grid holds exactly one 1 and twenty-four 0s. One move swaps two
// adjacent rows or two adjacent columns. Print the minimum moves needed to
// bring the 1 to the center cell.
//
// Key insight: swapping adjacent rows shifts the 1 up or down by exactly one
// row and never changes its column, and vice versa. So the row distance and
// column distance are independent and each costs one move per step — the
// answer is just the Manhattan distance to the center.
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<std::vector<int>> v(5, std::vector<int>(5));

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            std::cin >> v[i][j];
        }
    }

    int x, y; // coordinates of the 1 (see note below on initialization)

    // Scan for the single 1. The break exits only the inner loop, so the outer
    // loop keeps running over the remaining rows — wasted work, but not a
    // correctness problem, since there is exactly one 1 and nothing can
    // overwrite x and y afterward.
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (v[i][j] == 1){
                x = i;
                y = j;
                break;
            }
        }
    }

    // Center is (2,2) in 0-indexed terms. Row moves and column moves are
    // independent, so the two distances simply add.
    std::cout << abs(x - 2) + abs(y - 2) << "\n";

    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)