class Solution {
private:
    int func(int i, int j, int move, int m, int n, vector<vector<int>>& grid,
             vector<vector<int>>& dp) {
        if (j == n - 1) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int maxmove = 0;
        for (int c = -1; c < 2; c++) {
            if (i + c >= 0 && i + c < m && j + 1 >= 0 && j + 1 < n &&
                grid[i + c][j + 1] > grid[i][j]) {
                maxmove =
                    max(maxmove, 1 + func(i + c, j + 1, 0, m, n, grid, dp));
            }
        }

        return dp[i][j] = maxmove;
    }

public:
    int maxMoves(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false); // Disable synchronization with C I/O
        cin.tie(NULL);               // Untie cin from cout
        cout.tie(NULL);
        int m = grid.size();
        int n = grid[0].size();

        int moves = 0;
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // for (int ind = 0; ind < m; ind++) {
        //     moves = max(moves, func(ind, 0, 0, m, n, grid, dp));
        //     // cout << moves << endl;
        // }

        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        vector<int> prev(m+1 , 0) , curr(m+1 , 0);
        for (int j = n - 2; j >= 0; j--) {
            for (int i = 0; i < m; i++) {
                int maxMove = 0;

                // Check the three possible cells in the next column
                for (int c = -1; c <= 1; c++) {
                    if (i + c >= 0 && i + c < m &&
                        grid[i + c][j + 1] > grid[i][j]) {
                        maxMove = max(maxMove, 1 + prev[i + c]);
                    }
                }

                curr[i] = maxMove;
            }
            prev = curr;
        }
        for (int i = 0; i < m; i++) {
            moves = max(moves, prev[i]);
        }

        return moves;
    }
};