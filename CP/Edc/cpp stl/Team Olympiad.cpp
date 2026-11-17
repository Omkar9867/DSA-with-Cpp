#include <bits/stdc++.h>

// Each child is type 1 (programmer), 2 (mathematician) or 3 (sportsman).
// A valid team needs exactly one of each. Maximize the number of teams.
//
// Greedy is trivially optimal here: every team consumes exactly one child of
// each type, so with counts c1, c2, c3 you can never build more than
// min(c1, c2, c3) teams — and you can always achieve that many, since the
// children within a type are interchangeable. Which specific child goes on
// which team never matters, so no matching logic is needed.
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> one, two, three;

    for (int i = 0; i < n; i++){
        int x;
        std::cin >> x;

        if (x == 1)
            one.push_back(i + 1); // During input seggregate to respective grps
        else if (x == 2)
            two.push_back(i + 1);
        else
            three.push_back(i + 1);
    }

    std::vector<std::vector<int>> ans;

    for (int i = 0; i < std::min(one.size(), std::min(two.size(), three.size())); i++){
        ans.push_back({one[i], two[i], three[i]});
    }

    std::cout << ans.size() << std::endl;

    // Order within a team is not arbitrary: the problem wants programmer,
    // then mathematician, then sportsman. The one/two/three ordering here
    // satisfies that by construction.
    for (auto team : ans){
        for (auto idx : team){
            std::cout << idx << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)