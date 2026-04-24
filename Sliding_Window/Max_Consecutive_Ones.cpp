#include <iostream>
#include <vector>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
        int maxLength = 0;
        int count = 0; 
        int low = 0; 

        for (int high = 0; high < nums.size(); high++) {
           if(nums[high] == 0) {
            count++;
           }

           while(count > k) {
            if (nums[low] == 0) {
                count--;
            }
            low++;

           }
            maxLength = max(maxLength, (high-low+1));
        }
        return maxLength;
    }

int main() {
    vector<int>a = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int b = longestOnes(a,k);
    cout << b;
    return 0;
}