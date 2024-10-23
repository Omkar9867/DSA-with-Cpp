#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 5;
    int arr[5] = {1,2,3,4,5};
    for(int st=0; st<n; st++){
        for(int ed=st; ed<n; ed++){
            for(int i=st; i<=ed; i++){
                cout << arr[i];
            }
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}

//SubArray ==> [1,2,3,4,5] --> So the possible subarrays are:
//1,2,3,4,5:single; 12,23,34,45:double; 123,234,345:triple and soo on 1234,2345 ; 12345; ==> So here pattern is every index is coupled with other index
//to calculate the total probab elements ==> n*(n+1)/2 --> 5*6/2 --> 15 , and when you count above , separated it is 15. Hint this the formula of sum of n numbers