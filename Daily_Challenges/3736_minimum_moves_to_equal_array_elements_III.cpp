#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minMoves(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxVal = nums[n-1];

    int ans = 0;
    int diff = 0;

    for(int i = 0; i < n; i++) {
        diff = maxVal - nums[i];
        ans += diff;
    }

    return ans;
}

int main() {
    vector<int>nums = {2,1,3};
    int ans = minMoves(nums);
    cout << ans;
    return 0;
}
