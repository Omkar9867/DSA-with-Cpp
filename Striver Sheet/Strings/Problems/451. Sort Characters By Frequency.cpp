#include <bits/stdc++.h>

// static bool comparator(std::pair<int, char> p1, std::pair<int, char> p2) {
//     if (p1.first > p2.first) return true;
//     if (p1.first < p2.first) return false;
//     return p1.second < p2.second;
// }

// std::string frequencySort(std::string s) {
//     // Array to store frequency and character
//     std::pair<int, char> freq[26];
//     // Initialize frequency array with character labels
//     for (int i = 0; i < 26; i++) {
//         freq[i] = {0, i + 'a'};
//     }
//     // Count frequency of each character in string
//     for (char ch : s) {
//         freq[ch - 'a'].first++; // basically top find the charater postion
//     }
//     // Sort the frequency array using the custom comparator
//     sort(freq, freq + 26, comparator);

//     // Store characters with non-zero frequency, meaning which is in the 's'
//     std::string ans;
//     for (int i = 0; i < 26; i++) {
//         if (freq[i].first > 0) ans.push_back(freq[i].second);
//     }

//     // Return the result
//     return ans;
// }



//----------------------------------------------------TC->O(n log n)---SC->O(n)--------------------------
std::string frequencySort(std::string s) {
    // Array to store frequency and character
    std::map<char, int> freq;
    // Count frequency of each character in string
    for (auto& ch : s) {
        freq[ch]++;
    }
    //Above : Sorted automatically in desc order based on int

    std::vector<std::pair<char,int>> vect(freq.begin(),freq.end()); // vector can be sorted using sort()

    //Sort -> Important step using lambda
    sort(vect.begin(),vect.end(),  [](auto &a,auto &b){return a.second>b.second}  );

    std::string ans;
    for(auto &it:vect){
        ans.append(it.second,it.first); // ans.append(count, character); i.e (2, 'e')
    }
    // Return the result
    return ans;
}

int main(){
    std::string inputStr = "tree";
    std::string result = frequencySort(inputStr);

    std::cout << "Result after words reversed: '" << result << "'" << std::endl;
    return 0;
}

// 451. Sort Characters By Frequency

// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.

// Example 1:
// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

// Example 2:
// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.

// Example 3:
// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.
 
// Constraints:
// 1 <= s.length <= 5 * 105
// s consists of uppercase and lowercase English letters and digits.