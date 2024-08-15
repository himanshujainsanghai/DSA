class Solution {
private:
    int func(int i, int j, vector<vector<int>>& tri, int n,
             vector<vector<int>>& dp) {
        if (i == n - 1)
            return tri[i][j]; // Base case: last row
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = tri[i][j] + func(i + 1, j, tri, n, dp);
        int daig = tri[i][j] + func(i + 1, j + 1, tri, n, dp);
        return dp[i][j] = min(down, daig);
    }

public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return func(0, 0, tri, n , dp);

        // tabulation
        // for (int j = 0; j < n; j++) {
        //     dp[n - 1][j] = tri[n - 1][j];
        // }
        // for (int i = n - 2; i >= 0; i--) {
        //     for (int j = i; j >= 0; j--) {
        //         int down = tri[i][j] + dp[i+1][j];
        //         int daig = tri[i][j] + dp[i+1][j+1];
        //         dp[i][j] = min(down, daig);
        //     }
        // }
        // return dp[0][0];

        // space optimizations
        vector<int> front(n , 0) , curr(n ,0);
        for (int j = 0; j < n; j++) {
            front[j] = tri[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = tri[i][j] + front[j];
                int daig = tri[i][j] + front[j+1];
                curr[j] = min(down, daig);
            }
            front = curr;
        }
        return front[0];
    }
};
