#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long hoursRequired(vector<int>& piles, int speed) {
    long long h = 0;
    for (int pile : piles) {
        h += (long long)(pile + speed - 1) / speed;
    }
    return h;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long hrs = hoursRequired(piles, mid);
        if (hrs > h) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int>piles = {3,6,7,11};
    int ans = minEatingSpeed(piles,8);
    cout << ans;
    return 0;
}