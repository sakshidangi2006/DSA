#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i = 0;

    for(int j = 0; j < nums.size(); j++) {
        if(i < 2 || nums[j] != nums[i-2]){
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int ans = removeDuplicates(nums);
    cout << ans;
    return 0;
}