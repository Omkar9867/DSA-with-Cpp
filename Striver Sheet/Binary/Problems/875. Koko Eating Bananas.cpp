#include <bits/stdc++.h>

// -------------------------------------Brute Force Approach--TC->O(N * max(a[]))--SC->O(1)-----------------------------------
int calculateTotalHours(std::vector<int>& a, int hourly) {
    int totalHours = 0;
    for (int pile : a) {
        // Add hours using ceil
        totalHours += (pile + hourly - 1) / hourly; //Formula: (a + b - 1) / b (using integer division).
    }
    return totalHours;
}
int minEatingSpeed(std::vector<int>& piles, int h) {
    // Find maximum pile size
    int maxVal = *std::max_element(piles.begin(), piles.end());

    // Try every possible speed i to the max pile
    for (int i = 1; i <= maxVal; i++) {
        int hours = calculateTotalHours(piles, i); // Meaning if i can eat all bananas in ith hour i.e. <= h 

        // If hours fit within h
        if (hours <= h) {
            return i;
        }
    }
    return maxVal;
}


int main(){
    std::vector<int> arr = {3,6,7,11};
    int h = 8;
    int result = minEatingSpeed(arr, h);
    std::cout<< "Result: " << result << std::endl;
    return 0;
}

// 875. Koko Eating Bananas

// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
// If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.

// Example 1:
// Input: piles = [3,6,7,11], h = 8
// Output: 4

// Example 2:
// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

// Example 3:
// Input: piles = [30,11,23,4,20], h = 6
// Output: 23
 
// Constraints:
// 1 <= piles.length <= 104
// piles.length <= h <= 109
// 1 <= piles[i] <= 109