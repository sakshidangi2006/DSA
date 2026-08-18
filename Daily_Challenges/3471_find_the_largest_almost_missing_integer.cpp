#include <iostream>
#include <vector>
#include <set>
using namespace std;


int largestInteger(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> count(51, 0);

    for (int i = 0; i <= n - k; i++) {
        set<int> seen;

        for (int j = i; j < i + k; j++) {
            seen.insert(nums[j]);
        }

        for (int x : seen) {
            count[x]++;
        }
    }

    for (int x = 50; x >= 0; x--) {
        if (count[x] == 1) {
            return x;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {3,9,2,1,7};
    int k = 3;
    int ans = largestInteger(nums,k);
    cout << ans;
    return 0;
}
