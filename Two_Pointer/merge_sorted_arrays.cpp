#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int i = 0, j = 0;
    vector<int>a;

    while(i < m && j < n) {
        if(nums1[i] <= nums2[j]) {
            a.push_back(nums1[i]);
            i++;
        }
        else {
            a.push_back(nums2[j]);
            j++;
        }
    }

    while(i < m) {
        a.push_back(nums1[i]);
        i++;
    }
    while(j < n) {
        a.push_back(nums2[j]);
        j++;
    }
    for(int i= 0; i< m+n; i++) {
        nums1[i] = a[i];
    }
}

int main() {
    vector<int>nums1 = {1,2,3};
    vector<int>nums2 = {2,5};
    merge(nums1,3,nums2,2);
    return 0;
}