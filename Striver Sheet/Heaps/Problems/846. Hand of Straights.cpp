#include <bits/stdc++.h>

class Solution {
public:

//---------------------------Approach--TC->O(NlogN)-SC->O(N)-----------------------
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        // If total cards can't be divided evenly, return false
        if (hand.size() % groupSize != 0) return false;

        // Store the frequency of each card
        std::map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        // Create an iterator pointing to the beginning of the frequency map
        auto it = freq.begin();

        while (it != freq.end()) {

            // Skip cards that are already used up
            if (it->second == 0) {
                ++it;
                continue;
            }

            // Store the starting card of the group
            int start = it->first;

            // Number of times we need to form this group
            int count = it->second;

            // Try to form a group of consecutive cards of size groupSize
            for (int i = 0; i < groupSize; ++i) {

                // If the current required card is missing or doesn't have enough frequency
                if (freq[start + i] < count) return false; //! Since consecutive, note if count of start should be equevallent to the forwards nums. No gaps.

                // Decrease the frequency for current card
                freq[start + i] -= count;
            }

            // Move the iterator to the next element
            ++it;
        }

        // All groups formed successfully
        return true;
    }

    void printResult(bool result){
        std::cout << "Result: " << result << std::endl;
    }
};

int main(){
    Solution obj;
    std::vector<int> hands = {1,2,3,6,2,3,4,7,8};
    int n = 3;   
    bool result = obj.isNStraightHand(hands, n);
    
    obj.printResult(result);

    return 0;
}


// 846. Hand of Straights

// Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
// Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

// Example 1:
// Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

// Example 2:
// Input: hand = [1,2,3,4,5], groupSize = 4
// Output: false
// Explanation: Alice's hand can not be rearranged into groups of 4.

// Constraints:
// 1 <= hand.length <= 104
// 0 <= hand[i] <= 109
// 1 <= groupSize <= hand.length
 
// !Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/