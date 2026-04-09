#include <bits/stdc++.h>

//----------------------------------Brute Force Approach--TC->O(N^2)---------------------------
// int totalFruit(std::vector<int>& fruits) {
//     int maxCount = 0;
//     for(int i = 0; i <fruits.size(); ++i){
//         std::unordered_map<int, int> basket;
//         int count = 0; // We just have to see from which i the count max
//         for(int j = i; j < fruits.size(); j++){
//             basket[fruits[j]]++;
//             if(basket.size() > 2){
//                 break;
//             }
//             count++;
//         }
//         maxCount = std::max(maxCount, count);
//     }
//     return maxCount;
// }

//----------------------------------Optimal Approach--TC->O(2N)--SC->O(1)-Const '2' space--------------------------
// int totalFruit(std::vector<int>& fruits) {
//     std::unordered_map<int, int> basket;
//     int maxCount = 0;
//     int l = 0, r = 0;
//     while(r < fruits.size()){
//         basket[fruits[r]]++;

//         while(basket.size() > 2){
//             basket[fruits[l]]--;
//             // if count becomes zero remove from map
//             if (basket[fruits[l]] == 0) {
//                 basket.erase(fruits[l]);
//             }
//             l++;
//         }
//         maxCount = std::max(maxCount, r - l+1);
//         r++;
//     }
//     return maxCount;
// }

//----------------------------------Optimal Approach2--TC->O(N)--SC->O(1)---------------------------
int totalFruit(std::vector<int>& fruits) {
    int maxlen = 0;
    
    int lastfruit = -1, secondlastfruit = -1;
    
    // Count of current window size and the last fruit streak
    int currcount = 0, lastfruitstreak = 0;

    for (int fruit : fruits) {
        
        // If current fruit is same as last or second last, increase window
        if (fruit == lastfruit || fruit == secondlastfruit) {
            currcount++;
        } else {
            // Reset window size to size of last fruit streak + 1 (current fruit)
            currcount = lastfruitstreak + 1;
        }

        // Update streak count
        if (fruit == lastfruit) {
            lastfruitstreak++;
        } else {
            lastfruitstreak = 1;
            secondlastfruit = lastfruit;
            lastfruit = fruit;
        }
        maxlen = std::max(maxlen, currcount);
    }

    return maxlen;
}

int main(){
    // std::vector<int> nums = {1,2,3,2,2};
    std::vector<int> nums = {1,2,1};
    int result = totalFruit(nums);

    std::cout << "Result: " << result << std::endl;

    return 0;
}

// 904. Fruit Into Baskets

// You are visiting a farm that has a single row of fruit trees arranged from left to right. 
// The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.

// Example 1:
// Input: fruits = [1,2,1]
// Output: 3
// Explanation: We can pick from all 3 trees.

// Example 2:
// Input: fruits = [0,1,2,2]
// Output: 3
// Explanation: We can pick from trees [1,2,2].
// If we had started at the first tree, we would only pick from trees [0,1].

// Example 3:
// Input: fruits = [1,2,3,2,2]
// Output: 4
// Explanation: We can pick from trees [2,3,2,2].
// If we had started at the first tree, we would only pick from trees [1,2].
 
// Constraints:
// 1 <= fruits.length <= 105
// 0 <= fruits[i] < fruits.length