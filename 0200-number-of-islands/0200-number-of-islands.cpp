class Solution {
private:
    
    void bfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // traverse through the eight directions to find the neightbours
            // for (int delrow = -1; delrow <= 1; delrow++) {
            //     for (int delcol = -1; delcol <= 1; delcol++) {
            //         int nrow = r + delrow;
            //         int ncol = c + delcol;

            //         // check validity
            //         if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            //             grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
            //             vis[nrow][ncol] = 1;
            //             q.push({nrow, ncol});
            //         }
            //     }
            // }

            // traverse 4 directionally
            int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (int i=0 ; i<4 ; i++) {
                int nrow = r + directions[i][0];
                int ncol = c + directions[i][1];

                // check validity
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};


// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == '1') {
//                     islands++;
//                     grid[i][j] = '0';
//                     queue<pair<int, int>> todo;
//                     todo.push({i, j});
//                     while (!todo.empty()) {
//                         pair<int, int> p = todo.front();
//                         todo.pop();
//                         for (int k = 0; k < 4; k++) {
//                             int r = p.first + offsets[k], c = p.second + offsets[k + 1];
//                             if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
//                                 grid[r][c] = '0';
//                                 todo.push({r, c});
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return islands;
//     }
// };