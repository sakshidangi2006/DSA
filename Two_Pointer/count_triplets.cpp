#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countTriplets(vector<int>& nums, int sum) {
    sort(nums.begin(),nums.end());
    int count = 0;
    
    for(int i = 0; i < nums.size(); i++) {
        
        int j = i+1;
        int k = nums.size()-1;
        while(j < k) {
            int Closestsum = nums[i]+nums[j]+nums[k];
            if(Closestsum < sum) {
                count += (k-j);
                j++;
            }
            else k--;
        }
    }
    return count;
}

int main() {
    vector<int> a = {-2,-1,0,1,2,3};
    int sum = 2;
    int b = countTriplets(a, sum);
    cout<<b;
    return 0;
}