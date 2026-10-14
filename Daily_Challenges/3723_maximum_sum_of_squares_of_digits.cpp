#include <iostream>
using namespace std;

string maxSumOfSquares(int num, int sum) {

    if(sum > num * 9) return "";
    int nines = sum / 9;
    int remain = sum % 9;

    string result(nines, '9');
    if(remain > 0) {
        result.push_back(remain + '0');
    }

    result.append(num - result.size(), '0');

    return result;
}

int main() {
    int num = 2;
    int sum = 3;
    string ans = maxSumOfSquares(num, sum);
    cout << ans;
    return 0;
}