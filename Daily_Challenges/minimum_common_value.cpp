#include <iostream>
#include <vector>
using namespace std;

int getCommon(vector<int>& nums1, vector<int>& nums2) {

    int m = nums1.size();
    int n = nums2.size();
    int i = 0, j= 0;
    while(i < m && j < n) {
        if(nums1[i] < nums2[j]) i++;
        else if (nums1[i] > nums2[j]) j++;
        else {
            return nums1[i];
        }
    }
    return -1;
}

int main() {
    vector<int>nums1 = {1,2,3};
    vector<int>nums2 = {2,3};
    int ans = getCommon(nums1, nums2);
    cout << ans;
    return 0; 
}
