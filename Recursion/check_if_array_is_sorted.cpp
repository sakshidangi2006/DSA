#include <iostream>
#include <vector>
using namespace std;

bool sorted(vector<int>& arr, int index) {
    if (index == arr.size() - 1)
        return true;

    if (arr[index] > arr[index + 1])
        return false;

    return sorted(arr, index + 1);
}

bool isSorted(vector<int>& arr) {
    if (arr.size() <= 1)
        return true;

    return sorted(arr, 0);
}

int main() {
    vector<int> arr = {90, 80, 100, 70, 40, 30};
    bool ans = isSorted(arr);
    cout << ans;
    return 0;
}