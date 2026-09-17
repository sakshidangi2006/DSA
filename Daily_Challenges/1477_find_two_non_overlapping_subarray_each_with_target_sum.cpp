#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSumOfLengths(vector<int>& arr, int target) {
    int n = arr.size();

    vector<int> best(n, INT_MAX);

    int low = 0;
    int sum = 0;
    int minLen = INT_MAX;
    int ans = INT_MAX;

    for (int high = 0; high < n; high++) {
        sum += arr[high];

        while (sum > target) {
            sum -= arr[low];
            low++;
        }

        if (sum == target) {
            int len = high - low + 1;

            if (low > 0 && best[low - 1] != INT_MAX) {
                ans = min(ans, len + best[low - 1]);
            }

            minLen = min(minLen, len);
        }

        best[high] = minLen;
    }

    return ans == INT_MAX ? -1 : ans;
}

int main() {
    vector<int> arr = {3,2,2,4,3};
    int target = 3;

    int ans = minSumOfLengths(arr,target);
    cout << ans;
    return 0;
}