#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int firstUniqChar(string s) {

    int n = s.size();
    unordered_map<char,int>mpp;

    for(char ch : s) {
        mpp[ch]++;
    }

    for(int i = 0; i < n; i++) {
        if(mpp[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    string s = "leetcode";
    int ans = firstUniqChar(s);
    cout << ans;
    return 0;
}
