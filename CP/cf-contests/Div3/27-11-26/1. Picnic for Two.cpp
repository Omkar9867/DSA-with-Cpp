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

/*
    A. Picnic for Two
    time limit per test1 second
    memory limit per test256 megabytes
    Sunny and Aubrey decided to spend the day together and have a picnic. They started their morning by preparing a dessert and baked a large, round sweet toast, pre-cut into l
    equal slices numbered from 0
    to l−1
    in clockwise order.

    The friends decided to decorate it with fresh berries:

    Aubrey is in charge of strawberries. She places one berry every a
    slices, starting from slice 0
    (that is, at positions 0,amodl,2amodl,…
    ), until she returns to an already visited slice.
    Sunny is in charge of blueberries. He places one berry every b
    slices, starting from slice 0
    (that is, at positions 0,bmodl,2bmodl,…
    ), until his placement cycle repeats as well.
    A slice of toast is considered ideal if it ends up with both a strawberry and a blueberry on it. Count the total number of ideal slices on the toast.

    Input
    Each test consists of multiple test cases. The first line contains an integer t
    (1≤t≤104
    ) — the number of test cases. The description of the test cases follows.

    Each of the next t
    lines contains three integers l
    , a
    , and b
    (2≤l≤22
    , 1≤a,b≤21
    ) — the number of slices in the toast and the steps with which Aubrey and Sunny place their berries.

    Output
    For each test case, print a single integer — the number of ideal slices on the toast.

    Example
    InputCopy
    5
    6 2 3
    10 4 7
    5 1 1
    4 10 21
    15 20 8
    OutputCopy
    1
    5
    5
    2
    3
    Note
    In the first test case the strawberries are on slices 0,2,4
    , and the blueberries are on slices 0,3
    . Only slice 0
    has both berries.

    In the second test case Aubrey visits slices 0,4,8,2,6
    . With a step of 7
    , Sunny visits slices 0,7,4,1,8,5,2,9,6,3
    . All five slices on which Aubrey placed a strawberry receive both berries.

    In the fourth test case, the steps 10
    and 21
    are equivalent to steps 2
    and 1
    modulo 4
    . Both berries appear on slices 0
    and 2
    .
*/