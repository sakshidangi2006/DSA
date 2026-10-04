#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int city, int n) {
    visited[city] = true;

    for(int i = 0; i < n; i++) {

        if(isConnected[city][i] == 1 && visited[i] == false) {
            dfs(isConnected, visited, i, n);
        }
    }
    return;
}

int findCircleNum(vector<vector<int>>& isConnected) {

    int n = isConnected.size();

    vector<bool>visited(n,false);

    int province = 0;

    for(int i = 0; i < n; i++) {

        if(visited[i] == false){
            
            dfs(isConnected, visited, i, n);
            province++;
        }  
    }
    return province;
}

int main() {
    vector<vector<int>>isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    int ans = findCircleNum(isConnected);
    cout << ans;
    return 0;
}
