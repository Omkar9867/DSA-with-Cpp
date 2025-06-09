#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    // Pre compute
    int hash[26] = {0};
    for(int i=0; i<s.size(); i++){
        hash[s[i] - 'a'] += 1;
    }
    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        // fetch
        cout << hash[c-'a'] << endl;
    }

    return 0;
}

//Trick is to has the character value with the help of ASCII encoding
// a = 97 so to determine the first index to 'a' is simply a - a == 0
// a = 98 similarly to determine the second index to 'b' is simply b - a == 1

// int s = 'a b c d'
// hash[s[i] - 'a']
// hash['a' - 'a']
// hash[0]
// No need of - 'a' if taking all the charaters i.e. 256 it will store correctly to their place where we want to retrieve it

// We cannot hash an array up to 10^7 , so to solve the problem
//*STL : 
// map && un-ordered map