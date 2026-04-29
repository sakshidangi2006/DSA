#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findMaxLength(vector<int>& nums) {

    int sum = 0;
    int ans = 0;

    unordered_map<int,int>mpp;
    mpp[0] = -1;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] ==0 ) sum -= 1;
        else sum += 1;

        if(mpp.find(sum) != mpp.end()){
            ans = max(ans, i - mpp[sum]);
        }
        else {
            mpp[sum] = i;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {0,1,1,1,1,1,0,0,0};
    int ans = findMaxLength(nums);
    cout << ans;
    return 0;
}
