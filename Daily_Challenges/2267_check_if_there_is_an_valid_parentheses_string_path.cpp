#include <iostream>
#include <vector>
using namespace std;

bool hasValidPath(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int maxBalance = m + n;

    if ((m + n - 1) % 2 == 1)
        return false;

    if (grid[0][0] == ')')
        return false;

    vector<vector<vector<bool>>> dp(
        m,
        vector<vector<bool>>(
            n,
            vector<bool>(maxBalance + 1, false)
        )
    );

    dp[0][0][1] = true;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (i == 0 && j == 0)
                continue;

            for (int balance = 0;
                 balance <= maxBalance;
                 balance++) {

                if (i > 0 && dp[i - 1][j][balance]) {

                    int newBalance;

                    if (grid[i][j] == '(')
                        newBalance = balance + 1;
                    else
                        newBalance = balance - 1;

                    if (newBalance >= 0) {
                        dp[i][j][newBalance] = true;
                    }
                }

                if (j > 0 && dp[i][j - 1][balance]) {

                    int newBalance;

                    if (grid[i][j] == '(')
                        newBalance = balance + 1;
                    else
                        newBalance = balance - 1;

                    if (newBalance >= 0) {
                        dp[i][j][newBalance] = true;
                    }
                }
            }
        }
    }

    return dp[m - 1][n - 1][0];
}

int main() {
    vector<vector<char>> grid = {
    {'(', '(', '('},
    {')', '(', ')'},
    {'(', '(', ')'},
    {'(', '(', ')'}
    };

    bool ans = hasValidPath(grid);
    cout << ans;
    return 0;
}

