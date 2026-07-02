#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
using namespace std;


int maximumSafenessFactor(vector<vector<int>>& grid) {

    int n = grid.size();

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    queue<pair<int,int>> q;

    // Multi-source BFS initialization
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1)
            {
                dist[i][j]=0;
                q.push({i,j});
            }
        }
    }

    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};

    while(!q.empty())
    {
        pair<int,int> current = q.front();
        int r = current.first;
        int c = current.second;
        q.pop();

        for(int k=0;k<4;k++)
        {
            int nr=r+dr[k];
            int nc=c+dc[k];

            if(nr>=0 && nr<n && nc>=0 && nc<n &&
               dist[nr][nc]==INT_MAX)
            {
                dist[nr][nc]=dist[r][c]+1;
                q.push({nr,nc});
            }
        }
    }

    // best[r][c] = maximum safeness found so far
    vector<vector<int>> best(n, vector<int>(n,-1));

    priority_queue<vector<int>> pq;

    pq.push({dist[0][0],0,0});

    best[0][0]=dist[0][0];

    while(!pq.empty())
    {
        auto curr=pq.top();
        pq.pop();

        int safe=curr[0];
        int r=curr[1];
        int c=curr[2];

        if(r==n-1 && c==n-1)
            return safe;

        if(safe<best[r][c])
            continue;

        for(int k=0;k<4;k++)
        {
            int nr=r+dr[k];
            int nc=c+dc[k];

            if(nr>=0 && nr<n && nc>=0 && nc<n)
            {
                int newSafe=min(safe,dist[nr][nc]);

                if(newSafe>best[nr][nc])
                {
                    best[nr][nc]=newSafe;
                    pq.push({newSafe,nr,nc});
                }
            }
        }
    }

    return 0;
}

int main() {
    vector<vector<int>> grid = {{0,0,1},{0,0,0},{0,0,0}};
    int ans = maximumSafenessFactor(grid);
    cout << ans;
    return 0;
}