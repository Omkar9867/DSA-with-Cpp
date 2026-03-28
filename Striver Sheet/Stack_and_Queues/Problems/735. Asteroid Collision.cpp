#include <bits/stdc++.h>

//------------------------------------ Approach--TC->O(N)-SC->O(N)-------------------------
std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
    int n = asteroids.size();
    std::vector<int> st;
    
    for(int i = 0; i < n; i++){
        //If the aster is right moving push to the stack like made arr
        if(asteroids[i] > 0){
            st.push_back(asteroids[i]);
        }else{
            // pop the stack while it is not empty , if it is right moving and is smaller then the absolute aster
            while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])){
                st.pop_back();
            }
            // pop if both are of same size
            if(!st.empty() && st.back() == abs(asteroids[i])){
                st.pop_back();
            }else if(st.empty() || st.back() < 0){ // Else if stack is empty or has negative i.e left moving
                st.push_back(asteroids[i]);
            }
        }
    }
    return st;
}

int main(){
    std::vector<int> nums1 = {3,5,-6,2,-1,4};
    std::vector<int> result = asteroidCollision(nums1);
    for(int i = 0; i < result.size(); i++){
        std::cout << result[i] << std::endl;
    }
    return 0;
}

// 735. Asteroid Collision

// We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). 
// Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode.
// If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

// Example 1:
// Input: asteroids = [5,10,-5]
// Output: [5,10]
// Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

// Example 2:
// Input: asteroids = [8,-8]
// Output: []
// Explanation: The 8 and -8 collide exploding each other.

// Example 3:
// Input: asteroids = [10,2,-5]
// Output: [10]
// Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

// Example 4:
// Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
// Output: [-6,2,4]
// Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 makes the asteroid -1 explode and then continues going right, without reaching asteroid 4.
 
// Constraints:
// 2 <= asteroids.length <= 104
// -1000 <= asteroids[i] <= 1000
// asteroids[i] != 0