#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) {
        int maxbest = nums[0];
        int minbest = nums[0];
        int ans = nums[0];
        int n = nums.size();
        for(int i =1; i<n; i++) {
            int v1 = maxbest * nums[i];
            int v2 = minbest * nums[i];
            int v3 = nums[i];
            maxbest = max(v1,max(v2,v3));
            minbest = min(v1,min(v2,v3));
            ans = max(ans, max(minbest,maxbest));
        }
        return ans;
    }

int main() {
    vector<int> a = {-2,3,-4};
    int ans = maxProduct(a);
    cout << ans;
    return 0;
}