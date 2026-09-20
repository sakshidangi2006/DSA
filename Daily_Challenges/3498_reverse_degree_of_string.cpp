#include <iostream>
using namespace std;

int reverseDegree(string s) {
    int sum = 0;

    for(int i = 0; i < s.size(); i++) {
        int revVal = 26 - (s[i]-'a');
        int pos = i+1;
        sum += revVal * pos;
    }
    return sum;
}

int main() {
    string s = "abc";
    int ans = reverseDegree(s);
    cout << ans;
    return 0;
}