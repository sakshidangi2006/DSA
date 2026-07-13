#include <iostream>
#include <climits>
using namespace std;


int reverse(int x) {
    int sign = (x < 0) ? -1 : 1;

    long long num = llabs((long long)x);
    long long rev = 0;

    while (num > 0) {
        rev = rev * 10 + (num % 10);
        num /= 10;
    }

    rev *= sign;

    if (rev > INT_MAX || rev < INT_MIN)
        return 0;

    return (int)rev;
}

int main(){
    int x = -123;
    int ans = reverse(x);
    cout << ans;
    return 0;
}
