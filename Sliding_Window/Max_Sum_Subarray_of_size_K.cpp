#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        if (n < k) return -1;

        int sum = 0;

        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        int maxSum = sum;

        for (int i = k; i < n; i++) {
            sum += arr[i] - arr[i - k];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }

int main() {
    vector<int> a = {100, 200, 300, 400};
    int k = 2;
    int b = maxSubarraySum(a,k);
    cout << b;
    return 0;
}