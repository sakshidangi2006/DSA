#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {

    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++) {
        pq.push(nums[i]);
    }

    for (int i = k; i < n; i++) {
        if (nums[i] <= pq.top()) continue;
        pq.pop();
        pq.push(nums[i]);
    }

    return pq.top();
}

int main() {
    vector<int>nums = {3,2,1,5,6,4};
    int ans = findKthLargest(nums,2);
    cout << ans;
    return 0;
}
