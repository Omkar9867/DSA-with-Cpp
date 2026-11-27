#include <bits/stdc++.h>

int main(){
    int t;
    std::cin >> t;
    while(t--){
        long long x;
        std::cin >> x;
        //----------------------------------------------
        // bool drop = true;
        long long attack = 1;
        long long stack = 0;
        while(x){
            if(attack*(attack + 1)/2 >= x){
                break;
            }else{
                attack++;
                stack++;
            }
        }
        std::cout << attack+stack << std::endl;
    }
    return 0;
}


int main(){
    int t;
    std::cin >> t;
    while(t--){
        long long x;
        std::cin >> x;
        //------------------TC->O(N^2)----------------------------
        // bool drop = true;
        long long ans = x; // Worst case: attack x times with 0 charges
        
        for (long long c = 0; c <= 200; c++) {
            long long P = c + 1; // Attack power after c charges since increases by 1.
            for (long long a = 1; a <= P; a++) {
                long long damage = a * P - a * (a - 1) / 2; // Arithmetic progression
                if (damage >= x) {
                    ans = std::min(ans, c + a);
                    break;
                }
            }
        }
        
        std::cout << ans << std::endl;
    }
    return 0;
}