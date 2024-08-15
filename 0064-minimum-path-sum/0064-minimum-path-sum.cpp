class Solution {
private:
    int func(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return grid[i][j];
        if (i < 0 || j < 0)
            return 1e9;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = grid[i][j] + func(i - 1, j, grid, dp);
        int left = grid[i][j] + func(i, j - 1, grid, dp);
        return dp[i][j] = min(up, left);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return func(m-1 , n-1 , grid , dp);

        // tabulation
        // dp[0][0] = grid[0][0];
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (i == 0 && j == 0)
        //             continue;
        //         int up = 1e9, left = 1e9;
        //         if (i > 0)
        //             up = grid[i][j] + dp[i - 1][j];
        //         if (j > 0)
        //             left = grid[i][j] + dp[i][j - 1];
        //         dp[i][j] = min(up, left);
        //     }
        // }
        // return dp[m - 1][n - 1];

        // space optimization
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    curr[j] = grid[0][0];
                } else {
                    int up = grid[i][j];
                    if (i > 0)
                        up += prev[j];
                    else
                        up += 1e9;

                    int left = grid[i][j];
                    if (j > 0)
                        left += curr[j - 1];
                    else
                        left += 1e9;
                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};