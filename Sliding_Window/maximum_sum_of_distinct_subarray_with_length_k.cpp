#include <bits/stdc++.h>
using namespace std;


long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_map<int,int>freq;
    long long sum = 0, maxSum = 0;

    for(int i = 0; i < nums.size(); i++) {
        freq[nums[i]] ++;
        sum += nums[i];

        if(i >= k) {
            sum -= nums[i-k];
            freq[nums[i-k]]--;

            if(freq[nums[i-k]] == 0) {
                freq.erase(nums[i-k]);
            }
        }

        if(freq.size() == k){
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
}

int main() {
    vector<int> nums = {1,5,4,2,9,9,9};
    int k = 3;
    long long ans = maximumSubarraySum(nums,k);
    cout << ans;
    return 0;
}
