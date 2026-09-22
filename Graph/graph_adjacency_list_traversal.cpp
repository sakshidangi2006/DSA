#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
vector<vector<int>>adj(V);

for(int i = 0; i < edges.size(); i++) {
    int src = edges[i].first;
    int dest = edges[i].second;
    
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}
return adj;
    
}

int main() {
    int V = 5;
    vector<pair<int,int>>edges = {{0,1}, {0,4}, {4,1}, {4,3}, {1,3}, {1,2}, {3,2}};
    vector<vector<int>>adj = printGraph(V, edges);

    for(int i = 0; i < adj.size(); i++) {
        cout <<"[";
        for(int j = 0; j < adj[i].size(); j++) {
            cout<<adj[i][j] <<" ";
        }
        cout <<"]\n";
    }
    return 0;
}