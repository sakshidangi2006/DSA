#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longestPalindrome(string s) {
    int ans = 0;
    unordered_map<int,int>mpp;

    for(char ch: s) {
        mpp[ch]++;
    }

    bool odd = false;

    for(auto i : mpp) {
        int val = i.second;

        if(val % 2 == 0) {
            ans += val;
        }

        else {
            odd = true;
            ans += val -1;
        }
    }

    if(odd == true) {
        return ans +1;
    }

    return ans;
}

int main() {
    string s = "abccccdd";
    int ans = longestPalindrome(s);
    cout << ans;
    return 0;
}