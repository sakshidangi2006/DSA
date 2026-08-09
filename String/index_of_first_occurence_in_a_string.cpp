#include <iostream>
using namespace std;

int strStr(string haystack, string needle) {

    int n = haystack.size();
    int m = needle.size();

    if(m > n) return -1;

    for(int i = 0; i < n; i++) {
        int j = 0;

        while( j < m && haystack[i+j] == needle[j]) {
            j++;
        }
        if(j == m) {
            return i;
        }
    }
    return -1;
}

int main() {
    string haystack = "sadbutsad";
    string needle = "sad";
    int ans = strStr(haystack, needle);

    cout << ans;
    return 0;
}