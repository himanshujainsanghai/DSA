class Solution {
private:
    int func(int ind, int buy, vector<int>& p, int n, vector<vector<int>>& dp) {
        if (ind == n)
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit = 0;

        if (buy) {
            profit = max(-p[ind] + func(ind + 1, 0, p, n, dp),
                         func(ind + 1, 1, p, n, dp));
        } else {
            profit = max(func(ind + 1, 1, p, n, dp) + p[ind],
                         func(ind + 1, 0, p, n, dp));
        }
        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // return func(0 , 1 , p , n , dp);
        // dp[n][0] = dp[n][1] = 0;
        // vector<int> prev(2,0) , curr(2,0);
        // prev[0] = prev[1] = 0;
        // int profit = 0;
        // for (int ind = n - 1; ind >= 0; ind--) {
        //     for (int buy = 0; buy <= 1; buy++) {
        //         if (buy) {
        //             profit = max(-p[ind] + prev[0],
        //                          prev[1]);
        //         } else {
        //             profit = max(prev[1] + p[ind],
        //                         prev[0]);
        //         }
        //         curr[buy] = profit;
        //     }
        //     prev = curr;
        // }
        int aheadnotbuy, aheadbuy, currnotbuy, currbuy;
        aheadnotbuy = aheadbuy = 0;
        for (int ind = n - 1; ind >= 0; ind--) {
            currbuy = max(-p[ind] + aheadnotbuy, aheadbuy);

            currnotbuy = max(aheadbuy + p[ind], aheadnotbuy);
            aheadnotbuy = currnotbuy;
            aheadbuy = currbuy;
        }

        return aheadbuy;
    }
};