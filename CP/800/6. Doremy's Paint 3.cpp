#include <bits/stdc++.h>

class Solution{
public:
//-----------------------------TC->O(1)--SC->O(1)----------------------------
    std::string doremyPaint(std::vector<int> n){
        std::map<long long, long long>  freq_map;
        for(int i = 0; i < n.size(); i++){
            freq_map[n[i]]++;
        }
        // if more then 2 distinct number arrives
        if(freq_map.size() >= 3){
            return "NO";
        }else{
            // IF one freq even then the value of both will be same so the case is handled already
            long long freq_1 = freq_map.begin()->second;
            long long freq_2 = freq_map.rbegin()->second;
            
            // Check if the array can be made good
            if (freq_1 == freq_2) // If both frequencies are equal
                return  "Yes" ;
            else if (n.size() % 2 == 1 && abs(freq_1 - freq_2) == 1) // If the array length is odd and the frequency difference is 1
                return  "Yes" ;
            else
                return  "No";
        }
    }

};


int main(){
    Solution sol;
    std::vector<int> n = {1, 3, 4, 5};
    std::string result = sol.doremyPaint (n);
    return 0;
}

/*
    A. Doremy's Paint 3

    Time limit per test: 1 second
    Memory limit per test: 256 megabytes

    An array b1, b2, …, bn of positive integers is good if all the sums of two adjacent elements are equal to the same value. More formally, the array is good if there exists a k such that b1+b2=b2+b3=…=bn−1+bn=k.

    Doremy has an array a of length n. Now Doremy can permute its elements (change their order) however she wants. Determine if she can make the array good.

    Input
    The input consists of multiple test cases. The first line contains a single integer t (1 ≤ t ≤ 100) — the number of test cases. The description of the test cases follows.

    The first line of each test case contains a single integer n (2 ≤ n ≤ 100) — the length of the array a.

    The second line of each test case contains n integers a1, a2, …, an (1 ≤ ai ≤ 10^5).

    There are no constraints on the sum of n over all test cases.

    Output
    For each test case, print "Yes" (without quotes), if it is possible to make the array good, and "No" (without quotes) otherwise.

    You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

    Example

    Input
    5
    2
    8 9
    3
    1 1 2
    4
    1 1 4 5
    5
    2 3 3 3 3
    4
    100000 100000 100000 100000

    Output
    Yes
    Yes
    No
    No
    Yes

    Note
    In the first test case, [8,9] and [9,8] are good.

    In the second test case, [1,2,1] is good because a1+a2=a2+a3=3.

    In the third test case, it can be shown that no permutation is good.
*/