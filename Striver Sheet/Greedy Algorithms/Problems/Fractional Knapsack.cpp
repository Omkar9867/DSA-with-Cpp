#include<bits/stdc++.h>
using namespace std;

// Struct to represent an item with value and weight
struct Item {
    int value;
    int weight;
};

class Solution {
public:
//--------------------------------------------Approach-TC->O(NlogN + N)--SC->O(1)--------------------------------------------
//Step 1: Sort the arr w.r.t -> val/weight
//Count the values "state"
//"Double" the result due to points as the ans 
//Add the formula for the remain weight to get the value.
    // Comparator function to sort items by value/weight ratio
    bool static comp(Item a, Item b) {
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;
    }

    // Function to calculate the maximum value we can get with fractional knapsack
    double fractionalKnapsack(int C, Item arr[], int n) {
        std::sort(arr, arr + n, comp); //To sort w.r.t the (v/w)

        int curWeight = 0;
        double finalvalue = 0.0;

        for(int i = 0; i < n; i++){

            if(curWeight + arr[i].weight <= C){
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }else{
                // If the current item can't be fully added, take the fractional part
                int remain = C - curWeight;
                finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain; //The formula to get the val for the remaining weight
                break;
            }
        }
        return finalvalue;
    }
};

int main() {
    Solution obj;

    int n = 3, capacity = 50; 
    Item arr[n] = { {100,20},{60,10},{120,30} };
    
    double ans = obj.fractionalKnapsack(capacity, arr, n);
    
    cout << "The maximum value is " << setprecision(2) << fixed << ans;
    
    return 0;
}

// Fractional Knapsack Problem : Greedy Approach

// Problem Statement: The weight of N items and their corresponding values are given. 
// We have to put these items in a knapsack of weight W such that the total value obtained is maximized.
// Note: We can either take the item as a whole or break it into smaller units.

// Examples

// Example 1:
// Input:
//  val = [60, 100, 120], wt = [10, 20, 30], capacity = 50  
// Output:
//  240.000000  

// Explanation:
// - Take item 0 (w = 10, v = 60)  
// - Take item 1 (w = 20, v = 100)  
// - Take 2⁄3 of item 2 (w = 20, v = 80)  
// Total value = 60 + 100 + 80 = 240

// Example 2:
// Input:
//  val = [60, 100], wt = [10, 20], capacity = 50  
// Output:
//  160.000000  

// Explanation:
// Both items fit entirely since total weight 10 + 20 = 30 ≤ 50.  
// Total value = 60 + 100 = 160