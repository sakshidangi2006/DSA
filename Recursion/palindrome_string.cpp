#include <iostream>
using namespace std;

bool palindrome(string& s, int low, int high) {
    if (low >= high)
        return true;

    if (s[low] != s[high])
        return false;

    return palindrome(s, low + 1, high - 1);
}

bool isPalindrome(string& s) {
    return palindrome(s, 0, s.size() - 1);
}

int main() {
    string s = "abba";
    bool ans = isPalindrome(s);
    cout << ans;
    return 0;
}
