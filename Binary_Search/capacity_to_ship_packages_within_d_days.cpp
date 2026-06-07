#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool canShip(vector<int>& weights, int capacity, int days) {
    int usedDays = 1;
    int currWeight = 0;

    for (int w : weights) {
        if (currWeight + w > capacity) {
            usedDays++;
            currWeight = w;
        } else {
            currWeight += w;
        }
    }

    return usedDays <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canShip(weights, mid, days)) {
            ans = mid;
            high = mid - 1;   
        } else {
            low = mid + 1;    
        }
    }

    return ans;
}

int main() {
    vector<int>weights = {1,2,3,4,5,6,7,8,9,10};
    int ans = shipWithinDays(weights, 5);
    cout << ans;
    return 0;
}
