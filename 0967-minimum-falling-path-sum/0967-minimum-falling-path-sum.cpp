class Solution {
    private:
    int func(int i , int j , int n ,vector<vector<int>>& mat,vector<vector<int>>& dp){
        if(j<0 || j>=n) return 1e9;
        if(i == 0) return mat[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        int s = mat[i][j] + func(i-1 , j , n , mat , dp);
        int ld = mat[i][j] + func(i-1 , j-1 , n , mat , dp);
        int rd = mat[i][j] + func(i-1 , j+1 , n , mat , dp);
        return dp[i][j] =  min(s , min(ld , rd));
    }

public:
    int minFallingPathSum(vector<vector<int>>& mat) {

        int n = mat.size();
        // int mini = 1e9;
        // vector<vector<int>> dp(n , vector<int>(n , -1));
        // for(int i = 0 ; i<n ; i++){
        //     mini = min(mini , func(n-1 , i , n , mat , dp));
        // }
        // return mini;

        // tabulation
        // for(int j = 0 ; j<n ; j++){
        //     dp[0][j] = mat[0][j];
        // }
        // for(int i = 1 ; i<n ;i++){
        //     for(int j = 0 ; j<n ; j++){
        //         int s = mat[i][j] + dp[i-1][j];
        //         int ld = 1e9;
        //         if(j>0) ld = mat[i][j] + dp[i-1][j-1];
        //         int rd = 1e9;
        //         if(j<n-1) rd = mat[i][j] + dp[i-1][j+1];
        //         dp[i][j] = min( s, min( ld , rd));
        //     }
        // }

        // int mini = dp[n-1][0];
        // for(int i = 1; i<n ; i++){
        //     mini = min(mini , dp[n-1][i]);
        // }
        // return mini;

        // space optimization 
        vector<int> prev(n , 0);
        for(int j = 0 ; j<n ; j++){
            prev[j] = mat[0][j];
        }
        for(int i = 1 ; i<n ;i++){
            vector<int> curr(n ,0);
            for(int j = 0 ; j<n ; j++){
                int s = mat[i][j] + prev[j];
                int ld = 1e9;
                if(j>0) ld = mat[i][j] + prev[j-1];
                int rd = 1e9;
                if(j<n-1) rd = mat[i][j] + prev[j+1];
                curr[j] = min( s, min( ld , rd));
            }
            prev = curr;
        }

        int mini = prev[0];
        for(int i = 1; i<n ; i++){
            mini = min(mini , prev[i]);
        }
        return mini;
        
        
    }
};