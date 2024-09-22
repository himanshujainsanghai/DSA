class Solution {
    private:
        int func(int ind, int buy, vector<int>& p, int n, vector<vector<int>>& dp) {
        if (ind >= n) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];

        if (buy == 1) {
            return dp[ind][buy] = max(-p[ind] + func(ind + 1, 0, p, n, dp), func(ind + 1, 1, p, n, dp));
        }
        return dp[ind][buy] = max(func(ind + 2, 1, p, n, dp) + p[ind],func(ind + 1, 0, p, n, dp));
    }
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n+1 , vector<int>(2 , -1));
        return func(0 , 1 ,p , n , dp);
        
    }
};