#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool canAllocate(vector<int>& arr, int limit, int k) {
    int students = 1;
    int pages = 0;
    for (int book : arr) {
        if (book > limit)
            return false;
        if (pages + book > limit) {
            students++;
            pages = book;
        } else {
            pages += book;
        }
    }
    return students <= k;
}
int findPages(vector<int>& arr, int k) {
    if (k > arr.size()) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canAllocate(arr, mid, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {12,34,67,90};
    int ans = findPages(arr, 2);
    cout << ans;
    return 0;
}