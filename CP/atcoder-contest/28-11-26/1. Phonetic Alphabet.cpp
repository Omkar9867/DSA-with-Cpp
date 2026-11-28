#include <bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    //-----------------------------TC->O(N)--SC->O(N)------------------
    for(int i = 0; i < n; i++){
        if(s[i] == 'A'){
            std::cout << "Alpha" << " ";
        }else if(s[i] == 'B'){
            std::cout << "Bravo" << " ";
        }else{
            std::cout << "Charlie" << " ";
        }
    }
    return 0;
}


/*
A - Phonetic Alphabet  / 
Time Limit: 2 sec / Memory Limit: 1024 MiB

Score : 
100 points

Problem Statement
You are given a string 
S of length 
N consisting of A, B, and C.

Define the string 
T 
i
​
  as Alpha if the 
i-th character of 
S is A, Bravo if it is B, and Charlie if it is C.

Print 
T 
1
​
 ,…,T 
N
​
  in order.

Constraints
N is an integer between 
1 and 
100, inclusive.
S is a string of length 
N consisting of A, B, and C.
Input
The input is given from Standard Input in the following format:

N
S
Output
Print 
T 
1
​
 ,…,T 
N
​
  in this order, separated by spaces.

Sample Input 1
Copy
3
ABC
Sample Output 1
Copy
Alpha Bravo Charlie
The 
1-st, 
2-nd, and 
3-rd characters of 
S are A, B, and C, respectively, so 
T 
1
​
 ,T 
2
​
 ,T 
3
​
  are Alpha, Bravo, and Charlie, respectively.

Print these in this order.

Sample Input 2
Copy
6
CCABAC
Sample Output 2
Copy
Charlie Charlie Alpha Bravo Alpha Charlie
*/