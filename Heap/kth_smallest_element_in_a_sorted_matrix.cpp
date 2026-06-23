#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {

    priority_queue<int> pq;
    
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (pq.size() < k) {
                pq.push(matrix[i][j]);
            } else if (pq.top() > matrix[i][j]) {
                pq.pop();
                pq.push(matrix[i][j]);
            }
        }
    }

    return pq.top();
}

int main() {
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    int ans = kthSmallest(matrix,8);
    cout << ans;
    return 0;
}
