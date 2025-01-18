class Solution {
private:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis,
            int cost, int n, int m) {
        if (i == n - 1 && j == m - 1) {
            return cost;
        }
        vis[i][j] = 1;
        int minCost = INT_MAX;
        for (int k = 0; k < 4; k++) {
            int row = i + dir[k][0];
            int col = j + dir[k][1];

            if (row < n && row >= 0 && col < m && col >= 0 && !vis[row][col]) {
                int dirCost = cost + ((grid[i][j] - 1 == k) ? 0 : 1);
                minCost = min(minCost, dfs(row, col, grid, vis, dirCost, n, m));
            }
        }

        vis[i][j] = 0;

        return minCost;
    }

public:
    int minCost(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Brute Force Apporoach using DFS and Backtracking
        // vector<vector<int>> vis(n , vector<int>(m ,0));
        // return dfs(0 , 0 , grid , vis , 0 , n , m);

        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        ans[0][0] = 0;
        // vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<vector<int>,
                       vector<vector<int>>,
                       greater<vector<int>>>
            pq;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int cost = it[0];
            int i = it[1];
            int j = it[2];


            // vis[i][j] = 1;

            int minCost = INT_MAX;
            for (int k = 0; k < 4; k++) {
                int row = i + dir[k][0];
                int col = j + dir[k][1];

                if (row < n && row >= 0 && col < m && col >= 0 ) {
                    int dirCost = cost + ((grid[i][j] - 1 == k) ? 0 : 1);
                    if(dirCost < ans[row][col]){
                        ans[row][col] = dirCost;
                        pq.push({dirCost , row , col});
                    }
                }
            }
        }


        return ans[n-1][m-1];
    }
};