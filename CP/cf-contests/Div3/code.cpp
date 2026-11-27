#include <bits/stdc++.h>

int main(){
    int t;
    std::cin >> t;
    while(t--){
        long long l, a, b;
        std::cin >> l >> a >> b;
        //-----------------------------TC->O(N)----------------------
        std::unordered_set<int> a_set = {0};
        std::unordered_set<int> b_set = {0};
        for(int i=0; i<l; i++){
            a_set.insert(i * a % l);
        }
        for(int i=0; i<l; i++){
            b_set.insert(i * b % l);
        }
        int count = 0;
        for (auto elem : a_set) {
            if (b_set.find(elem) != b_set.end()) {
                count++;
            }
        }
        std::cout << count << '\n';
    }

    return 0;
}