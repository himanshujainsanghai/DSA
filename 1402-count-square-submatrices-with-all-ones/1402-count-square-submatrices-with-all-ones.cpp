class Solution {
private:
    // int m;
    // int n;

    // int solve(int i, int j, vector<vector<int>>& grid,
    //           vector<vector<int>>& dp) {
    //     if (i >= m || j >= n) {
    //         return 0;
    //     }
    //     if (grid[i][j] != 1) {
    //         return 0;
    //     }
    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
    //     int hori = solve(i, j + 1, grid, dp);
    //     int daig = solve(i + 1, j + 1, grid, dp);
    //     int below = solve(i + 1, j, grid, dp);

    //     return dp[i][j] = 1 + min({hori, daig, below});
    // }

public:
    int countSquares(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);


        int m = grid.size();
        int n = grid[0].size();

        int result = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //   for(int i=0 ; i<m ; i++){
        //     for(int j=0 ; j<n ; j++){
        //         if(grid[i][j] == 1){
        //             result += solve(i ,j , grid , dp);
        //         }
        //     }
        //   }

        // TABULATION

        for(int i=0 ; i<m ; i++){
            dp[i][0] = grid[i][0];
            result += dp[i][0];
        }

        for(int j=1 ; j<n ; j++){
            dp[0][j] = grid[0][j];
            result += dp[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] =
                        1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                }

                result += dp[i][j];
            }
        }

        return result;
    }
};