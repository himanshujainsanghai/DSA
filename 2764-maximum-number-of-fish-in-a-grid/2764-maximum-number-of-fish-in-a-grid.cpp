// class Solution {
// private:
//     vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//     int m, n;

// public:
//     int bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
//         queue<pair<int, int>> que;
//         que.push({i, j});
//         vis[i][j] = 1;
//         int sum = grid[i][j];

//         while (!que.empty()) {
//             auto [x, y] = que.front();
//             que.pop();

//             for (const auto& d : dir) {
//                 int row = x + d[0];
//                 int col = y + d[1];

//                 if (row >= 0 && row < m && col >= 0 && col < n &&
//                     grid[row][col] != 0 && !vis[row][col]) {
//                     que.push({row, col});
//                     vis[row][col] = 1;
//                     sum += grid[row][col];
//                 }
//             }
//         }

//         return sum;
//     }

//     int findMaxFish(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();

//         vector<vector<int>> vis(m, vector<int>(n, 0));
//         int maxi = 0;

//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[i][j] != 0 && !vis[i][j]) {
//                     maxi = max(maxi, bfs(i, j, grid, vis));
//                 }
//             }
//         }

//         return maxi;
//     }
// };
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0) return 0;
        int cur = grid[i][j];
        grid[i][j]=0;
        cur+=dfs(i+1, j, grid);
        cur+=dfs(i-1, j, grid);
        cur+=dfs(i, j+1, grid);
        cur+=dfs(i, j-1, grid);
        return cur;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]!=0){
                    ans = max(ans, dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};