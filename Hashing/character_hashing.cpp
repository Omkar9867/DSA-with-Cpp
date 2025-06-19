#include <iostream>
#include <map>
using namespace std;

int main(){

    // string s;
    // cin >> s;
    // Pre compute
    // int hash[26] = {0};
    // for(int i=0; i<s.size(); i++){
    //     hash[s[i] - 'a'] += 1;
    // }
    // int q;
    // cin >> q;
    // while(q--){
    //     char c;
    //     cin >> c;
    //     // fetch
    //     cout << hash[c-'a'] << endl;
    // }

    // Map int
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    //Pre compute
    map<int, int> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }
    // Iterate in the map to see the sort
    for(auto it: mpp){
        cout << it.first << "-->" << it.second << endl;
    }
    int q;
    cin >> q;
    while(q--){
        int num;
        cin >> num;
        // fetch
        cout << mpp[num] << endl;
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
// It is best option because the normal arr hash will take the max number value length and create that size array to store
// But map only stores value that is needed
//Map: stores all the values in sorted order
//Storing or fetching from map takes OlogN TC in all case scenario

// Unorderd map
// As the name commends it doesnot store in order
// Advantage: avg and best case scenario --> O(1)
//          : worst case scenario --> O(N)

//WorstCase reason: Internal Collision
// concept of collision example is when max numbers hash in a only particular index.
// [1, 2,    3,     4]
// [-, -, all data, -]