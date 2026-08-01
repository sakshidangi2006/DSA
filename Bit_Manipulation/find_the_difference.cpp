#include <iostream>
using namespace std;

char findTheDifference(string s, string t) {
    char ans = 0;

    for (char ch : s) {
        ans ^= ch;
    }

    for (char ch : t) {
        ans ^= ch;
    }

    return ans;
}


int main() {
    string s = "abcd";
    string t = "abcde";
    char ans = findTheDifference(s,t);
    cout << ans;
    return 0;
}
