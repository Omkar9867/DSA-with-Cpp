#include <bits/stdc++.h>

class Solution{
public:
//--------------------------------------TC->O(N)
    int minCapacity(std::vector<int>& nums, int x){
        nums.push_back(x);
        int n = nums.size();
        int max_distance_between_points = INT_MIN;
        for(int i = 1; i < n; i++){
            if(i == n - 1){ //last point
                max_distance_between_points = std::max(max_distance_between_points, 2*(nums[i] - nums[i - 1]));
            }else{
                max_distance_between_points = std::max(max_distance_between_points, nums[i] - nums[i - 1]);
            }
        }
        return max_distance_between_points;
    }
};

//tc -> O(n) -> O(50)

int main(){
    Solution sol;
    int n = 3 , x = 7;
    std::vector<int> arr = {1, 2, 5};
    int result = sol.minCapacity(arr, x);
    std::cout << "Result: " << result << std::endl; 
    return 0;
}

// A. Line Trip --- time limit per test: 2 seconds --- memory limit per test256 megabytes

// There is a road, which can be represented as a number line. 
// You are located in the point 0 of the number line, and you want to travel from the point 0 to the point x, and back to the point 0.

// You travel by car, which spends 1 liter of gasoline per 1 unit of distance travelled. When you start at the point 0
// , your car is fully fueled (its gas tank contains the maximum possible amount of fuel).

// There are n gas stations, located in points a1,a2,…,an.
// When you arrive at a gas station, you fully refuel your car. Note that you can refuel only at gas stations, and there are no gas stations in points 0 and x

// You have to calculate the minimum possible volume of the gas tank in your car (in liters) that will allow you to travel from the point 0
//  to the point x and back to the point 0.

// Input
// The first line contains one integer t (1≤t≤1000) — the number of test cases.

// Each test case consists of two lines:

// the first line contains two integers n and x (1≤n≤50 ; 2≤x≤100);
// the second line contains n integers a1,a2,…,an (0<a1<a2<⋯<an<x).

// Output
// For each test case, print one integer — the minimum possible volume of the gas tank in your car that will allow you to travel from the point 0
// to the point x and back.

// Example
// InputCopy
// 3
// 3 7
// 1 2 5
// 3 6
// 1 2 5
// 1 10
// 7
// OutputCopy
// 4
// 3
// 7
// Note
// In the first test case of the example, if the car has a gas tank of 4
//  liters, you can travel to x
//  and back as follows:

// travel to the point 1
// , then your car's gas tank contains 3
//  liters of fuel;
// refuel at the point 1
// , then your car's gas tank contains 4
//  liters of fuel;
// travel to the point 2
// , then your car's gas tank contains 3
//  liters of fuel;
// refuel at the point 2
// , then your car's gas tank contains 4
//  liters of fuel;
// travel to the point 5
// , then your car's gas tank contains 1
//  liter of fuel;
// refuel at the point 5
// , then your car's gas tank contains 4
//  liters of fuel;
// travel to the point 7
// , then your car's gas tank contains 2
//  liters of fuel;
// travel to the point 5
// , then your car's gas tank contains 0
//  liters of fuel;
// refuel at the point 5
// , then your car's gas tank contains 4
//  liters of fuel;
// travel to the point 2
// , then your car's gas tank contains 1
//  liter of fuel;
// refuel at the point 2
// , then your car's gas tank contains 4
//  liters of fuel;
// travel to the point 1
// , then your car's gas tank contains 3
//  liters of fuel;
// refuel at the point 1
// , then your car's gas tank contains 4
//  liters of fuel;
// travel to the point 0
// , then your car's gas tank contains 3
//  liters of fuel.

