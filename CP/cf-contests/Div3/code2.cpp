#include <bits/stdc++.h>

int main(){
    int t;
    std::cin >> t;
    while(t--){
        long long n, k, p;
        std::cin >> n >> k >> p;
        std::vector<int> arr(n);
        for(int i=0; i<n; i++){
            std::cin >> arr[i];
        }
        //-----------------------------TC->O(N)----------------------
        std::sort(arr.begin(), arr.end()); // Avoid sacrificing high value for juice

        long long total_joy = 0;

        for (int i = 0; i < n; i++){
            total_joy += arr[i];
        }

        for (int i = 0; i + k <= n; i += k) {
            long long sum = 0;

            for (int j = i; j < i + k; j++) {
                sum += arr[j];
            }

            
        }

        std::cout << total_joy << '\n';
    }

    return 0;
}