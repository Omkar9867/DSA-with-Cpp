#include <iostream>
using namespace std;

int main(){
    // //Number Pattern
    // int n=7;
    // for(int i=1; i<=n; i++){//Lines
    //     for(int j=1; j<=n; j++){//Every single line
    //         cout << j;
    //     }
    //     cout << endl;
    // }

    // //Normal star pattern
    // int n=4;
    // for(int i=0; i<n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    //Character pattern
    int n = 7;
    for(int i=0; i<n; i++){
        char ch = 'A';
        for(int j=0; j<n; j++){
            cout << ch << " ";
            ch = ch+1; //ASCII value is being converted: A --> 65+1 => 66 --> B
        }
        cout << endl;
    }
    return 0;
}
