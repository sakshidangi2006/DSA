#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<int> &arr, int k) {
    priority_queue<int>pq;
    
    for(int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }
    
    for(int i = k; i < arr.size(); i++) {
        if(arr[i] >= pq.top())continue;
        pq.pop();
        pq.push(arr[i]);
    }
    return pq.top();
}

int main() {
    vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int ans = kthSmallest(arr,4);
    cout << ans;
    return 0;
}