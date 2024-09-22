class Solution {
private:
    int func(int ind, int buy, int cap, int n, vector<int>& p,
             vector<vector<vector<int>>>& dp) {
        if (cap == 0 || ind == n)
            return 0;
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        if (buy) {
            return dp[ind][buy][cap] =
                       max(-p[ind] + func(ind + 1, 0, cap, n, p, dp),
                           func(ind + 1, 1, cap, n, p, dp));
        }
        return dp[ind][buy][cap] =
                   max(p[ind] + func(ind + 1, 1, cap - 1, n, p, dp),
                       func(ind + 1, 0, cap, n, p, dp));
    }
    int trans(int ind , int t ,int n, vector<int>& p , vector<vector<int>>& dp){
        if(ind==n || t == 4) return 0;
        if( dp[ind][t] != -1) return dp[ind][t];
        if(t%2 == 0){
            return dp[ind][t] = max(-p[ind] + trans(ind+1 , t+1 , n ,p , dp) , trans(ind+1 , t , n, p , dp));
        }
        return dp[ind][t] = max(p[ind] + trans(ind+1 , t+1 , n ,p , dp) , trans(ind+1 , t , n ,p , dp));
    }
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        // return func(0 , 1 , 2 , n , p , dp);
        // vector<vector<int>> after(2, vector<int>(3, 0));
        // vector<vector<int>> curr(2, vector<int>(3, 0));
        // for (int ind = n - 1; ind >= 0; ind--) {
        //     for (int buy = 0; buy <= 1; buy++) {
        //         for (int cap = 1; cap <= 2; cap++) {
        //             if (buy) {
        //                 curr[buy][cap] = max(-p[ind] + after[0][cap],
        //                                         after[1][cap]);
        //             } else {
        //                 curr[buy][cap] =
        //                     max(p[ind] + after[1][cap - 1],
        //                         after[0][cap]);
        //             }
        //         }
        //     }
        //     after = curr;
        // }
        // return after[1][2];


        // DP[N X 4] SOLUTION:
        // vector<vector<int>> dp(n+1 , vector<int>(5 , 0));
        vector<int> ahead(5,0) , curr(5,0);
        // return trans(0 , 0, n ,p , dp);
        for(int ind =n-1 ; ind>=0 ; ind--){
            for(int t =0 ; t<=3 ; t++){
                if(t%2 == 0){
                curr[t] = max(-p[ind] + ahead[t+1] , ahead[t]);
                }
                else{
                curr[t] = max(p[ind] + ahead[t+1] , ahead[t]);

                }
            }
            ahead = curr;
        }
        return ahead[0];
        
    }
};