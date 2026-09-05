#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool uniformArray(vector<int>& nums1) {
int minOdd = INT_MAX;
bool hasEven = false;

for (int num : nums1) {
    if (num % 2 == 0) {
        hasEven = true;
    } else {
        minOdd = min(minOdd, num);
    }
}

if (minOdd == INT_MAX) {
    return true;
}

    if (!hasEven) {
        return true;
    }

    for (int num : nums1) {
        if (num % 2 == 0 && num <= minOdd) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> nums1 = {1,4,7};
    bool ans = uniformArray(nums1);
    cout << ans;
    return 0;
}