#include <iostream>
#include <vector>
using namespace std;

int findKthNumber(int m, int n, int k) {
    int low = 1;
    int high = m * n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        long long cnt = 0;
        for (int i = 1; i <= m; i++) {
            cnt += min(n, mid / i);
        }
        if (cnt >= k)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    vector<vector<int>>nums = {{1,2,3},{2,4,6},{3,6,9}};
    int ans = findKthNumber(3,3,5);
    cout << ans;
    return 0;
}