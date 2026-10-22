#include <bits/stdc++.h>

//-------------------------------My solution----------------------------------
int main(){
    int t;
    std::cin >> t;
    while(t--){
        long long a; 
        long long b; 
        long long c; 
        std::cin >> a;
        std::cin >> b;
        std::cin >> c;
        //-------------------------------TC->O(1)--SC->O(1)----------------------
        // Case 1 : if a+c & b+c is same based on the parity odd First even Second
        // Case 2 : if a > b then a + c if odd then Second , even then First 
        // Else : Vice versa
        std::string result = "";
        if(a+c == b+c){
            c % 2 == 0 ? result = "Second" : result = "First";
        }else if(a > b){
            a + c % 2 == 0 ? result = "Second" : result = "First";
        }else{
            b + c % 2 == 0 ? result = "First" : result = "Second";
        }
        std::cout << result << std::endl;
    }
    return 0;
}

//---------------------------------Actual----------------------------------
int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        long long a, b, c; // a: buttons only Anna can press, b: buttons only Katie can press, c: buttons either can press
        std::cin >> a >> b >> c;
        
        //-------------------------------TC->O(1)--SC->O(1)----------------------
        if (c % 2 == 1){ // odd
            // If c is odd, the player with more exclusive buttons will win
            if (b > a)
                std::cout << "Second" << std::endl;
            else
                std::cout << "First" << std::endl;
        }else{ // even
            // If c is even, the player with more exclusive buttons will win
            if (a > b)
                std::cout << "First" << std::endl;
            else
                std::cout << "Second" << std::endl;
        }
    }
    return 0;
}


/*
    A. Buttons

    Time limit per test: 1 second
    Memory limit per test: 256 megabytes

    Anna and Katie ended up in a secret laboratory.

    There are a+b+c buttons in the laboratory. It turned out that a buttons can only be pressed by Anna, b buttons can only be pressed by Katie, and c buttons can be pressed by either of them. Anna and Katie decided to play a game, taking turns pressing these buttons. Anna makes the first turn. Each button can be pressed at most once, so at some point, one of the girls will not be able to make her turn.

    The girl who cannot press a button loses. Determine who will win if both girls play optimally.

    Input
    The first line contains a single integer t (1 ≤ t ≤ 10^4) — the number of test cases.

    Each test case consists of three integers a, b, and c (1 ≤ a, b, c ≤ 10^9) — the number of buttons that can only be pressed by Anna, the number of buttons that can only be pressed by Katie, and the number of buttons that can be pressed by either of them, respectively.

    Output
    For each test case, output First if Anna wins, or Second if Katie wins.

    Example

    Input
    5
    1 1 1
    9 3 3
    1 2 3
    6 6 9
    2 2 8

    Output
    First
    First
    Second
    First
    Second

    Note
    For the simplicity of the explanation, we will numerate the buttons by the numbers from 1 to a+b+c: the first a buttons can only be pressed by Anna, the next b buttons can only be pressed by Katie, and the last c buttons can be pressed by either of them.

    In the first test case, Anna can press the 3-rd button on the first turn. Then Katie will press the 2-nd button (since it is the only possible turn for her). Then Anna will press the 1-st button. Katie won't have a button to press, so Anna will win.

    In the second test case, Anna can press the first nine buttons in some order on her turns. No matter what buttons Katie will press, all the buttons from the 10-th to the 15-th will be pressed after 12 turns. On the 13-th turn, Anna will press one of the first nine buttons and Katie will not have a button to press on her turn. Thus, Anna will win.

    In the third test case, the game can proceed as follows:

    On the 1-st turn Anna presses the 5-th button.
    On the 2-nd turn Katie presses the 4-th button.
    On the 3-rd turn Anna presses the 6-th button.
    On the 4-th turn Katie presses the 3-rd button.
    On the 5-th turn Anna presses the 1-st button.
    On the 6-th turn Katie presses the 2-nd button.

    Anna cannot make the turn, so Katie wins. It can be shown that Katie can win no matter what moves Anna takes.
*/