class Solution {
    private:
    int func(int ind , int t ,vector<int>& coins , vector<vector<int>>& dp){
        if(ind==0){
            if(t%coins[0] == 0) return t/coins[0];
            return 1e9;
        }
        if(dp[ind][t] != -1) return dp[ind][t];
        int notTake = func(ind-1 ,t , coins , dp );
        int take = 1e9;
        if(coins[ind] <= t){
            take = 1 + func(ind , t-coins[ind] , coins , dp);
    
        }
        return dp[ind][t] = min(take , notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // int n = coins.size();
        // vector<vector<int>> dp(n , vector<int>(amount+1 , -1));
        // int result = func(n-1 , amount , coins , dp);



        // tabulation
        // vector<vector<int>> dp(n , vector<int>(amount+1 , 0));
        // vector<int> prev(amount+1 , 0) , curr(amount+1 , 0); 
        // for(int t = 0 ; t<=amount ;t++){
        //     if(t%coins[0] == 0) prev[t] = t/coins[0];
        //     else prev[t] = 1e9; 
        // }
        // for(int ind = 1 ; ind<n ; ind++){
        //     for(int t = 0 ; t<=amount ; t++){
        //         int notTake = prev[t];
        //         int take = 1e9;
        //         if(coins[ind] <= t){
        //             take = 1 + curr[ t-coins[ind]];
            
        //         }
        //         curr[t] = min(take , notTake);
        //     }
        //     prev = curr;
        // }
        // int result = prev[amount];
        // if(result == 1e9) return -1;
        // return result;


        int n = coins.size();
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = coins[i]; j<= amount ; j++){
                dp[j] = min(dp[j], dp[j-coins[i]] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];

    }
};