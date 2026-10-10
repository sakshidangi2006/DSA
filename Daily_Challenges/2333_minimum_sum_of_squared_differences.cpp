#include <iostream>
#include <vector>
using namespace std;


long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

    int n = nums1.size();
    vector<int>countDiff(100001,0);

    for(int i = 0; i < n; i++) {
        int d = abs(nums1[i]-nums2[i]);
        countDiff[d]++;
    }
    
    int k = k1+k2;
    for(int currDiff = 1e+5; currDiff > 0 && k > 0; currDiff--) {
        int countOps = min(countDiff[currDiff],k);
        countDiff[currDiff] -= countOps;
        countDiff[currDiff-1] += countOps;
        k -= countOps;
    }

    long long result = 0;

    for(long long d = 1; d <= 1e+5; d++){
        result += (countDiff[d] * d*d);
    }
    return result;
}

int main() {
    vector<int>nums1 = {1,4,10,12};
    vector<int>nums2 = {5,8,6,9};
    int k1 = 1;
    int k2 = 1;

    long long ans = minSumSquareDiff(nums1, nums2, k1, k2);
    cout << ans;
    return 0;
}