#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool canAllocate(vector<int>& candies, long long k, int x) {
    long long children = 0;

    for (int c : candies) {
        children += c / x;

        if (children >= k)
            return true;
    }

    return false;
}

int maximumCandies(vector<int>& candies, long long k) {
    int low = 1;
    int high = *max_element(candies.begin(), candies.end());

    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(candies, k, mid)) {
            ans = mid;
            low = mid + 1;   
        } else {
            high = mid - 1;  
        }
    }

    return ans;
}


int main() {
    vector<int>candies = {5,8,6};
    int ans = maximumCandies(candies,3);
    cout << ans;
    return 0;
}