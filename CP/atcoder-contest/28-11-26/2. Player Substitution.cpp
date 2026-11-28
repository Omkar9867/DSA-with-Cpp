#include <bits/stdc++.h>

int main(){
    int n, m;
    std::cin >> n;
    std::cin >> m;

    std::set<int> result;
    
    for(int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        result.insert(x);
    }
    //-----------------------------TC->O(MlogN)--SC->O(N)------------------
    while(m--){
        int x , y;
        std::cin >> x;
        std::cin >> y;

        result.erase(x);
        result.insert(y);
    }

    for(auto player: result){
        std::cout << player << " ";
    }

    return 0;
}
// int main(){
//     int n, m;
//     std::cin >> n;
//     std::cin >> m;
//     std::vector<int> arr(n);
//     for(int i = 0; i < n; i++){
//         std::cin >> arr[i];
//     }
//     //-----------------------------TC->O(NlogN)--SC->O(N)------------------
//     std::sort(arr.begin(), arr.end());
//     std::vector<int> result = arr;
//     while(m--){
//         int x , y;
//         std::cin >> x;
//         std::cin >> y;

//         auto playerx = std::lower_bound(result.begin(), result.end(), x);

//         if (playerx != result.end() && *playerx == x) {
//             *playerx = y;
//         }
//     }
//     std::sort(result.begin(), result.end());
//     for(auto player: result){
//         std::cout << player << " ";
//     }

//     return 0;
// }

/*
    B - Player Substitution

    Time Limit: 2 sec
    Memory Limit: 1024 MiB

    Score: [Not specified]

    Problem Statement

    A sports match is being played.

    At the start of the match, N players are on the field, and their uniform numbers are A1, A2, ..., AN.

    Between the start and the end of the match, Q substitutions were made. In the i-th substitution, the player with uniform number Xi on the field was replaced by the player with uniform number Yi on the bench.

    Find the uniform numbers of the players on the field at the end of the match.

    Constraints

    - [Missing in the provided statement]
    - The Ai are pairwise distinct.
    - [Missing in the provided statement]
    - At the time of the i-th substitution, the player with uniform number Xi is on the field, and the player with uniform number Yi is not on the field.
    - All input values are integers.

    Input

    The input is given from Standard Input in the following format:

    [Input format missing in the provided statement]

    Output

    Print the uniform numbers of the players on the field at the end of the match in ascending order, separated by spaces.

    Sample Input 1

    3 3 3 1 4 3 2 2 5 1 8

    Sample Output 1

    4 5 8

    Explanation:

    - At the start of the match, the uniform numbers of the players on the field are [Missing].
    - After the 1st substitution, the uniform numbers of the players on the field are [Missing].
    - After the 2nd substitution, the uniform numbers of the players on the field are [Missing].
    - After the 3rd substitution, the uniform numbers of the players on the field are [Missing].

    Sample Input 2

    1 4 1 1 2 2 1 1 2 2 1

    Sample Output 2

    1

    A player with the same uniform number may enter the field again.
*/