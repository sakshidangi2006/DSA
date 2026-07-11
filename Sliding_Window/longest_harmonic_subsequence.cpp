#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findLHS(vector<int>& nums) {

    sort(nums.begin(), nums.end());
    int low = 0;
    int maxLen = 0;

    for (int high = 0; high < nums.size(); high++) {

        while (nums[high] - nums[low] > 1) {
            low++;
        }

        if (nums[high] - nums[low] == 1) {
            maxLen = max(maxLen, high - low + 1);
        }
    }

    return maxLen;
}

int main() {
    vector<int> nums = {1,3,2,2,3,5,2,7};
    int ans = findLHS(nums);
    cout << ans; 
    return 0;
}