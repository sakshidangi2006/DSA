#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

  
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> mpp;

    for (int i = 0; i < nums.size(); i++) {
        if (mpp.count(nums[i]) && (i - mpp[nums[i]] <= k))
            return true;

        mpp[nums[i]] = i;
    }

    return false;
}

int main() {
    vector<int>nums = {1,2,3,1};
    bool ans = containsNearbyDuplicate(nums,3);
    cout << ans;
    return 0;
}