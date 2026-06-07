#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int first = -1, last = -1;

    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target) {
            if (nums[mid] == target) first = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] <= target) {
            if (nums[mid] == target) last = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return {first, last};
}

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> ans = searchRange(nums,8);
    cout <<"{" << ans[0] <<","<<ans[1]<<"}";
    return 0;
}