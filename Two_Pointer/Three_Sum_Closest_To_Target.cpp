#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int closestSum = nums[0]+nums[1]+nums[2];
    for(int i = 0; i < nums.size(); i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = nums.size()-1;
        while(j < k) {
            int sum = nums[i]+nums[j]+nums[k];
            if(abs(sum-target)< abs(closestSum-target)) {
                closestSum = sum;
            }
            if(sum == target) return sum;
            else if (sum < target ) j++;
            else k--;
        }
    }
    return closestSum;
}

int main() {
    vector<int> a = {-1,2,1,-4};
    int target = 1;
    int b = threeSumClosest(a,target);
    cout<<b;
    return 0;
}