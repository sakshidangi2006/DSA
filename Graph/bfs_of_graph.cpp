#include <iostream>
#include <queue>
#include <vector>
using namespace std;


void bfs(vector<vector<int>>&adj, int node, vector<int>& ans, vector<bool>visited){
    queue<int>q;
    q.push(node);
    visited[node] = true;
    
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        ans.push_back(current);
        
        for(int neighbour : adj[current]) {
            if(visited[neighbour] == false){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
vector<int> bfs(vector<vector<int>> &adj) {
    vector<int> ans;
    vector<bool>visited(adj.size(),false);
    bfs(adj,0,ans,visited);
    return ans;
}

int main() {
    vector<vector<int>>adj = {{2,3,1},{0},{0,4},{0},{2}};
    vector<int> result = bfs(adj);

    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}