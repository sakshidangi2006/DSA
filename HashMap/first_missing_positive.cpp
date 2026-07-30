#include <iostream>
#include <vector>
using namespace std;

#include <vector>
using namespace std;


int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n &&
               nums[nums[i] - 1] != nums[i]) {
            int j = nums[i] - 1;
            swap(nums[i], nums[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1)
            return i + 1;
    }

    return n + 1;
}

int main() {
    vector<int> nums = {1,2,0};
    int ans = firstMissingPositive(nums);
    cout<< ans;
    return 0;
}
