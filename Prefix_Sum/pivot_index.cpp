#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }

        int left = 0;
        for(int i = 0; i < nums.size(); i++) {
            int right = sum - left - nums[i];

            if(left == right) {
                return i;
            }

            left += nums[i];
        }
        return -1;
    }

int main() {
    vector<int> nums = {1,7,3,6,5,6};
    int ans = pivotIndex(nums);
    cout << ans;
    return 0;
}