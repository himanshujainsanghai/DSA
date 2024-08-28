class Solution {
private:
    int func(int ind, int t, vector<int>& coins, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (t % coins[0] == 0)
                return 1;
            return 0;
        }
        if (dp[ind][t] != -1)
            return dp[ind][t];
        int notTake = func(ind - 1, t, coins, dp);
        int take = 0;
        if (coins[ind] <= t) {
            take = func(ind, t - coins[ind], coins, dp);
        }
        return dp[ind][t] = take + notTake;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n , vector<int>(amount+1 , -1));
        // int result = func(n-1 , amount , coins , dp);
        // return result;

        // vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        vector<int> prev(amount+1 , 0) , curr(amount+1 ,0);
        for (int t = 0; t <= amount; t++)
            prev[t] = (t % coins[0] == 0);
        for (int ind = 1; ind < n; ind++) {
            for (int t = 0; t <= amount; t++) {
                int notTake = prev[t];
                int take = 0;
                if (coins[ind] <= t) {
                    take = curr[t - coins[ind]];
                }
                curr[t] = take + notTake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};