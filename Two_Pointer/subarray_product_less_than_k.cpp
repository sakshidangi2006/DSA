#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
    int count = 0;
    if (k <= 1) return 0;
        
    for(int i = 0; i < nums.size(); i++) {
        int product = 1;

            
        for(int j = i; j < nums.size(); j++) {
            product *= nums[j];

            if(product < k) {
                count ++;
            }
            else break;
        }
    }
    return count;
    }


    int main() {
    vector<int> a = {10,5,2,6};
    int k = 100;
    int b = numSubarrayProductLessThanK(a,k );
    cout<<b;
    return 0;
}