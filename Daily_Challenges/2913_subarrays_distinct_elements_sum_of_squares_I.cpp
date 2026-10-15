#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


int sumCounts(vector<int>& nums) {
    int sum = 0;

    for(int i = 0; i < nums.size(); i++) {

        unordered_set<int>st;
        for(int j = i; j < nums.size(); j++) {
            st.insert(nums[j]);
            int distinct = st.size();

            sum += distinct * distinct;
        }
        
    }
    return sum;

}

int main() {
    vector<int>nums = {1,2,1};
    int ans = sumCounts(nums);
    cout << ans;
    return 0;
}