class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        // for (int i = 0; i < 4; i++) {
        //     int nrow = row + drow[i];
        //     int ncol = col + dcol[i];
        //     if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
        //         !vis[nrow][ncol] && grid[nrow][ncol] == 'O') {
        //         dfs(nrow, ncol, vis, grid);
        //     }
        // }
        stack<pair<int, int>> stk;
        stk.push({row, col});

        while (!stk.empty()) {
            auto [r, c] = stk.top();
            stk.pop();
            vis[r][c] = 1;

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 'O') {
                    stk.push({nrow, ncol});
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // treverse rows
        for (int j = 0; j < m; j++) {
            // first row
            if (grid[0][j] == 'O' && !vis[0][j]) {
                vis[0][j] = 1;
                dfs(0, j, vis, grid);
            }
            // lasr row
            if (grid[n - 1][j] == 'O' && !vis[n - 1][j]) {
                vis[n - 1][j] = 1;
                dfs(n - 1, j, vis, grid);
            }
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O' && !vis[i][0]) {
                vis[i][0] = 1;
                dfs(i, 0, vis, grid);
            }
            if (grid[i][m - 1] == 'O' && !vis[i][m - 1]) {
                vis[i][m - 1] = 1;
                dfs(i, m - 1, vis, grid);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O' && !vis[i][j]) {
                    grid[i][j] = 'X';
                }
            }
        }
    }
};