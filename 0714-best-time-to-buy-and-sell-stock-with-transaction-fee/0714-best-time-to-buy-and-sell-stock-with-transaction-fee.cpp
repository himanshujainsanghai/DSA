class Solution {
    private:
        int func(int ind, int buy, vector<int>& p, int n, vector<vector<int>>&  dp, int fee) {
        if (ind == n) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];

        if (buy == 1) {
            return dp[ind][buy] = max(-p[ind] + func(ind + 1, 0, p, n, dp ,fee), func(ind + 1, 1, p, n, dp ,fee));
        }
        return dp[ind][buy] = max(func(ind + 1, 1, p, n, dp ,fee) + p[ind] - fee,func(ind + 1, 0, p, n, dp ,fee));
    }
public:
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();
        // vector<vector<int>> dp(n , vector<int>(2 ,-1));
        // return func(0 , 1 , p , n , dp , fee);
        int aheadnotbuy, aheadbuy, currnotbuy, currbuy;
        aheadnotbuy = aheadbuy = 0;
        for (int ind = n - 1; ind >= 0; ind--) {
            currbuy = max(-p[ind] + aheadnotbuy, aheadbuy);

            currnotbuy = max(aheadbuy + p[ind] - fee, aheadnotbuy);
            aheadnotbuy = currnotbuy;
            aheadbuy = currbuy;
        }

        return aheadbuy;
    }
};