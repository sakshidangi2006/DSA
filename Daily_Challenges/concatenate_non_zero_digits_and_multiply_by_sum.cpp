#include <iostream>
using namespace std;


long long sumAndMultiply(int n) {
    long long rev = 0;
    long long x = 0;
    long long sum = 0;

    while(n > 0) {
    int rem = n % 10;
    if(rem != 0)
        rev = (rev*10)+rem;
        sum += rem;
    n = n/10;

}

while(rev > 0) {
    int rem = rev % 10;
    x = (x*10) + rem;
    rev = rev/10;
}

    return x*sum;
}


int main() {
    int n = 10203004;
    long long ans = sumAndMultiply(n);
    cout << ans;
    return 0;
}