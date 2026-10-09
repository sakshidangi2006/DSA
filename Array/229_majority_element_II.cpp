#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int majEle1 = 0, majEle2 = 0;
    int count1 = 0, count2 = 0;
    vector<int>ans;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == majEle1 && count1 > 0) {
            count1++;
        }
        else if(nums[i] == majEle2 && count2 > 0) {
            count2++;
        }
        else if(count1 == 0) {
            majEle1 = nums[i];
            count1++;
        }
        else if(count2 == 0){
            majEle2 = nums[i];
            count2++;
        }
        else {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == majEle1) count1++;
        else if(nums[i] == majEle2) count2++;
        }

    if(count1 > nums.size()/3) {
            ans.push_back(majEle1);
    }

    if(count2 > nums.size()/3) {
        ans.push_back(majEle2);
    }

    return ans;
}

int main() {
    vector<int>nums = {3,2,3};
    vector<int>ans = majorityElement(nums);
    for(int a : ans) {
        cout << a <<" ";
    }
    return 0;
}
