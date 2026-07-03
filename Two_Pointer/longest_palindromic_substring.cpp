#include <iostream>
using namespace std;


string longestPalindrome(string s) {
    int n = s.size();
    int start = 0;
    int maxLen = 1;

    for(int i = 0; i < n; i++) {
        int left = i;
        int right = i;

        while(left >= 0 && right < n && s[left] == s[right]) {
            if(maxLen < right - left + 1) {
                maxLen = right - left + 1;
                start = left;
            }
                left--, right++;
        }
        
        int left1 = i;
        int right1 = i+1;

        while(left1 >= 0 && right1 < n && s[left1] == s[right1]) {
            if(maxLen < right1 - left1 + 1) {
                maxLen = right1 - left1 + 1;
                start = left1;
            }
                left1--, right1++;
        }
    }

    return s.substr(start,maxLen);
}

int main() {
    string s = "babad";
    string ans = longestPalindrome(s);
    cout << ans;
    return 0;
}