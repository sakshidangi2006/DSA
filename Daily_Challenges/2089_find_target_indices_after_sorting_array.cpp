#include <iostream>
#include <vector>
using namespace std;

vector<int> targetIndices(vector<int>& nums, int target) {
    int small = 0;
    int equal = 0;
    vector<int>ans;

    for(int num : nums) {
        if(num < target) small++;

        else if(num == target) equal++;
    }

    for(int i = small; i < small + equal; i++) {
        ans.push_back(i);
    }
    return ans;
}

int main() {
    vector<int>nums = {1,2,5,2,3};
    int target = 2;
    vector<int>ans = targetIndices(nums, target);

    for(int num : ans) {
        cout << num <<" ";
    }
    return 0;
}