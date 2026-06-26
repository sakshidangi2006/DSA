#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lastStoneWeight(vector<int>& stones) {

    priority_queue<int> pq;
    for (int s : stones) {
        pq.push(s);
    }

    while (pq.size() > 1) {
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();
        if (y != x) {
            pq.push(y - x);
        }
    }

    return pq.empty() ? 0 : pq.top();
}

int main() {
    vector<int> stones = {2,7,4,1,8,1};
    int ans = lastStoneWeight(stones);
    cout << ans;
    return 0;
}