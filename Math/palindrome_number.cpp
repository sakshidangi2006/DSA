#include <iostream>
using namespace std;

bool isPalindrome(int x) {

    if (x < 0)
        return false;

    int original = x;
    long long num = 0;

    while (x > 0) {
        int rem = x % 10;
        num = num * 10 + rem;
        x = x / 10;
    }

    return num == original;
}

int main() {
    int x = 121;
    bool ans = isPalindrome(x);
    cout << ans;
    return 0;
}