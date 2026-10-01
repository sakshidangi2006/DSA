#include <iostream>
#include <vector>
using namespace std;
  
void dfs(vector<vector<int>>& adj, int node, vector<int>&ans, vector<bool>&visited) {
    
    ans.push_back(node);
    visited[node] = true;
    
    for(int i = 0; i < adj[node].size(); i++) {
        int neighbour = adj[node][i];
        
        if(visited[neighbour] == false) {
            dfs(adj, neighbour, ans, visited);
        }
    }
    return;
}
vector<int> dfs(vector<vector<int>>& adj) {
    
    int n = adj.size();
    vector<int>ans;
    vector<bool>visited(n,false);
    dfs(adj, 0, ans, visited);
    return ans;
}

int main() {
    vector<vector<int>> adj = {{1, 2},{0, 3, 4}, {0},{1},{1}};
    vector<int> result = dfs(adj);

    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}
