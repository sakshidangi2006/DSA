#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canMake(vector<int>& bloomDay, int day, int m, int k) {
    int bouquets = 0;
    int flowers = 0;

    for (int bloom : bloomDay) {
        if (bloom <= day) {
            flowers++;

            if (flowers == k) {
                bouquets++;
                flowers = 0;
            }
        } else {
            flowers = 0;
        }
    }

    return bouquets >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    long long need = 1LL * m * k;

    if (need > bloomDay.size())
        return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (canMake(bloomDay, mid, m, k))
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    vector<int>bloomDay = {1,10,3,10,2};
    int ans = minDays(bloomDay,3,1);
    cout << ans;
    return 0;
}