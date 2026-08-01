#include <iostream>
#include <unordered_map>
using namespace std;

char findTheDifference(string s, string t) {
    unordered_map<char, int> freq;

    for (char ch : s)
        freq[ch]++;

    for (char ch : t)
        freq[ch]--;

    for (auto &it : freq) {
        if (it.second != 0)
            return it.first;
    }

    return ' ';
}

int main() {
    string s = "abcd";
    string t = "abcde";
    char ans = findTheDifference(s,t);
    cout << ans;
    return 0;
}
