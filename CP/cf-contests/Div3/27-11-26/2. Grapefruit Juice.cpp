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
            //!Understand this step
            if(sum <= p){
                total_joy += p - sum;
            }else{
                break;
            }
        }

        std::cout << total_joy << '\n';
    }

    return 0;
}

/*
    B. Grapefruit Juice
    time limit per test2 seconds
    memory limit per test256 megabytes
    After making the sweet toast, Sunny and Aubrey turned their attention to the grapefruits that Sunny had brought for their picnic.

    They have n
    grapefruits in total. The i
    -th grapefruit has a taste value of ai
    .

    They can enjoy the grapefruits in two ways:

    eat the i
    -th grapefruit fresh and gain ai
    joy points;
    make a glass of juice from any k
    grapefruits and drink it to gain p
    joy points.
    Each grapefruit can be used only once: either eaten fresh or used to make a glass of juice. They can make any number of glasses of juice.

    What is the maximum total number of joy points they can gain?

    Input
    Each test consists of multiple test cases. The first line contains an integer t
    (1≤t≤104
    ) — the number of test cases. The description of the test cases follows.

    The first line of each test case contains three integers n
    , k
    , and p
    (1≤n≤2⋅105
    , 1≤k≤n
    , 1≤p≤109
    ) — the number of grapefruits, the number of fruits per glass of juice, and the joy points for a glass of juice.

    The second line contains n
    integers a1,a2,…,an
    (1≤ai≤109
    ) — the taste ratings of the grapefruits.

    The sum of n
    over all test cases does not exceed 2⋅105
    .

    Output
    For each test case, print a single integer — the maximum possible total joy.

    The answer may not fit into a 32-bit signed integer.

    Example
    InputCopy
    7
    4 2 10
    3 1 4 2
    3 3 100
    10 20 30
    3 1 5
    2 3 1
    4 2 5
    3 1 1 1
    3 2 10
    9 1 2
    2 2 4
    8 7
    4 2 5
    1 1 9 9
    OutputCopy
    20
    100
    15
    10
    19
    15
    23
    Note
    In the second test case, one glass gives 100
    points. Eating all three fruits fresh gives 10+20+30=60
    points.

    In the fifth test case, the friends can squeeze the fruits rated 1
    and 2
    and eat the fruit rated 9
    fresh. This gives 10+9=19
    points. Eating all three fresh would give 12
    points.

    In the seventh test case, using the two fruits rated 1
    for one glass gives 5+9+9=23
    points. Making no juice gives 20
    points, and making two glasses gives 10
    .
*/