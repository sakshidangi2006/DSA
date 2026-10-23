#include <iostream>
#include <vector>
using namespace std;


vector<int> productExceptSelf(vector<int>& nums) {
    int product = 1;
    int n = nums.size();

    vector<int>prefix(n), suffix(n), answer(n);
    prefix[0] = nums[0];
    suffix[n-1] = 1;

    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] * nums[i];
    }

    for(int i = n-2; i >= 0; i--){
        suffix[i] = suffix[i+1] * nums[i+1];
    }

    answer[0] = suffix[0];

    for(int i = 1; i < n; i++) {
        answer[i] = suffix[i] * prefix[i-1];
    }

    return answer;
}

int main() {
    vector<int>nums = {1,2,3,4};
    vector<int>answer = productExceptSelf(nums);
    for(int ans : answer) {
        cout << ans <<" ";
    }

    return 0;
}