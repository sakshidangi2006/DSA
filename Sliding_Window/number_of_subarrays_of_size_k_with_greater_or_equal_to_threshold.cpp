#include <bits/stdc++.h>
using namespace std;


int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int sum = 0;
    int count = 0;

    for (int i = 0; i < k; i++)
        sum += arr[i];

    if (sum >= k * threshold)
        count++;

    for (int i = k; i < arr.size(); i++) {
        sum += arr[i];
        sum -= arr[i - k];

        if (sum >= k * threshold)
            count++;
    }

    return count;
}

int main() {
    vector<int>arr = {2,2,2,2,5,5,5,8};
    int k = 2, threshold = 4;
    int ans = numOfSubarrays(arr,k,threshold);
    cout << ans;
    return 0;
}