#include <iostream>
#include <vector>
using namespace std;

vector<int> leftRightDifference(vector<int>& nums) {

    int n = nums.size();
    vector<int> leftSum(n, 0);
    vector<int> rightSum(n, 0);
    vector<int> ans(n);

    for (int i = 1; i < n; i++) {
        leftSum[i] = leftSum[i - 1] + nums[i - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        rightSum[i] = rightSum[i + 1] + nums[i + 1];
    }

    for (int i = 0; i < n; i++) {
        ans[i] = abs(leftSum[i] - rightSum[i]);
    }

    return ans;
}

int main() {
    vector<int> nums = {10,4,8,3};
    vector<int> ans = leftRightDifference(nums);
    cout <<"{";
    for(int i = 0; i < ans.size(); i++ ) {
        cout << ans[i] <<" ";
    }
    cout <<"}";
    return 0;
}