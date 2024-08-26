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
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1));
        int result = func(n-1 , amount , coins , dp);
        return result;
    }
};