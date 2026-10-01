#include <iostream>
#include <vector>
using namespace std;

int x[4] = {-1,1,0,0};
int y[4] = {0,0,-1,1};

bool valid(int i, int j, int m, int n, vector<vector<bool>>&visited) {
    if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == true) 
        return false;
    return true;
}

void dfs(vector<vector<char>>& grid, int i, int j, int m, int n,vector<vector<bool>>& visited) {

    visited[i][j] = true;

    for(int k = 0; k < 4; k++) {
        int row = i + x[k];
        int column = j + y[k];

        if(valid(row, column, m, n, visited) && grid[row][column] == '1') 
            dfs(grid, row, column, m, n, visited);
    }
    return; 

}
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    vector<vector<bool>>visited(m,vector<bool>(n,false));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            if(grid[i][j] == '1' && visited[i][j]== false){
                dfs(grid, i,j, m, n, visited);
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<char>>grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    int ans = numIslands(grid);
    cout << ans;
    return 0;
}
