#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minMoves2(vector<int>& nums) {
        
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int first = 0;
    int last = n-1;
    int minVal = nums[first];
    int maxVal = nums[last];

    int diff = 0;
    int sum = 0;
    int mid = (nums[first] + nums[last])/2;

    while(first < last) {
        diff = nums[last] - nums[first];
        sum += diff;
        first++;
        last--;

        if(sum == mid) break;
    }

    return sum;
}

int main() {
    vector<int>nums = {1,10,2,9};
    int ans = minMoves2(nums);
    cout << ans;
    return 0;
}
