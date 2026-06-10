#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int m = nums1.size();
    int n = nums2.size();

    if (m > n)
        return findMedianSortedArrays(nums2, nums1);

    int low = 0, high = m;

    while (low <= high) {

        int mid = low + (high - low) / 2;   
        int mid2 = (m + n + 1) / 2 - mid;   

        int l1 = (mid == 0) ? INT_MIN : nums1[mid - 1];
        int r1 = (mid == m) ? INT_MAX : nums1[mid];

        int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
        int r2 = (mid2 == n) ? INT_MAX : nums2[mid2];

        if (l1 <= r2 && l2 <= r1) {

            if ((m + n) % 2 == 0) {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return 0.0;
}

int main()  {

    vector<int>nums1 = {1,2};
    vector<int>nums2 = {3,4};
    double ans = findMedianSortedArrays(nums1,nums2);
    cout<< ans;
    return 0;
}
