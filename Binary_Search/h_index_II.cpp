#include <iostream>
#include <vector>
using namespace std;

int hIndex(vector<int>& citations) {

    int n = citations.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (citations[mid] >= n - mid) {
            high = mid - 1;   
        } else {
            low = mid + 1;    
        }
    }
    return n - low;
}

int main() {
    vector<int>citations = {0,1,3,5,8};
    int ans = hIndex(citations);
    cout << ans;
    return 0;
}