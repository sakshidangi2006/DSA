#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSum(vector<int>& arr) {
        int sum = arr[0];
        int maximum = arr[0];

        for(int i = 1; i < arr.size(); i++) {
            int v1 = arr[i];
            int v2 = sum + arr[i];
            sum = max(v1,v2);
            maximum = max(maximum, sum);
        }
        return maximum;
    }

    int minSum(vector<int>& arr) {
        int sum = arr[0];
        int minimum = arr[0];

        for(int i = 1; i < arr.size(); i++) {
            int v1 = arr[i];
            int v2 = sum + arr[i];
            sum = min(v1,v2);
            minimum = min(minimum, sum);
        }
        return minimum;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        
        int maxi = maxSum(nums);
        int mini = minSum(nums);
        return max(abs(maxi), abs(mini));
    }

int main() {
    vector<int> arr = {2,-5,1,-4,3,-2};
    int ans = maxAbsoluteSum(arr);
    cout << ans;
    return 0;
}