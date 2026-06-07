#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlace(vector<int>&stalls, int guess, int k) {
    int cow = 1;
    int pos = stalls[0];
    
    for(int i = 1; i < stalls.size(); i++) {
        if(guess <= stalls[i] - pos) {
            cow ++;
            pos = stalls[i];
        }
    }
    
    if(cow >= k) return true;
    return false;
}


int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls.back() - stalls.front();
    int ans = 0;
    
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(canPlace(stalls, mid, k)) {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}

int main() {
    vector<int> stalls = {1,2,4,8,9};
    int ans = aggressiveCows(stalls, 3);
    cout << ans;
    return 0;
}